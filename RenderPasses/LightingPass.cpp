//
// Created by Hayden Chalin on 11/15/26.
//

#include "LightingPass.h"

namespace kinetis {


LightingPass::LightingPass(MTK::View *view): RenderPass(view),
    _label("Lighting Render Pass")
{

}

//
void LightingPass::resize(MTK::View* view, CGSize size) {

}


void LightingPass::draw(MTL::CommandBuffer *, Scene &scene, Uniforms &uniforms, Params &params) {

}

}
