//
// Created by Hayden Chalin on 11/17/26.
//
#include <gtest/gtest.h>
#include "Simulation/Simulation.h"
#include "View/Scheduler.h"
/**
 *  Test that the simulation advances the correct amount of time
 *  Simulation Time: 1.0s
 */
TEST(SimulationTest, AdvancesTimeCorrectly) {
    kinetis::Simulation sim;

    constexpr int steps = 480;
    constexpr double dt = 1.0 / steps;

    for (int i = 0; i < steps; ++i) {
        sim.step(dt);
    }

    EXPECT_NEAR(sim.getSimTime(), 1.0, 1e-10);
}

/**
 *  This test verifies that the simulated position calculation of a falling object matches that of the
 *  arithmatic calculation.
 */
TEST(SimulationTest, FallingBodyPositionTest) {
    const double tolerance = 1.5e-2;

    const chrono::ChVector3d gacc{0.0, 0.0, -9.81};
    kinetis::Simulation sim{gacc};

    // Create a body at 3 meters high
    auto body = std::make_shared<chrono::ChBody>();
    constexpr double startHeight = 3.0;
    constexpr double startTime = 0.0;
    constexpr double initialVelo = 0.0; // m/s
    body->SetPos(chrono::ChVector3d(0.0, 0.0, startHeight));

    sim.addBody(body);

    constexpr int steps = 480;
    double dT = 1.0/steps;
    for (int i = 0; i < steps; ++i) {
        sim.step(dT);
    }

    // x(t) = x_0 + v_0*t + 1/2 a*t*t
    const double calculatedPosition = startHeight + (initialVelo * startTime) + (1.0/2.0)*(gacc.z())*(std::pow(sim.getSimTime(), 2));
    const double simulatedPosition = body->GetPos().z();

    EXPECT_NEAR(calculatedPosition, simulatedPosition, tolerance);
}

TEST(SchedulerTest, MultipleStepsForLongFrame) {
    kinetis::Simulation sim;
    kinetis::Scheduler scheduler(sim);

    // Simulate a frame taking 22 milliseconds
    const int steps = scheduler.timeStep(0.022);

    EXPECT_EQ(steps, 2);

    EXPECT_NEAR(
        sim.getSimTime(),
        2.0 / 120.0,
        1e-10
    );
}