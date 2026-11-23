//
// Created by Hayden Chalin on 11/21/26.
//

#include "Scheduler.h"
#define DEBUG 0

namespace kinetis {
    Scheduler::Scheduler(Simulation& sim):
        _startTime(steady_clock::now()),
        _accumulator(0.0), _dT(1.0 / 120.0), _frameThreshold(2.5e-2),
        _simulation(sim)
    {
    }

    /**
     * This constructor is used for testing the accumulator using fixed time steps
     * @param sim
     * @param tp
     */
    // TODO: Finish this
    Scheduler::Scheduler(Simulation& sim, time_point<steady_clock> tp):
     _startTime(steady_clock::now()),
     _accumulator(0.0), _dT(1.0 / 120.0), _frameThreshold(2.5e-2),
     _simulation(sim)
    {
    }

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
        std::cout << "Frame in flight time: " << elapsed <<  std::endl;
#endif

        _accumulator += frameTime;

        // Advance physics simulation
        while (_accumulator >= _dT) {
            _simulation.step(_dT);
            _accumulator -= _dT;
        }

    }
/**
     *     Semi-implicit Euler Integration
     *      Source: https://www.gafferongames.com/post/fix_your_timestep/
     *
     *      Testable version
     */
    int Scheduler::timeStep( const time_point<steady_clock> & newTime, const time_point<steady_clock>& startTime) {

        using namespace std::chrono;

        // const auto newTime = steady_clock::now();    // This variable is now passed in
        // Now: Update outer-scoped variable to test the version passed in
        _startTime = startTime;

        const duration<double> elapsed = newTime - _startTime;
        double frameTime = elapsed.count();

        // Clamp frame-time
        if (frameTime >= _frameThreshold)
            frameTime = _frameThreshold;
       _startTime = newTime;

#ifdef DEBUG
        std::cout << "Frame in flight time: " << elapsed <<  std::endl;
#endif

        _accumulator += frameTime;

        // Advance physics simulation
        while (_accumulator >= _dT) {
            _simulation.step(_dT);
            _accumulator -= _dT;
        }

        return 1;

    }
}
