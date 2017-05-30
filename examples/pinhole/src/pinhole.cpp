#include <iostream>
#include <random>

#include <simulated_annealing.hpp>

#include "points.hpp"
#include "camera.hpp"

double cost_function(const Observations& observations, const PinholeCameraModel& model)
{
    double err = 0.0;
    for (size_t i = 0 ; i<observations.pixels.size(); ++i)
    {
        double d = distance(observations.pixels.at(i), model.project(observations.p3ds.at(i)));
        err += std::hypot(d, d);
    }

    return std::sqrt(err / (double)observations.pixels.size());
}

struct Energy
{
    const Observations& observations;

    double operator()(const PinholeCameraModel& p) const
    {
        return cost_function(observations, p);
    }
};

struct Generator
{
    PinholeCameraModel operator()(PinholeCameraModel const& p, const SimulatedAnnealing& s) const
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> distrib(0, 1.0);

        return PinholeCameraModel{
              p.focal + s.current_it * distrib(gen)
            , p.u0 + s.current_it * distrib(gen)
            , p.v0 + s.current_it * distrib(gen)
            , p.k + 1e-5 * distrib(gen)
            , p.l + 1e-5 * distrib(gen)
        };
    }
};

int main()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> distrib(0, 10.0);

    PinholeCameraModel reference_camera{200.0, 400.0, 400.0, 1.0, 1.0};

    //Creating observations
    Observations observations;

    for (double p = 0; p < 100.0; ++p)
    {
        observations.p3ds.emplace_back( p * distrib(g), p * distrib(g), 100.0);
    }
    // for (auto& p : observations.p3ds)
    //     std::cout << p << "\n";

    observations.pixels.resize(observations.p3ds.size());
    for (size_t i = 0; i < observations.pixels.size(); ++i)
        observations.pixels[i] = reference_camera.project(observations.p3ds[i]);
    // for (auto& p : observations.pixels)
    //     std::cout << p << "\n";

    PinholeCameraModel camera_to_optimize;
    Energy energy{observations};
    Generator gen;

    std::cout << "initial state:\n" << camera_to_optimize << std::endl;

    SimulatedAnnealing sim(1e6, 1e-3, int(1e4));
    sim(energy, camera_to_optimize, gen);

    std::cout << "final state:\n" << camera_to_optimize << std::endl;
}
