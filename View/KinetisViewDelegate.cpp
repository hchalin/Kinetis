//
// Created by Hayden Chalin on 11/3/26.
//


#include "KinetisViewDelegate.h"

KinetisViewDelegate::KinetisViewDelegate(MTL::Device *pDevice, kinetis::Simulation& sim)
    : MTK::ViewDelegate(),
      _pRenderer(std::make_unique<Renderer>(pDevice)),
      _simulation(sim), _scheduler(sim)

{
    using namespace std::chrono;
}

KinetisViewDelegate::~KinetisViewDelegate() {

}

void KinetisViewDelegate::drawableSizeWillChange(MTK::View *pView, CGSize size) {

}

void KinetisViewDelegate::drawInMTKView(MTK::View *pView) {

    _scheduler.timeStep();

    _pRenderer->draw(pView);
}



