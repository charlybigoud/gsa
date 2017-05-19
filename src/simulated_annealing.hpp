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
    // double acceptation_tolerance;

    double current_temperature;
    int current_it;
    double current_energy;

    SimulatedAnnealing(double start_tmp = 1e3, double stop_tmp = 0.0, int it_max = 1000, double min_e = 0.0);

    double random_value();

    bool metropolisCritieria(const double delta_e, const double temperature);

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
    current_it = 0;
    current_temperature = start_temperature;
    double previous_energy = energy(state);
    current_energy = previous_energy;

    bar();

    while (
        (current_temperature >= stop_temperature)
    // or (current_energy >= min_energy)
    )
    {
        const State current_state = generate(state, *this);
        current_energy = energy(current_state);

        if (metropolisCritieria(current_energy - previous_energy, current_temperature))
        {
            state = current_state;
            previous_energy = current_energy;

            print(*this, Accepted{});

        }
        else
        {
            // print(*this, Rejected{});
        }

        if (current_it > iterations_per_temperature)
        {
            current_temperature = temperature();
            current_it = 0;
        }
        else
        {
           ++current_it;
        }
    }

    final_print(*this);
}
