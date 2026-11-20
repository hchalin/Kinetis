//
// Created by Hayden Chalin on 11/3/26.
//

#pragma once

#include <AppKit/AppKit.hpp>
#include <Metal/Metal.hpp>
#include <MetalKit/MetalKit.hpp>
#include <memory>

#include "../View/KinetisViewDelegate.h"
#include "Simulation/Simulation.h"

class KinetisAppDelegate : public NS::ApplicationDelegate {
public:
    virtual ~KinetisAppDelegate();
    void applicationDidFinishLaunching(NS::Notification *pNotification) override;
    void applicationWillFinishLaunching(NS::Notification *pNotification) override;
    bool applicationShouldTerminateAfterLastWindowClosed(NS::Application *pSender) override;
private:
    NS::SharedPtr<NS::Window> _window;
    NS::SharedPtr<MTK::View> _view;
    NS::SharedPtr<MTL::Device> _device;
    kinetis::Simulation _simulation;
    std::unique_ptr<KinetisViewDelegate> _viewDelegate;
};
