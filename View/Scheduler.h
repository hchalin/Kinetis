//
// Created by Hayden Chalin on 11/21/26.
//

#pragma once

#include <chrono>

#include "Simulation/Simulation.h"

namespace kinetis {

class Scheduler {
public:
    Scheduler(kinetis::Simulation& sim);
    ~Scheduler() = default;

    void timeStep();

private:
    std::chrono::time_point<std::chrono::steady_clock> _startTime;
    double _accumulator;
    double _dT;
    double _frameThreshold;

    kinetis::Simulation& _simulation;
};
}
