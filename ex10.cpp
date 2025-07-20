
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// 当数组作为函数参数传递时，编译器会自动将其转换为指向数组首元素的指针，而非传递整个数组的副本。
void func(int arr[], int size) { 
    cout << "数组长度: " << size << endl; // 输出传入的数组长度
    // 实际等效于 void func(int* arr)
    cout << sizeof(arr) << endl; // 输出指针大小（如 8 字节），而非数组长度
}

// 写一个throw抛出异常，局部对象被自动销毁的例子



int main() {
    int nums[5] = {1,2,3,4,5};
    func(nums, 5); // 等价于 func(&nums[0])
    return 0;
}
