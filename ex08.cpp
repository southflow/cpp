#include "Message.hpp"
#include "Sales_item.hpp"
#include "Screen.hpp"
#include <stdexcept>
#include <iostream>
int main() {
    // Folder folder("Inbox");
    // Message msg("Hello, World!");
    // msg.save(folder);
    // msg.print(); // Print message and folders
    // Sales_item item1;
    // std::cin >> item1;
    // std::cout << item1 << std::endl;
        // 创建一个 Screen 对象并用 ScreenPtr 管理
    Screen *pScreen = new Screen("abcdefghi", 3, 3);
    ScreenPtr sp1(pScreen);

    // 测试 operator-> 和 operator*
    std::cout << "sp1->get(0,0): " << sp1->get(0, 0) << std::endl;  // 输出 'a'
    std::cout << "(*sp1).get(1,1): " << (*sp1).get(1, 1) << std::endl;  // 输出 'e'

    // 测试拷贝构造函数
    ScreenPtr sp2 = sp1;
    std::cout << "sp2->get(2,2): " << sp2->get(2, 2) << std::endl;  // 输出 'i'

    // 测试赋值运算符
    ScreenPtr sp3(new Screen("123456789", 3, 3));
    sp3 = sp1;
    std::cout << "sp3->get(0,1): " << sp3->get(0, 1) << std::endl;  // 输出 'b'

    // 测试空指针（应抛出异常）
    try {
        ScreenPtr spNull(nullptr);
        spNull->get(0, 0);  // 抛出异常
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}