#include <iostream>

#include <simulated_annealing.hpp>

struct City{
    float x;
    float y;
};

using Trajectory = std::vector<City>;

struct Generator{
    Trajectory operator()(const Trajectory& t, const SimulatedAnnealing& sa) const
    {
        return Trajectory{};
    }
};

struct Energy{
    double operator()(const Trajectory& t) const
    {
        return {};
    }
};

int main()
{
    City clermont_ferrand{0, 0}; //center of the universe
    City madrid{-10, -100};
    City new_york{-1000, 20};
    City shanghai{+5000, -100};

    Trajectory trajectory{clermont_ferrand, madrid, new_york, shanghai};
    Energy energy;
    Generator generator;

    SimulatedAnnealing sim(
          1e3       //start temp
        , 1e-3      //stop temp
        , int(1e10) //max it
        , 1e-4      //energy min
        );


    std::cout << gsa::color<gsa::Red>(std::string("\nNothing is done here")) << std::endl;
    std::cout << gsa::color<gsa::Blue>(std::string(";( :( :@")) << std::endl;
    std::cout << gsa::color<gsa::Green>(std::string("Please come back later")) << std::endl;
    std::cout << gsa::color<gsa::Yellow>(std::string(";) :) :D")) << std::endl;

    sim(energy, trajectory, generator);

    return 0;
}
