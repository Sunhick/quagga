//  Copyright © 2018 Sunil. All rights reserved.

#include <sstream>

#ifdef __GNUG__
#include <cxxabi.h>
#include <cstdlib>
#include <memory>

struct handle {
  char* p;
  handle(char* ptr) : p(ptr) {}
  ~handle() { std::free(p); }
};

std::string demangle(const char* name) {
  int status = -4;
  handle result(abi::__cxa_demangle(name, NULL, NULL, &status));
  return (status == 0) ? result.p : name;
}

#else

// does nothing if not g++
std::string demangle(const char* name) {
  return name;
}

#endif

namespace quagga {

template <class T>
void Container::Register(std::shared_ptr<Component> instance) {
  instances[typeid(T)] = instance;
}

template <class T>
std::shared_ptr<T> Container::Resolve() {
  const auto& index = typeid(T);
  if (auto found = instances.find(index); found != instances.end()) {
    // found a valid instance registered.
    // auto instance = instances[typeid(T)];
    return std::dynamic_pointer_cast<T>(found->second);
  }

  if (auto registration = registrations.find(index);
      registration != registrations.end()) {
    // found a registration for creating the instance
    auto instance = registration->second();
    instances[index] = instance;
    return std::dynamic_pointer_cast<T>(instance);
  }

  std::ostringstream stream;
  stream << "unable to resolve the type: " << demangle(typeid(T).name());
  std::string error = stream.str();
  throw std::invalid_argument(error);
}

template <typename T>
void Container::Register(ComponentMaker creator) {
  registrations[typeid(T)] = creator;
}

}  // namespace quagga
