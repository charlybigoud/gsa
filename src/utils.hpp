#pragma once

#include <iostream>
#include <iomanip>
#include <string.h>
#include <tuple>

template<typename T>
std::string to_string(const T& t)
{
    std::ostringstream strs;
    strs << std::scientific << std::setprecision(3) << t;
    return strs.str();
}

// save and restore T
template<typename ... T>
struct BackUp
{
    std::tuple<T...> values;
    std::tuple<T&...> reference;

    void restore() { reference = values; }
};

template<typename ... T>
BackUp<T...> back_up(T& ... args)
{
    return BackUp<T...>{ std::make_tuple(args...), std::tie(args...) };
}
