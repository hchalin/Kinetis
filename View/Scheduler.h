//
// Created by Hayden Chalin on 11/21/26.
//

#pragma once

#include <chrono>

#include "Simulation/Simulation.h"

namespace kinetis {
    using namespace std::chrono;

    class Scheduler {
    public:
        explicit Scheduler(kinetis::Simulation &sim);
        ~Scheduler() = default;

        // Production: calculate elapsed time automatically
        void timeStep();

        // Testing: supply elapsed time manually (seconds)
        int timeStep(double elapsedSeconds);

    private:
        steady_clock::time_point _startTime;

        double _accumulator;
        double _dT;
        double _frameThreshold;

        kinetis::Simulation &_simulation;
    };
}
