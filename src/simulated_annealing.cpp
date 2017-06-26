#include "simulated_annealing.hpp"

SimulatedAnnealing::SimulatedAnnealing(
      const double start_tmp
    , const double stop_tmp
    , const int max_it
    , const double min_e
    , const double a
    // , const double tol
) :
  start_temperature(start_tmp)
, stop_temperature(stop_tmp)
, iterations_per_temperature(max_it)
, min_energy(min_e)
, alpha(a)
// , acceptation_tolerance(tol)
{};

double SimulatedAnnealing::random_value() const
{
    return double(std::rand()) / double(RAND_MAX);
}

bool SimulatedAnnealing::stop(const double temperature, const double energy) const
{
    return (temperature >= stop_temperature)
        or (energy >= min_energy)
        ;
}

bool SimulatedAnnealing::metropolis_critieria(const double delta_e, const double temperature) const
{
    if (delta_e <= 0.0)
        return true;
    else if (random_value() <= std::exp(-delta_e / temperature) )
        return true;
    else
        return false;
}

double SimulatedAnnealing::temperature() const
{
    return alpha * current_temperature;
}
