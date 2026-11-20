//
// Created by Hayden Chalin on 11/3/26.
//

#pragma once
#include <memory>
#include <MetalKit/MetalKit.hpp>

// File includes
#include "MetalKit/MTKView.hpp"
#include "../Rendering/Renderer.h"
#include "Simulation/Simulation.h"


class Renderer;

class KinetisViewDelegate : public MTK::ViewDelegate {
public:
    KinetisViewDelegate(MTL::Device* pDevice, kinetis::Simulation& sim);
    virtual ~KinetisViewDelegate() override;
    virtual void drawableSizeWillChange(class MTK::View *pView, CGSize size) override;
    virtual void drawInMTKView(class MTK::View *pView) override;
private:
    // class Renderer* _pRenderer;
    std::unique_ptr<Renderer> _pRenderer;
    kinetis::Simulation& _simulation;

    std::chrono::time_point<std::chrono::steady_clock> _startTime;
    double _accumulator;
    double _dT;
    double t;
};
