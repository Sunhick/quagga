//  Copyright © 2018 Sunil. All rights reserved.

#pragma once

#include <functional>
#include <string>

namespace quagga {

class Component {
 public:
  virtual std::string to_string();
};  // class Component

using ComponentMaker = std::function<std::shared_ptr<Component>()>;

}  // namespace quagga
