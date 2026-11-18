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