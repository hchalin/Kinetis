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
        Scheduler(kinetis::Simulation &sim);

        Scheduler(kinetis::Simulation &sim, time_point<steady_clock> tp);

        ~Scheduler() = default;

        void timeStep();
        int timeStep( const time_point<steady_clock> & newTime, const time_point<steady_clock>& startTime);

    private:
        time_point<steady_clock> _startTime;
        double _accumulator;
        double _dT;
        double _frameThreshold;

        kinetis::Simulation &_simulation;
    };
}
