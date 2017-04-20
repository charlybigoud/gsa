#include <iostream>
#include <random>

#include <simulated_annealing.hpp>

int main()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<> distrib(0, 1.0);

    SimulatedAnnealing sim(1e4, 1e-3, int(1e3));

    // double x = -12.46;
    double x = -1e3;

    auto f = [](double x){ return 5.0 * std::cos(0.25 * x) + x * (x / 750.0); };

    // auto gen = [&](double x, SimulatedAnnealing& s){ return x + distrib(generator);};
    // auto gen = [&](double x, const SimulatedAnnealing& s){ return x + s.current_it * distrib(generator);};
    auto gen = [&](double x, const SimulatedAnnealing& s){
            return   x 
                   + (0.01 * s.current_temperature) * s.current_it * distrib(generator);
        };

    std::cout << "initial value: " << x << " (err: " << f(x) << ")" << std::endl;

    sim(f, x, gen);

    std::cout << "final value: " << x << " (err: " << f(x) << ")" << std::endl;
}
