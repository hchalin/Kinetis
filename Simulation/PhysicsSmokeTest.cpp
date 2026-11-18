//
// Created by Hayden Chalin on 11/16/26.
//
#include <memory>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include <chrono/physics/ChSystemNSC.h>
#include <chrono/physics/ChBody.h>
#include <chrono/assets/ChVisualShapes.h>

#include "Simulation.h"

constexpr int N = 480;
/// Step size in time
constexpr double dT = 1.0/N;
constexpr double expectedSimTime = 1.0;
constexpr double timeTolerance = 1e-10;
constexpr double posTolerance = 1.5e-2;


int main() {

    // Gravitational constant
    const chrono::ChVector3d gacc{0, 0, -9.81};
    kinetis::Simulation sim{gacc};

    const double startHeight {3.0};
    const double mass {1.0};
    auto body = std::make_shared<chrono::ChBody>();
    body->SetPos(chrono::ChVector3d{0, 0, startHeight});
    body->SetMass(mass);

    const double a {1.0};
    const double b {1.0};
    const double c {1.0};
    const double iXX = mass/12.0*((b*b) + (c*c));
    const double iYY = mass/12.0*((a*a) + (c*c));
    const double iZZ = mass/12.0*((a*a) + (b*b));

    auto inertiaDiagonal = chrono::ChVector3d{iXX,iYY,iZZ};
    body->SetInertiaXX(inertiaDiagonal);

    sim.addBody(body);

    for (int i {0}; i < N; ++i) {
        sim.step(dT);
    }
    // Simulation time
    const double simTime = sim.getSimTime();
    const double position = body->GetPos().z();
    /// Calculated final position
    const double analyticalPosition = startHeight + 1.0/2.0*(gacc.z())*1*1;
    const double absoluteError = std::abs(position - analyticalPosition);

    std::cout << "N value: " << N << std::endl;
    std::cout << "Final Simulation Time: " << simTime << "s" << std::endl;
    std::cout << "Chrono's calculated final position: " << position << "m"<< std::endl;
    std::cout << "Calculated final position: " << analyticalPosition << "m"<< std::endl;
    std::cout << "Calculated height difference: " << absoluteError*100.0 << "cm"<< std::endl;

    if (std::abs(simTime - expectedSimTime) < timeTolerance && (std::abs(analyticalPosition - position) < posTolerance))
        return EXIT_SUCCESS;
    else {
        std::cerr << "Simulation time was out of tolerance." << std::endl;
        return EXIT_FAILURE;
    }

}