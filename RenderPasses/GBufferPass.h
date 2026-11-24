//
// Created by Hayden Chalin on 11/15/26.
//

#pragma once
#include <MetalKit/MetalKit.hpp>

#include "RenderPass.h"


namespace kinetis {

class GBufferPass final :public RenderPass{
public:
     explicit GBufferPass(MTK::View* view);
     void draw(MTL::CommandBuffer *, Scene& scene, Uniforms& uniforms, Params& params) override;
     /**
     * @brief Resizes the G-buffer render targets.
     *
     * Recreates the albedo, normal, position, and depth
     * textures to match the Metal view's drawable size.
     */
     void resize(MTK::View* view, CGSize size) override;

private:
     // * Textures
     NS::SharedPtr<MTL::Texture> _albedoTexture;
     NS::SharedPtr<MTL::Texture> _normalTexture;
     NS::SharedPtr<MTL::Texture> _positionTexture;

     // * PSO Descriptor
     NS::SharedPtr<MTL::RenderPassDescriptor> _renderPassDescriptor;
     NS::SharedPtr<MTL::RenderPipelineState> _PSO;
     NS::SharedPtr<MTL::DepthStencilState> _depthStencilState;
     const std::string _label;

};
}
