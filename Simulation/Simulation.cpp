//
// Created by Hayden Chalin on 11/17/26.
//

#include "Simulation.h"

namespace kinetis {
    Simulation::Simulation() : _systemNCS("Kinetis Simulation") {
    }

    Simulation::Simulation(chrono::ChVector3d gacc) : _systemNCS("Kinetis Simulation") {
        _systemNCS.SetGravitationalAcceleration(gacc);
    }


    void Simulation::step(double dT) {
        _systemNCS.DoStepDynamics(dT);
    }

    void Simulation::addBody(std::shared_ptr<chrono::ChBody> body) {
        _systemNCS.AddBody(body);
    }

    double Simulation::getSimTime() const {
        return _systemNCS.GetChTime();
    }

}

