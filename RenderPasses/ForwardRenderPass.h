//
// Created by Hayden Chalin on 11/24/26.
//

#pragma once

#include "RenderPass.h"

namespace kinetis {
    class ForwardRenderPass final : public RenderPass {
    public:
        ForwardRenderPass(MTK::View* view);
        const std::string label = "Forward Render Pass";
        /**
         *      Add the following:
         *      ShadowTexture
         *      RP Descriptor
         *      Pipeline state
         */
        void draw(MTL::CommandBuffer *, Scene &scene, Uniforms &uniforms, Params &params) override{};
        void resize(MTK::View *view, CGSize size) override {};

    };
} // kinetis