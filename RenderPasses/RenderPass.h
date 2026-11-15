//
// Created by Hayden Chalin on 11/15/26.
//

#pragma once

#include <Metal/Metal.hpp>
#include <MetalKit/MetalKit.hpp>


// TODO: Remove forward declarations once created.
class Scene;
struct Uniforms;
struct Params;

/**
 * @class RenderPass
 * @brief Pure ABC, derive from this class when creating a new Render Pass
 *
 * This is an interface
 */
class RenderPass {
public:
    virtual ~RenderPass() = default;

    virtual void resize() = 0;
    virtual void draw(MTL::CommandBuffer*, Scene& scene, Uniforms& uniforms, Params& params) = 0;


private:

protected:
    // Constructor
    explicit RenderPass(MTK::View* view): _pView(view){};
    MTK::View* _pView;
    const std::string label;
};
