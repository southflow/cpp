#include <iostream>
using namespace std;

class A {
    public:
        int x = 1;
        void setX(int y) {
            x = y;
        }
        int getX() const {
            return x;
        }
};

void printA(const A& a) {
    // a.x++;
    cout << a.x << endl;
}

int main() {
    // 只读的
    const int MAX_SPEED = 300;
    // MAX_SPEED = 30;
    int x = 10;
    int y = 20;
    int* const ptr = &x;
    *ptr = 20;    // 正确：可以修改对象
    // ptr = &y;  // 错误：不能修改指针的值
}