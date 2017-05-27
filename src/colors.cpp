#include "colors.hpp"

std::string red(const std::string& s)
{
    return "\033[31m" + s + "\033[0m";
}

std::string green(const std::string& s)
{
    return "\033[32m" + s + "\033[0m";
}

std::string yellow(const std::string& s)
{
    return "\033[33m" + s + "\033[0m";
}

std::string blue(const std::string& s)
{
    return "\033[34m" + s + "\033[0m";
}

std::string white(const std::string& s)
{
    return "\033[37m" + s + "\033[0m";
}
