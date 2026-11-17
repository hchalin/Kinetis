
# Rough development checklist

## Milestone 0: Renderer Foundation

## GitHub
- [ ] Need a README
  - [ ] Create some basic documentation on how to build/run project.
- [ ] Project Chrono links to my locally built library. Fix this for anyone cloning the repo.

### Application and Metal Setup
- [x] Create native AppKit window
- [x] Initialize MTL::Device
- [x] Configure MTK::View
- [x] Implement view delegate
- [x] Create command queue
- [x] Implement basic frame rendering loop

### Shader System
- [x] Configure CMake shader compilation
- [ ] Verify generated Kinetis.metallib
- [ ] Load metallib using MTL::Device::newLibrary()
- [ ] Retrieve vertex and fragment functions
- [ ] Implement shader loading error handling

### Geometry and GPU Data
- [ ] Define vertex structure (position, normal, UV)
- [ ] Create basic cube geometry (a Primitive class would be nice)
- [ ] Create a vertex buffer
- [ ] Create an index buffer
- [ ] Define shared CPU/GPU uniforms
- [ ] Define Params for shaders customization (light count, exposure, etc...)
- [ ] Create model, view, projection matrices
- [ ] Implement basic camera 
- [ ] Camera controls (Use AppKit, this needs to inhearit a Movement interface, look at 'Aluminum v0 for references)
  - Note: 'anything' should be able to move.

### Render Pass Architecture
- [x] Create RenderPass abstract base class
- [ ] Create a ShaderPass class
- [x] Create a GBufferPass class
- [x] Create a LightingPass class
- [ ] Define render pass initialization
- [ ] Establish resource ownership
- [ ] Connect passes to Renderer
- [ ] Forward drawable size changes to passes
- [ ] Decide G-buffer attachment formats

### Debugging
- [ ] Add G-buffer visualizer (radio buttons or segmented control)
- [ ] Verify albedo, normal, position, and depth attachments
- [ ] Test resizing the window
- [ ] Capture and inspect GPU frames in Xcode
- [ ] Add Metal resource labels for easier debugging
- [ ] Add GPU validation and error reporting 

### Unit Testing
- [ ] Integrate GoogleTest with CMake
- [ ] Create a separate KinetisTests target
- [ ] Test camera math and transformation matrices
- [ ] Test vertex and uniform structure layouts
- [ ] Test scene data and resource management
- [ ] Investigate C++20 Concepts for type constraints

## Milestone 1: Deferred Rendering

### G-Buffer Pass
- [ ] Create albedo texture
- [ ] Create normal texture
- [ ] Create position texture
- [ ] Create depth texture
- [ ] Configure render pass descriptor
- [ ] Create geometry render pipeline state
- [ ] Create depth stencil state
- [ ] Implement resize handling
- [ ] Render cube into G-buffer

### Lighting Pass
- [ ] Provide G-buffer textures to lighting pass
- [ ] Create lighting render pipeline state
- [ ] Implement fullscreen triangle
- [ ] Sample G-buffer textures
- [ ] Output albedo to drawable
- [ ] Implement directional lighting
- [ ] Implement point lights



