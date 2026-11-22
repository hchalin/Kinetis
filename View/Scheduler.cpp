//
// Created by Hayden Chalin on 11/21/26.
//

#include "Scheduler.h"
#define DEBUG 0

namespace kinetis {
    using namespace std::chrono;
    Scheduler::Scheduler(kinetis::Simulation& sim):
        _startTime(steady_clock::now()),
        _accumulator(0.0), _dT(1.0 / 120.0), _frameThreshold(2.5e-2),
        _simulation(sim)
    {
    }

    /**
     *     Semi-implicit Euler Integration
     *      Source: https://www.gafferongames.com/post/fix_your_timestep/
     *
     *      Note: This can be improved upon
     */
    void Scheduler::timeStep() {

        using namespace std::chrono;

        const auto newTime = steady_clock::now();

        const duration<double> elapsed = newTime - _startTime;
        double frameTime = elapsed.count();

        // Clamp frame-time
        if (frameTime >= _frameThreshold)
            frameTime = _frameThreshold;
       _startTime = newTime;

#ifdef DEBUG
        std::cout << "Frame in flight time: " << frameTime << " ms" << std::endl;
#endif

        _accumulator += frameTime;

        // Advance physics simulation
        while (_accumulator >= _dT) {
            _simulation.step(_dT);
            _accumulator -= _dT;
        }

    }


    // Scheduler
}
