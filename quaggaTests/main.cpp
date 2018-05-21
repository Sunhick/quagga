//  Copyright © 2018 Sunil. All rights reserved.

#include <iostream>

#include "Container.hpp"
#include "Component.hpp"

class Foo : public quagga::Component {
public:
    ~Foo() {
        std::cout << "Foo destroyed" << std::endl;
    }
    
    void print() {
        std::cout << "Foo -- print function" << std::endl;
    }
};

class Bar : public quagga::Component {
public:
    ~Bar() {
        std::cout << "Bar destroyed" << std::endl;
    }
    
    void print() {
        std::cout << "Bar -- print function" << std::endl;
    }
};

class FooBar : public quagga::Component {
public:
    ~FooBar() {
        std::cout << "FooBar destroyed" << std::endl;
    }
    
    void print() {
        std::cout << "FooBar -- print function" << std::endl;
    }
};


int main(int argc, const char * argv[]) {
    quagga::Container container;
    
    auto foo = std::make_shared<Foo>();
    container.Register<Foo>(foo);
    
    auto copyFoo = container.Resolve<Foo>();
    copyFoo->print();
    
    container.Register<Bar>([]() {
        return std::make_shared<Bar>();
    });
    
    auto copyBar = container.Resolve<Bar>();
    copyBar->print();
    
    auto error = container.Resolve<FooBar>();
    
    std::cout << "Hello World!" << std::endl;
    return 0;
}
