#include "display.hpp"

std::string delta()
{
    return "\u0394";
    // return "\xCE\x94";
}

void blank_line()
{
    std::cout << "\n\e[A";

    // std::cout << "\n\r\e[A";
    // std::cout << "\r";

    // std::cout << "\r";
}
