#include "simulated_annealing.hpp"

SimulatedAnnealing::SimulatedAnnealing(double start_tmp, double stop_tmp, int it_max, double min_e
    //, double tol = 0.1
) :
  start_temperature(start_tmp)
, stop_temperature(stop_tmp)
, iterations_per_temperature(it_max)
, min_energy(min_e)
// , acceptation_tolerance(tol)
{};

double SimulatedAnnealing::random_value()
{
    return double(std::rand()) / double(RAND_MAX);
}

bool SimulatedAnnealing::metropolis_critieria(const double delta_e, const double temperature)
{
    if (delta_e <= 0)
        return true;
    else if (random_value() <= std::exp(-delta_e / temperature) )
        return true;
    else
        return false;
}

double SimulatedAnnealing::temperature() const
{
    // assert(current_it >= iterations_per_temperature);
    // return ( double(current_it) / double(iterations_per_temperature)) * current_temperature;

    return 0.99 * current_temperature;
}
