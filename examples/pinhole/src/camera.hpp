#pragma once

#include <random>

#include "points.hpp"

struct PinholeCameraModel
{
    double focal;
    double u0;
    double v0;
    double k;
    double l;

    PinholeCameraModel(const double f = 1.0, const double u = 1.0, const double v = 1.0, const double k_i = 1.0, const double l_i  = 1.0)
    : focal(f), u0(u), v0(v), k(k_i), l(l_i)
    {};

    P2D project(const P3D& p3d) const
    {
        return {
              (focal / k) * p3d.x() / p3d.z() + u0
            , (focal / l) * p3d.y() / p3d.z() + v0
        };
    };
};

std::ostream& operator<<(std::ostream& o, const PinholeCameraModel& ucm)
{
    o << "\t- focal: " << ucm.focal << "\n";
    o << "\t- center: {" << ucm.u0 << ", " << ucm.v0 << "}\n";
    o << "\t- k: " << ucm.k << "\n";
    o << "\t- l: " << ucm.l << "\n";
    return o;
}

struct Observations
{
    P3DS p3ds;
    P2DS pixels;
};
