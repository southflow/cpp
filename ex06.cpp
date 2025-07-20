#include <iostream>

class Logger {
public:
    static void log(const std::string& message) {
        std::cout << "[LOG] " << message << std::endl;
        ++callCount; // 只能操作静态成员变量
    }
private:
    static int callCount; // 记录日志调用次数
};

int Logger::callCount = 0; // 定义静态变量

int main() {
    Logger::log("System started"); // 直接通过类名调用
    Logger::log("User logged in");
    // Logger::callCount; // 错误：private 成员无法外部访问
}