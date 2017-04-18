#include <iostream>
#include <random>

#include "../src/simulated_annealing.hpp"

//parameters to optimize
struct Parameters
{
    double x, y;
};

std::ostream& operator<<(std::ostream& o, const Parameters& p)
{
    o << "(" << p.x << ", " << p.y << ")";

    return o;
}

int main()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<> distrib(0, 1.0);

    SimulatedAnnealing sim(
          1e3      //start temp
        , 1e-3     //stop temp
        , 1000     //max iteration per temperature step
        , 1e-4     //energy min
        );

    auto ros_err = [](const Parameters& r)
    {
        return (1 - r.x) * (1 - r.x) + 100 * (r.y - r.x * r.x) * (r.y - r.x * r.x);
    };

    Parameters ros_parameters{100.0, 100.0};

    auto ros_gen = [&](const Parameters& r, const SimulatedAnnealing& s)
    {
        //fixed generator
        // return Parameters{
        //       r.x + distrib(generator)
        //     , r.y + distrib(generator)
        // };

        //generator depending on current_it
        // std::cout << (1e3 / (double(s.current_it))) << "\n";
        // return Parameters{
        //       r.x + 1e3 / (double(s.current_it) != 0 ? double(s.current_it) : 1.0) * distrib(generator)
        //     , r.y + 1e3 / (double(s.current_it) != 0 ? double(s.current_it) : 1.0) * distrib(generator)
        // };

        //generator depending on current_temperature
        return Parameters{
              r.x + s.current_temperature * distrib(generator)
            , r.y + s.current_temperature * distrib(generator)
        };
    };

    std::cout << "initial value: " << ros_parameters << std::endl;

    sim(ros_err, ros_parameters, ros_gen);

    std::cout << "final value: " << ros_parameters << std::endl;
}
