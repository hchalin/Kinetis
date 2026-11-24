cmake_minimum_required(VERSION 3.20)
project(Kinetis LANGUAGES CXX OBJCXX)

if(NOT APPLE)
    message(FATAL_ERROR "Kinetis requires macOS and Apple Metal frameworks.")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

add_executable(Kinetis
    main.cpp
        App/KinetisAppDelegate.cpp
        App/KinetisAppDelegate.h
        View/KinetisViewDelegate.cpp
        View/KinetisViewDelegate.h
        Backend/MetalCppImplementation.cpp
        Rendering/Renderer.cpp
        Rendering/Renderer.h
        RenderPasses/GBufferPass.cpp
        RenderPasses/GBufferPass.h
        RenderPasses/LightingPass.cpp
        RenderPasses/LightingPass.h
        RenderPasses/RenderPass.h
        View/Scheduler.cpp
        View/Scheduler.h
        RenderPasses/ForwardRenderPass.cpp
        RenderPasses/ForwardRenderPass.h
)

# Chrono test
find_package(Chrono REQUIRED CONFIG)
message(STATUS "Chrono found at: ${Chrono_DIR}")
message(STATUS "Chrono targets: ${CHRONO_TARGETS}")


########
# Add Simluation as a static library
########
add_library(KinetisSimulation STATIC
        Simulation/Simulation.h
        Simulation/Simulation.cpp
)

target_include_directories(KinetisSimulation PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(KinetisSimulation PUBLIC
    ${CHRONO_TARGETS}
)
########

# Original physics smoke test
add_executable(KinetisPhysicsTest
        Simulation/PhysicsSmokeTest.cpp
)

target_link_libraries(KinetisPhysicsTest PRIVATE
        KinetisSimulation
)

# Google Test executable
add_executable(KinetisUnitTests
        Tests/SimulationTests.cpp
        View/Scheduler.cpp
)

target_include_directories(KinetisUnitTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(KinetisUnitTests PRIVATE
        GTest::gtest_main
        KinetisSimulation
)

include(GoogleTest)

gtest_discover_tests(KinetisUnitTests)

# Pre compile shaders
# Process the Shaders directory
add_subdirectory(Shaders)

# Ensure Metal shaders are built with Aluminum
add_dependencies(Kinetis KinetisShaders)

# Provide compiled shader library path to C++
target_compile_definitions(Kinetis PRIVATE
        KINETIS_METALLIB_PATH=\"${KINETIS_METALLIB}\"
)

target_include_directories(Kinetis PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Backend/metal-cpp
)



target_link_libraries(Kinetis PRIVATE
        "-framework Metal"
        "-framework Foundation"
        "-framework QuartzCore"
        "-framework AppKit"
        "-framework MetalKit"
        "-framework ModelIO"
        KinetisSimulation
)
