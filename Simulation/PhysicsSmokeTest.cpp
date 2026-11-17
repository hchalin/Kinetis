//
// Created by Hayden Chalin on 11/16/26.
//
#include <memory>

#include <chrono/physics/ChSystemNSC.h>
#include <chrono/physics/ChBody.h>
#include <chrono/assets/ChVisualShapes.h>

constexpr double N = 480.0;
constexpr double dT = 1.0/N;

using namespace chrono;
int main() {

    ChSystemNSC sys;

    const ChVector3d gacc{0, 0, -9.81};
    sys.SetGravitationalAcceleration(gacc);

    auto body = std::make_shared<ChBody>();
    const double startHeight {3.0};
    body->SetPos(ChVector3d{0, 0, startHeight});


    const double mass {1.0};
    body->SetMass(mass);

    const double a {1.0};
    const double b {1.0};
    const double c {1.0};
    const double iXX = mass/12.0*((b*b) + (c*c));
    const double iYY = mass/12.0*((a*a) + (c*c));
    const double iZZ = mass/12.0*((a*a) + (b*b));

    auto inertiaDiagonal = ChVector3d{iXX,iYY,iZZ};
    body->SetInertiaXX(inertiaDiagonal);

    sys.AddBody(body);

    for (int i {0}; i < N; ++i) {
        sys.DoStepDynamics(dT);
    }
    // Simulation time
    auto simTime = sys.GetChTime();
    auto chronoCalculatedPosistion = body->GetPos().z();
    const double analyticalPosition = startHeight + 1.0/2.0*(gacc.z())*1*1;
    const double absoluteError = chronoCalculatedPosistion - analyticalPosition;

    std::cout << "N value: " << N << std::endl;
    std::cout << "Final Simulation Time: " << simTime << "s" << std::endl;
    std::cout << "Chrono's calculated final position: " << chronoCalculatedPosistion << "m"<< std::endl;
    std::cout << "Calculated final position:j " << analyticalPosition << "m"<< std::endl;
    std::cout << "Calculated height difference: " << std::abs(absoluteError) << "m"<< std::endl;



}