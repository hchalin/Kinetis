//
// Created by Hayden Chalin on 11/21/26.
//

#include "Scheduler.h"

namespace kinetis {
    Scheduler::Scheduler(Simulation& sim):
        _startTime(steady_clock::now()),
        _accumulator(0.0), _dT(1.0 / 120.0), _frameThreshold(2.5e-2),
        _simulation(sim)
    {
    }


    void Scheduler::timeStep() {
        using namespace std::chrono;

        const auto newTime = steady_clock::now();

        const duration<double> elapsed = newTime - _startTime;
        double elapsedSeconds = elapsed.count();

        _startTime = newTime;

        // Delegate to the shared accumulator implementation
        timeStep(elapsedSeconds);
    }

/**
     *     Semi-implicit Euler Integration
     *      Source: https://www.gafferongames.com/post/fix_your_timestep/
     *
     *      Testable version
     */
    int Scheduler::timeStep(double elapsedSeconds) {

        // Clamp frame-time
        if (elapsedSeconds > _frameThreshold)
            elapsedSeconds = _frameThreshold;

        _accumulator += elapsedSeconds;

        int steps = 0;
        // Advance physics simulation
        while (_accumulator >= _dT) {
            _simulation.step(_dT);
            _accumulator -= _dT;

            ++steps;
        }

        return steps;

    }
}
