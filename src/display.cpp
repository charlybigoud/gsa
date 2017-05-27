#include "display.hpp"

void bar()
{
    std::cout << yellow("\tT\t\tDT\t\tE") << std::endl;
    std::cout << yellow(std::string(42, '-')) << std::endl;
}

void blank_line()
{
    // std::cout << "\n\r\e[A";
    // std::cout << "\r";
    // std::cout << std::string(100, ' ');

    std::cout << "\r";
}
