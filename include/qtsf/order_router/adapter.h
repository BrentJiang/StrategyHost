#pragma once

#include <functional>
#include <limits>
#include <memory>
#include <string>

#include "envoy/common/pure.h"

using namespace Envoy;


namespace Qtsf {
namespace OrderRouter {

/**
 * An Adapter transfer structs from QTSF to exchanges' API.
 */
class Adapter {
public:
  virtual ~Adapter() = default;
};

using AdapterPtr = std::unique_ptr<Adapter>;

} // namespace OrderRouter
} // namespace Qtsf
