//  Copyright © 2018 Sunil. All rights reserved.

namespace quagga {

template <class T>
void Container::Register(std::shared_ptr<Component> instance) {
  instances[typeid(T)] = instance;
}

template <class T>
std::shared_ptr<T> Container::Resolve() {
  auto instance = instances[typeid(T)];
  return std::dynamic_pointer_cast<T>(instance);
}

template <typename T>
void Container::Register(ComponentMaker creator) {
  // No op for now
}

}  // namespace quagga
