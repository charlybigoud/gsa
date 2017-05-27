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
void final_print(const Solver& s)
{
    std::cout << '\n' << std::endl;
    std::cout << "Final temperature: " << s.current_temperature << "\n";
    std::cout << "Final energy: " << s.validated_energy << "\n";
    std::cout << '\n' << std::endl;
}
