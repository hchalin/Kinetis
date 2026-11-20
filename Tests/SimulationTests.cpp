//
// Created by Hayden Chalin on 11/17/26.
//
#include <gtest/gtest.h>
#include "Simulation/Simulation.h"

TEST(SimulationTest, AdvancesTimeCorrectly) {
    kinetis::Simulation sim;

    constexpr int steps = 480;
    constexpr double dt = 1.0 / steps;

    for (int i = 0; i < steps; ++i) {
        sim.step(dt);
    }

    EXPECT_NEAR(sim.getSimTime(), 1.0, 1e-10);
}

TEST(SimulationTest, FallingBodyPositionTest) {
    const double tolerance = 1.5e-2;

    const chrono::ChVector3d gacc{0.0, 0.0, -9.81};
    kinetis::Simulation sim{gacc};

    // Create body at 3m high
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