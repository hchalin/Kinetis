//
// Created by Hayden Chalin on 11/15/26.
//

#pragma once
#include "RenderPass.h"

namespace kinetis {

class LightingPass final : public RenderPass{
public:
    explicit LightingPass(MTK::View* view);

    void draw(MTL::CommandBuffer *, Scene& scene, Uniforms& uniforms, Params& params) override;
    void resize(MTK::View* view, CGSize size) override;

private:
    // * PSO Descriptor
    NS::SharedPtr<MTL::RenderPassDescriptor> _renderPassDescriptor;
    NS::SharedPtr<MTL::RenderPipelineState> _PSO;
    NS::SharedPtr<MTL::DepthStencilState> _depthStencilState;
    const std::string _label;
};

}
