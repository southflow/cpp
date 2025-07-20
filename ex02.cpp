#include <iostream>

int main() {
    int v1, v2;
    std::cin >> v1 >> v2;

    if (std::cin.fail()) { // 检查是否有输入失败
        std::cerr << "错误：输入必须是数字！" << std::endl;
        return 1;
    }

    std::cout << v1 + v2 << std::endl;
}