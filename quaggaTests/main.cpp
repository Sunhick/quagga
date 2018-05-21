//  Copyright © 2018 Sunil. All rights reserved.

#include <iostream>

#include "Container.hpp"
#include "Component.hpp"

class Foo : public quagga::Component {
public:
    void print() {
        std::cout << "Foo -- print function" << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    quagga::Container container;
    
    auto foo = std::make_shared<Foo>();
    container.Register<Foo>(foo);
    
    auto copyFoo = container.Resolve<Foo>();
    copyFoo->print();
    
    container.Register<Foo>([]() {
        return std::make_shared<Foo>();
    });
    
    std::cout << "Hello World!" << std::endl;
    return 0;
}
