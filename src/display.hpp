#pragma once

#include <iostream>
#include <iomanip>
#include <string.h>

#include "colors.hpp"

std::string delta();

void blank_line();

struct Initial
{
    template<typename T>
    std::string operator()(const T& s)
    {
        return gsa::color<gsa::Yellow>(s);
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

template<typename Solver>
void print(const Solver& slr,
           Initial i = Initial{})
{
    std::cout << '\n'
              << std::setw(22) << i("#")
              << std::setw(22) << i("T")
              << std::setw(23) << i(delta() + "T")
              << std::setw(22) << i("E")
              << std::setw(22) << i(delta() + "E")
              << '\n'
              << i(std::string(65, '-')) << std::endl;
}

template<typename Solver>
void print(const Solver& slr, Final f = Final{})
{
    std::cout << "\n\n"
              << f("Total iterations: ") << f(slr.total_it) << "\n"
              << f("Final temperature: ") << f(slr.current_temperature) << "\n"
              << f("Final energy: ") << f(slr.validated_energy) << "\n"
              << '\n'
              << std::endl;
}

template<typename Status, typename Solver>
void print(const Solver& slr, Status s = Status{})
{
    blank_line();

    std::cout << std::setw(22) << s(slr.total_it)
              << std::setw(22) << s(slr.current_temperature)
              << std::setw(22) << s(slr.current_temperature - slr.temperature())
              << std::setw(22) << s(slr.validated_energy)
              << std::setw(22) << s(slr.current_energy - slr.validated_energy);
}
