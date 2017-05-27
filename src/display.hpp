#pragma once

#include <iostream>
#include <iomanip>
#include <string.h>

// void print(const int it, const double energy);

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

// template<typename Solver, typename Color>
// template<typename Solver, typename T, typename Color = std::string (*Color)(T&)>
// template<typename T, std::string (*Color)(const T&), typename Solver>
// void print(
//       const Solver& s
//     // , const Color& c
//     )
// {
//     std::cout << Color(s.current_it) << "\t";
//     std::cout << Color(s.current_temperature) << "\t";
//     std::cout << Color(s.current_temperature - s.temperature(s.current_temperature)) << "\t";
//     std::cout << Color(s.current_energy) << "\t";
//     // // std::cout << s.d_energy << "\t";
//     std::cout << std::endl;
// }

struct Accepted{};
struct Rejected{};

template<typename Solver>
void print(
      const Solver& s
    , Accepted
    )
{
    // std::cout << green(s.current_it) << "\t";
    std::cout << green(s.current_temperature) << "\t";
    std::cout << green(s.current_temperature - s.temperature()) << "\t";
    std::cout << green(s.validated_energy) << "\t";
    // // std::cout << s.d_energy << "\t";

    std::cout << "\r";
}

template<typename Solver>
void print(
      const Solver& s
    , Rejected
    )
{
    // std::cout << red(s.current_it) << "\t";
    std::cout << red(s.current_temperature) << "\t";
    std::cout << red(s.current_temperature - s.temperature()) << "\t";
    std::cout << red(s.current_energy) << "\t";
    // // std::cout << s.d_energy << "\t";

    std::cout << "\r";
}

template<typename Solver>
void final_print(const Solver& s)
{
    std::cout << std::endl;
    std::cout << "Final temperature: " << s.current_temperature << "\n";
    std::cout << "Final energy: " << s.validated_energy << "\n";
    std::cout << std::endl;
}
