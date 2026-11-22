//
// Created by Hayden Chalin on 11/3/26.
//


#include "KinetisViewDelegate.h"

/*
 * Constructor
 */

// {
//     using namespace std::chrono;
//
//     auto start = steady_clock::now();
//
//     // ... code to measure ...
//
//     auto end = steady_clock::now();
//     auto elapsed = duration_cast<milliseconds>(end - start);
//
//     std::cout << elapsed.count() << " ms\n";
// }
KinetisViewDelegate::KinetisViewDelegate(MTL::Device *pDevice, kinetis::Simulation& sim)
    : MTK::ViewDelegate(),
      _pRenderer(std::make_unique<Renderer>(pDevice)),
      _simulation(sim), _scheduler(sim),
      _accumulator(0.0),
      _dT(1.0 / 120.0)

{
    using namespace std::chrono;
    _startTime = steady_clock::now();
}

KinetisViewDelegate::~KinetisViewDelegate() {

}

void KinetisViewDelegate::drawableSizeWillChange(MTK::View *pView, CGSize size) {

}

void KinetisViewDelegate::drawInMTKView(MTK::View *pView) {

    _scheduler.timeStep();

    _pRenderer->draw(pView);
}



