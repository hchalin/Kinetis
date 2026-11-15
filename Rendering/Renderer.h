//
// Created by Hayden Chalin on 11/5/26.
//

#pragma once

#include <Metal/Metal.hpp>
#include <MetalKit/MetalKit.hpp>

class Renderer final {
public:
    explicit Renderer(MTL::Device *pDevice);
    ~Renderer();
    void draw(MTK::View* pView);
private:
    MTL::Device* _pDevice;
    NS::SharedPtr<MTL::CommandQueue> _commandQueue;

};