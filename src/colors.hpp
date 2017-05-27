#pragma once

#include <string.h>

#include "utils.hpp"

template<typename T>
std::string red(const T& t)
{
    return "\033[31m" + to_string(t) + "\033[0m";
}

template<typename T>
std::string green(const T& t)
{
    return "\033[32m" + to_string(t) + "\033[0m";
}

template<typename T>
std::string yellow(const T& t)
{
    return "\033[33m" + to_string(t) + "\033[0m";
}

template<typename T>
std::string blue(const T& t)
{
    return "\033[34m" + to_string(t) + "\033[0m";
}

template<typename T>
std::string white(const T& t)
{
    return "\033[37m" + to_string(t) + "\033[0m";
}

std::string red(const std::string& s);
std::string green(const std::string& s);
std::string yellow(const std::string& s);
std::string blue(const std::string& s);
std::string white(const std::string& s);

