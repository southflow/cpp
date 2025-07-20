#include <iostream>
#include <string>
using namespace std;

class MyData {
public:
    string info;
    MyData(const string& str) : info(str) {
        cout << "MyData构造函数: " << info << endl;
    }
    ~MyData() {
        cout << "MyData析构函数: " << info << endl;
    }
};

void func(int &x) {
    // 这里的x是一个左值引用，可以修改原始变量
    x = 20;  // 修改x的值
    cout << "func&中的x: " << x << endl;
}

void func(int &&x) {
    // 这里的x是一个右值引用，不能修改原始变量
    cout << "func&&中的x: " << x << endl;
    // x = 30;  // 这行代码会报错，因为x是右值引用
}

void func(MyData &&data) {
    // 这里的data是一个右值引用，可以直接使用
    data.info += " (右值引用)";
    cout << "func(MyData&&)中的data: " << data.info << endl;
}
void func(MyData &data) {
    // 这里的data是一个左值引用，可以修改原始对象
    data.info += " (左值引用)";
    cout << "func(MyData&)中的data: " << data.info << endl;
}

class MyString {
public:
    char* data;
    size_t size;
    // 移动构造函数
    MyString(MyString&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;  // "窃取"资源
    }
};

void process(int& x) { cout << "左值版本" << endl; }
void process(int&& x) { cout << "右值版本" << endl; }

template<typename T>
void wrapper(T&& arg) {
    process(std::forward<T>(arg)); // 无论传入的是左值还是右值，arg作为命名变量都是左值
}



int main() {
    int x = 10;
    int& lref = x;  // lref是x的左值引用

    func(x);
    func(lref);

    // int& lref1 = 100;

    func(100);  // 传递一个左值引用

    MyData data("临时数据1");
    func(MyData("临时数据2"));  // 传递一个右值引用
    func(data);  // 传递一个左值引用
    func(std::move(data));  // 使用std::move将data转换为右值引用
    func(std::move(MyData("临时数据3"))); 
    // cout << data.info << endl;  // 输出data的info，注意data可能已经被移动
    process(x);  // 调用左值版本
    process(100);  // 调用右值版本
    wrapper(x);  // 调用左值版本
    wrapper(100);  // 调用右值版本
}