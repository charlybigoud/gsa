#pragma once

#include <iostream>
#include <iomanip>
#include <string.h>

template<typename T>
std::string to_string(const T& t)
{
    std::ostringstream strs;
    strs << std::scientific << std::setprecision(3) << t;
    return strs.str();
}
