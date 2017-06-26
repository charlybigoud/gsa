#include "display.hpp"

std::string delta()
{
    return "\u0394";
    // return "\xCE\x94";
}

void bar()
{
    std::cout << std::setw(22) << color<Yellow>("#");
    std::cout << std::setw(22) << color<Yellow>("T");
    std::cout << std::setw(23) << color<Yellow>(delta() + "T");
    std::cout << std::setw(22) << color<Yellow>("E");
    std::cout << '\n';

    std::cout << color<Yellow>(std::string(53, '-')) << std::endl;
}

void blank_line()
{
    std::cout << "\n\e[A";

    // std::cout << "\n\r\e[A";
    // std::cout << "\r";

    // std::cout << "\r";
}
