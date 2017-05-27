#pragma once

#include <iostream>
#include <iomanip>
#include <string.h>

#include "colors.hpp"

void bar();
void blank_line();

struct Accepted
{
    template<typename T>
    std::string operator()(const T& s)
    {
        return green(s);
    };
};

struct Rejected
{
    template<typename T>
    std::string operator()(const T& s)
    {
        return red(s);
    };
};

struct Final
{
    template<typename T>
    std::string operator()(const T& s)
    {
        return blue(s);
    };
};

template<typename Color, typename Solver>
void print(const Solver& s)
{
    blank_line();

    // std::cout << Color{}(s.current_it) << "\t";
    std::cout << Color{}(s.current_temperature) << "\t";
    std::cout << Color{}(s.current_temperature - s.temperature()) << "\t";
    std::cout << Color{}(s.validated_energy) << "\t";
    // std::cout << s.d_energy << "\t";
}

template<typename Solver>
void print(Final f, const Solver& s)
{
    std::cout << '\n' << std::endl;
    std::cout << f("Final temperature: ") << f(s.current_temperature) << "\n";
    std::cout << f("Final energy: ") << f(s.validated_energy) << "\n";
    std::cout << '\n' << std::endl;
}
