#include <iostream>
#include <string>
#include <stdexcept>
#include <boost/random.hpp>
using namespace std;

class DivideByZeroException  {
    public:
        const char* what() const noexcept {
            return "Division by zero is not allowed.";
        }
};

double divide(int a, int b) {
    if (b == 0) {
        throw DivideByZeroException();
    }
    return static_cast<double>(a) / b;
}

int randomInt(int min, int max) {
    if (min > max) {
        throw std::invalid_argument("最小值不能大于最大值");
    }
    
    static boost::random::mt19937 gen;  // 默认构造，无需种子
    boost::random::uniform_int_distribution<> dist(min, max);
    
    return dist(gen);
}


int main1() {
    int x = 10, y = 1;
    
    try {
        // 尝试执行可能抛异常的函数
        double result = divide(x, y); 
        cout << "结果：" << result << endl; // 若没异常，执行这里
    } catch (const DivideByZeroException& e) { 
        cout << "捕获到异常：" << e.what() << endl; // 处理除0异常
    }
    catch (...) { // 匹配所有未被前面catch处理的异常（兜底）
        cout << "捕获到未知异常" << endl;
    }
    return 0;
}

void test1() {
    try {
        throw 10;  // 抛出int类型
    }
    catch (double d) {  // 不匹配！int无法隐式转为double
        cout << "不会执行这里";
    }
    catch (int i) {     // 精确匹配
        cout << "捕获int: " << i;  // 执行这里
    }
}

class MyException {
public:
    int count; // 静态成员变量
    MyException() { setCount(); cout << "构造" <<count << endl; }
    ~MyException() { cout << "析构" << count << endl; }
    MyException(const MyException&) { setCount(); cout << "拷贝构造" << count << endl; }
    void setCount() {
        count = randomInt(1, 10000); // 调用可能抛异常的函数
    }
};

void test2() {
    try {
        throw MyException();  // 构造临时对象（第1次构造）
    }                       // 临时对象拷贝到catch参数（第2次构造）
    catch (MyException e) { // 处理异常
        cout << "捕获异常，count = " << e.count << endl; // 处理异常
        // 在这里可以使用e对象
    }                       // catch块结束，e析构（第1次析构）
    catch (...) {          // 匹配所有未被前面catch处理的异常（兜底）
        cout << "捕获到未知异常" << endl;
    }                       // catch块结束，e析构（第1次析构）
                            // 临时对象析构（第2次析构）
}


int main() {
    test2();
    return 0;
}