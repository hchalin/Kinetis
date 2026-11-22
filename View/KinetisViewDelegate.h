//
// Created by Hayden Chalin on 11/3/26.
//

#pragma once
#include <memory>
#include <chrono>
#include <MetalKit/MetalKit.hpp>

// File includes
#include "Scheduler.h"
#include "MetalKit/MTKView.hpp"
#include "../Rendering/Renderer.h"
#include "Simulation/Simulation.h"


class Renderer;

class KinetisViewDelegate : public MTK::ViewDelegate {
public:
    KinetisViewDelegate(MTL::Device* pDevice, kinetis::Simulation& sim);
    ~KinetisViewDelegate() override;
    void drawableSizeWillChange(class MTK::View *pView, CGSize size) override;
    void drawInMTKView(class MTK::View *pView) override;
private:
    std::unique_ptr<Renderer> _pRenderer;
    kinetis::Simulation& _simulation;

    // This schedular is in charge of controlling the render loop between the physics and render engine
    kinetis::Scheduler _scheduler;

    std::chrono::time_point<std::chrono::steady_clock> _startTime;
    double _accumulator;
    double _dT;
};
