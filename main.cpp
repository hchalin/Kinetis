#include <iostream>

#include "App/KinetisAppDelegate.h"
#include <objc/runtime.h>

int main() {
    // Obj-c runtime experiment
    Class assetClass = objc_getClass("MDLAsset");
    if (assetClass)
        std::cout << "MDLAsset Found!" << std::endl;

    NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();
    KinetisAppDelegate appDelegate;
    NS::Application* app = NS::Application::sharedApplication();
    app->setDelegate(&appDelegate);
    app->run();
    pool->release();
    return 0;
}
