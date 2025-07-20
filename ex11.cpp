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
    MyData *heapData = new MyData("堆数据");
    try {
        throw 1;
    }catch (...) {
        throw heapData;  // 重新抛出异常
    }
}

int main() {
    try {
        func();  // 调用可能抛异常的函数
    } catch (MyData *p) {  // 捕获int类型异常
        cout << "捕获到异常: " << p->info << endl;
        delete p;  // 释放堆内存
    } catch (...) {  // 捕获所有其他类型异常
        cout << "捕获到未知异常" << endl;
    }
    
    cout << "程序继续执行..." << endl;  // 异常处理后继续执行
    return 0;
}