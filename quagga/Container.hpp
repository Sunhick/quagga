//  Copyright © 2018 Sunil. All rights reserved.

#include <map>
#include <memory>
#include <typeindex>

#include "Component.hpp"

namespace quagga {

class Container {
 private:
  std::map<std::type_index, ComponentMaker> registrations;
  std::map<std::type_index, std::shared_ptr<Component>> instances;

 public:
  template <class T>
  void Register(std::shared_ptr<Component> instance);

  template <typename T>
  void Register(ComponentMaker creator);

  template <class T>
  std::shared_ptr<T> Resolve();
};

}  // namespace quagga

#include "Container.cpp"
