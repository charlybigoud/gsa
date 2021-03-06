#include <iostream>
#include <algorithm>
#include <random>

#include <simulated_annealing.hpp>

struct City{
    float x;
    float y;
};

float distance(const City& c1, const City& c2)
{
    return std::hypot(c2.x - c1.x, c2.y - c1.y);
}

using Trajectory = std::vector<City>;

std::ostream& operator<<(std::ostream& o, const Trajectory& t)
{
    for (auto& c : t)
        o << "[" << c.x << ", " << c.y << "], ";

    return o;
}

struct Generator{
    Trajectory operator()(const Trajectory& t, const SimulatedAnnealing& sa) const
    {
        Trajectory t2 = t;

        std::shuffle(begin(t2), end(t2), std::default_random_engine{});

        return t2;
    }
};

struct Energy{
    float operator()(const Trajectory& t) const
    {
        std::vector<float> distances;

        for (size_t i = 1; i < t.size(); ++i)
            distances.push_back(distance(t[i - 1], t[i]));

        return std::accumulate(begin(distances), end(distances), 0.0);
    }
};

int main()
{
    Energy energy;
    Generator generator;

    City c0 { 200.0,  800.0};
    City c1 {3600.0, 2300.0};
    City c2 {3100.0, 3300.0};
    City c3 {4700.0, 5750.0};
    City c4 {5400.0, 5750.0};
    City c5 {5608.0, 7103.0};
    City c6 {4493.0, 7102.0};
    City c7 {3600.0, 6950.0};
    Trajectory trajectory{c0, c1, c2, c3, c4, c5, c6, c7};

    std::cout << "Optimal trajectory: " << trajectory << std::endl;
    std::cout << "Optimal distance: " << energy(trajectory) << std::endl;

    SimulatedAnnealing sim(1e3, // start temp
                           1e-1, // stop temp
                           int(1e4), // max it
                           energy(trajectory)); // energy min

    std::shuffle(begin(trajectory), end(trajectory), std::default_random_engine{});

    std::cout << "Initial trajectory: " << trajectory << std::endl;

    sim(energy, trajectory, generator);

    std::cout << "Final trajectory: " << trajectory << std::endl;

    return 0;
}
