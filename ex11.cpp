#include <iostream>
#include <string>
using namespace std;

struct MyData {
    string info;
    MyData(const string& str) : info(str) {
        cout << "MyData构造函数: " << info << endl;
    }
    ~MyData() {
        cout << "MyData析构函数: " << info << endl;
    }
};

void func(){
    MyData data("临时数据");
    throw 1;
}

int main() {
    try {
        func();  // 调用可能抛异常的函数
    } catch (int e) {  // 捕获int类型异常
        cout << "捕获到异常: " << e << endl;
    } catch (...) {  // 捕获所有其他类型异常
        cout << "捕获到未知异常" << endl;
    }
    
    cout << "程序继续执行..." << endl;  // 异常处理后继续执行
    return 0;
}