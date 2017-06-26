#pragma once

#include <random>
#include <cassert>

#include "display.hpp"

// https://fr.wikipedia.org/wiki/Recuit_simul%C3%A9

// Par exemple, on pourrait avoir trois paramètres : la température
// initiale, la longueur d’un palier (nombre d’itérations avant de
// changer la température) et le coefficient de décroissance (si
// décroissance géométrique).
// • On peut aussi utiliser d’autres schémas de refroidissement :
// – On peut faire décroître la température à chaque itération.
// – On utilise parfois une température constante (algorithme de Metropolis).
// – On peut utiliser des schémas plus complexes, dans lesquels la
// température peut parfois remonter.
struct CoolingSchedule{};

struct SimulatedAnnealing
{
    double start_temperature;
    double stop_temperature;
    int iterations_per_temperature;
    double min_energy;
    double alpha;
    // double acceptation_tolerance;

    double current_temperature;
    int step_it;                    // the iteration counter in the temperture step
    int total_it;                   // the total iteration counter
    double validated_energy;
    double current_energy;

    SimulatedAnnealing(
          const double start_tmp = 1e3
        , const double stop_tmp = 0.0
        , const int max_it = 1000
        , const double min_e = 0.0
        , const double a = 0.99
        // , const double tol = 0.1
    );

    double random_value() const;

    bool stop(const double temperature, const double energy) const;

    bool metropolis_critieria(const double delta_e, const double temperature) const;

    double temperature() const;

    template<typename Energy, typename State, typename Generator>
    void operator()(const Energy& energy, State& state, const Generator& generate);
};

template<typename Energy, typename State, typename Generator>
void SimulatedAnnealing::operator()(const Energy& energy, State& state, const Generator& generate)
{
    //State to save in each temperature step
    // State state_to_save;
    // double energy_to_save;

    //initiate system
    current_temperature = start_temperature;
    step_it = 0;
    total_it = 0;
    validated_energy = energy(state);
    current_energy = validated_energy;

    bar();

    while ( stop(current_temperature, current_energy) )
    {
        auto backup = back_up(state);

        state = generate(state, *this);
        current_energy = energy(state);

        if (metropolis_critieria(current_energy - validated_energy, current_temperature))
        {
            print<Accepted>(*this);

            validated_energy = current_energy;
        }
        else
        {
            print<Rejected>(*this);

            backup.restore();
        }

        if (step_it > iterations_per_temperature)
        {
            current_temperature = temperature();
            step_it = 0;
        }
        else
        {
           ++step_it;
        }

        ++total_it;
    }

    print(*this, Final{});
}
