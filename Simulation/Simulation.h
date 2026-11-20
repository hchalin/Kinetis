//
// Created by Hayden Chalin on 11/17/26.
//

#pragma once
#include <chrono/physics/ChSystemNSC.h>
#include <chrono/physics/ChBody.h>


namespace kinetis {
    class Simulation {
    public:
        Simulation();

        Simulation(chrono::ChVector3d gacc);

        ~Simulation() = default;

        void step(double dT, double t);

        void addBody(std::shared_ptr<chrono::ChBody> body);

        double getSimTime() const;

    private:
        chrono::ChSystemNSC _systemNCS;
    };
};
