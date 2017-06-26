#include "display.hpp"

void bar()
{
    std::cout << color<Yellow>("\tT\t\tDT\t\tE") << std::endl;
    std::cout << color<Yellow>(std::string(42, '-')) << std::endl;
}

void blank_line()
{
    std::cout << "\n\e[A";

    // std::cout << "\n\r\e[A";
    // std::cout << "\r";

    // std::cout << "\r";
}
