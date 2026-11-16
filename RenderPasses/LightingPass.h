//
// Created by Hayden Chalin on 11/15/26.
//

#pragma once
#include "RenderPass.h"

// TODO: Remove forward declarations once created.
class Scene;
struct Uniforms;
struct Params;

class LightingPass final : public RenderPass{
public:
    explicit LightingPass(MTK::View* view);
    // ~LightingPass() override;
    void draw(MTL::CommandBuffer *, Scene& scene, Uniforms& uniforms, Params& params) override;
    void resize() override;

private:
    // * PSO Descriptor
    NS::SharedPtr<MTL::RenderPassDescriptor> _renderPassDescriptor;
    NS::SharedPtr<MTL::RenderPipelineState> _PSO;
    NS::SharedPtr<MTL::DepthStencilState> _depthStencilState;
    const std::string _label;
};

