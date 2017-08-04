#include "display.hpp"

std::string delta()
{
    return "\u0394";
    // return "\xCE\x94";
}

void bar()
{
    std::cout << std::setw(22) << gsa::color<gsa::Yellow>("#");
    std::cout << std::setw(22) << gsa::color<gsa::Yellow>("T");
    std::cout << std::setw(23) << gsa::color<gsa::Yellow>(delta() + "T");
    std::cout << std::setw(22) << gsa::color<gsa::Yellow>("E");
    std::cout << '\n';

    std::cout << gsa::color<gsa::Yellow>(std::string(53, '-')) << std::endl;
}

void blank_line()
{
    std::cout << "\n\e[A";

    // std::cout << "\n\r\e[A";
    // std::cout << "\r";

    // std::cout << "\r";
}
