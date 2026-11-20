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
      _dT(0.01), t(0.0)

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

    auto newTime = steady_clock::now();
    auto frameTime = static_cast<double>(duration_cast<milliseconds>(newTime - _startTime).count());
    if (frameTime > 25)
        frameTime = 25;
    _startTime = newTime;

    _accumulator += frameTime;

    while (_accumulator >= _dT) {
        _simulation.step(_dT, t);
        _accumulator -= _dT;
        t += _dT;
    }

    // _simulation.step()
    // std::cout << "Frame time: " << frameTime << std::endl;
    _pRenderer->draw(pView);
}



