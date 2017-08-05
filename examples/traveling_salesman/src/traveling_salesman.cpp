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

        for (int i = 1; i < t.size(); ++i)
            distances.push_back(distance(t[i-1], t[i]));

        return std::accumulate(begin(distances), end(distances), 0.0);
    }
};

int main()
{
    Energy energy;
    Generator generator;

    // City clermont_ferrand{0, 0}; //center of the universe
    // City madrid{-10, -100};
    // City new_york{-1000, 20};
    // City shanghai{+5000, -100};
    // Trajectory trajectory{clermont_ferrand, madrid, new_york, shanghai};

    // City a0 {0.0, 0.0};
    // City a1 {1.0, 0.0};
    // City a2 {2.0, 0.0};
    // City a3 {3.0, 0.0};
    // City a4 {4.0, 0.0};
    // City a5 {5.0, 0.0};
    // City a6 {6.0, 0.0};
    // City a7 {7.0, 0.0};
    // City a8 {8.0, 0.0};
    // City a9 {9.0, 0.0};
    // City a10 {10.0, 0.0};
    // City a11 {11.0, 0.0};
    // City a12 {12.0, 0.0};
    // City a13 {13.0, 0.0};
    // City a14 {14.0, 0.0};
    // City a15 {15.0, 0.0};
    // Trajectory trajectory{a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15};

    City a0 { 200.0,  800.0};
    City a1 {3600.0, 2300.0};
    City a2 {3100.0, 3300.0};
    City a3 {4700.0, 5750.0};
    City a4 {5400.0, 5750.0};
    City a5 {5608.0, 7103.0};
    City a6 {4493.0, 7102.0};
    City a7 {3600.0, 6950.0};
    Trajectory trajectory{a0, a1, a2, a3, a4, a5, a6, a7};

    std::cout << "Optimal trajectory: " << trajectory << std::endl;
    std::cout << "Optimal distance: " << energy(trajectory) << std::endl;

    SimulatedAnnealing sim(
          1e3       //start temp
        , 1e-1      //stop temp
        , int(1e4)  //max it
        , energy(trajectory)      //energy min
        );

    std::shuffle(begin(trajectory), end(trajectory), std::default_random_engine{});

    std::cout << "Initial trajectory: " << trajectory << std::endl;

    sim(energy, trajectory, generator);

    std::cout << "Final trajectory: " << trajectory << std::endl;

    return 0;
}
