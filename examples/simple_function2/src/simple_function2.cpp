#include <iostream>
#include <random>

#include <simulated_annealing.hpp>

//parameters to optimize
struct Parameters
{
    double x;
};

double cost_function(const Parameters& p)
{
    return 5.0 * std::cos(0.25 * p.x) + p.x * (p.x / 750.0);
}

struct Energy
{
    double operator()(const Parameters& p) const
    {
        return cost_function(p);
    }
};

struct Generator
{
    Parameters operator()(const Parameters& p, const SimulatedAnnealing& s) const
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::normal_distribution<> distrib(0, 1.0);

        // return Parameters{p.x + distrib(generator)};
        // return Parameters{p.x + 0.01 * s.current_temperature * distrib(generator)};
        // return Parameters{p.x + s.current_temperature * distrib(generator)};
        return Parameters{p.x + s.current_temperature * s.step_it * distrib(generator)};
    }
};

int main()
{
    SimulatedAnnealing sim(1e3, 1e-3, int(1e2));

    Energy energy;
    Parameters params{1e3};
    Generator gen;

    std::cout << "initial value: " << params.x << " (err: " << energy(params) << ")" << std::endl;

    sim(energy, params, gen);

    std::cout << "final value: " << params.x << " (err: " << energy(params) << ")" << std::endl;
}
