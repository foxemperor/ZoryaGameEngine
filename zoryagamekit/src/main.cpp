#include <iostream>
#include "engine/engine.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    zorya::GetInfo();
    int a = zorya::Add(10, 5);
    int b = zorya::Sub(10, 5);
    std::cout << a << ", " << b << std::endl;

    return 0;
}
