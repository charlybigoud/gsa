#include <iostream>
#include <random>

#include <simulated_annealing.hpp>

int main()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<> distrib(0, 1.0);

    SimulatedAnnealing sim(
          1e3       //start temp
        , 1e-3      //stop temp
        , int(1e10) //max it
        , 1e-4      //energy min
        );

    return 0;   
}