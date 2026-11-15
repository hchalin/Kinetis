//
// Created by Hayden Chalin on 11/15/26.
//

#include "GBufferPass.h"

GBufferPass::GBufferPass(MTK::View *view) : RenderPass(view),
    _label("G-Buffer Render Pass")
{

}
void GBufferPass::resize() {

}

void GBufferPass::draw(MTL::CommandBuffer *, Scene &scene, Uniforms &uniforms, Params &params) {

}


