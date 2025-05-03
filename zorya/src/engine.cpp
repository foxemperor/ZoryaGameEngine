#include <iostream>
#include "engine.h"

namespace zorya
{
    int Add(int a, int b)
    {
        return a + b;
    }

    void GetInfo()
    {
#ifdef ZORYAENGINE_CONFIG_DEBUG
       std::cout << "Configuration: DEBUG" << std::endl; 
#endif
#ifdef ZORYAENGINE_CONFIG_RELEASE
       std::cout << "Configuration: RELEASE" << std::endl; 
#endif

#ifdef ZORYAENGINE_PLATFORM_WINDOWS
       std::cout << "For platform: WINDOWS" << std::endl; 
#endif
#ifdef ZORYAENGINE_PLATFORM_LINUX
       std::cout << "For platform: LINUX" << std::endl; 
#endif
#ifdef ZORYAENGINE_PLATFORM_MAC
       std::cout << "For platform: MACOSX" << std::endl; 
#endif
    }

}

