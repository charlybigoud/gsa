#include <iostream>
#include <cmath>
#include <vector>
#include <array>

#include "simulated_annealing.hpp"

int main()
{
//////////////////////Camera//////////////////////

    // // building reference
    // PinholeCameraModel reference_camera(50.0, 200.0, 200.0, 1.0, 1.0);
    // std::cout << "reference_camera:\n" << reference_camera << std::endl;

    // // computing model
    // Observations observations{
    //       {{1,2,50}, {3,4,50}, {5,6,50}, {7,8,50}, {9,10,50}, {11,12,50}, {13,14,50}, {15,16,50}, {17,18,50}}
    // };

    // observations.pixels.resize(observations.p3ds.size());
    // for (size_t i=0 ; i<observations.pixels.size() ; ++i)
    //     observations.pixels[i] = reference_camera.project(observations.p3ds[i]);

    // PinholeCameraModel to_optimize{1.0, 1.0, 1.0, 1.0, 1.0};
    // CameraState<PinholeCameraModel> camera_state{reference_camera, 1.1};

    // SimulatedAnnealing<decltype(camera_state), Energy> sa{
    //     camera_state
    //     , Energy{camera_state, observations}
    //     , CoolingSchedule{}
    //     , 10.0
    //     , 0.0
    //     , int(1e4)
    //     , 1e3
    // };

    // std::cout << "camera_to_optimize:\n" << camera_state.f << std::endl;
    // sa.run();
    // std::cout << "camera_to_optimize:\n" << camera_state.f << std::endl;


    return 0;
}
