//
// Created by Hayden Chalin on 11/3/26.
//

#include <chrono>

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
      _simulation(sim),
      _accumulator(0.0),
      _dT(1.0 / 120.0),
      _t(0.0)

{
    using namespace std::chrono;

    _startTime = steady_clock::now();

    // std::chrono::steady_clock clock;
    // auto now = clock.now();
    // std::cout << "Time since epoch: " << start << std::endl;
    // auto startMs = duration_cast<milliseconds>(start);
}

KinetisViewDelegate::~KinetisViewDelegate() {

}

void KinetisViewDelegate::drawableSizeWillChange(MTK::View *pView, CGSize size) {

}

// https://www.gafferongames.com/post/fix_your_timestep/
void KinetisViewDelegate::drawInMTKView(MTK::View *pView) {
    using namespace std::chrono;

    const auto newTime = steady_clock::now();

    const duration<double> elapsed = newTime - _startTime;
    double frameTime = elapsed.count();

    if (frameTime >= 0.025)
        frameTime = 0.025;
    _startTime = newTime;

    _accumulator += frameTime;

    while (_accumulator >= _dT) {
        _simulation.step(_dT);
        _accumulator -= _dT;
        _t += _dT;
    }

    std::cout << "Frame time: " << frameTime << std::endl;
    _pRenderer->draw(pView);
}



