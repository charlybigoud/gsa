#pragma once

#include <iostream>
#include <iomanip>
#include <string.h>

#include "colors.hpp"

std::string delta();

void bar();
void blank_line();

struct Accepted
{
    template<typename T>
    std::string operator()(const T& s)
    {
        return gsa::color<gsa::Green>(s);
    };
};

struct Rejected
{
    template<typename T>
    std::string operator()(const T& s)
    {
        return gsa::color<gsa::Red>(s);
    };
};

struct Final
{
    template<typename T>
    std::string operator()(const T& s)
    {
        return gsa::color<gsa::Cyan>(s);
    };
};

template<typename Status, typename Solver>
void print(const Solver& slr
         , Status s = Status{}
          )
{
    blank_line();

    std::cout << std::setw(22) << s(slr.total_it);
    std::cout << std::setw(22) << s(slr.current_temperature);
    std::cout << std::setw(22) << s(slr.current_temperature - slr.temperature());
    std::cout << std::setw(22) << s(slr.validated_energy);
    // std::cout << slr.d_energy << "\t";
}

template<typename Solver>
void print(const Solver& slr, Final f)
{
    std::cout << '\n' << std::endl;
    std::cout << f("Total iterations: ") << f(slr.total_it) << "\n";
    std::cout << f("Final temperature: ") << f(slr.current_temperature) << "\n";
    std::cout << f("Final energy: ") << f(slr.validated_energy) << "\n";
    std::cout << '\n' << std::endl;
}
