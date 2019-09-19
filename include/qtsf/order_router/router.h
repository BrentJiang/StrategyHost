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
 * A Router serializes Orders via data flow and will 
 * ensure return status in strict order.
 */
class Router {
public:
  virtual ~Router() = default;
};

using RouterPtr = std::unique_ptr<Router>;

/**
 * A Router transfer order directly to exchanges' API.
 */
class DirectRouter {
public:
  virtual ~DirectRouter() = default;
};

using DirectRouterPtr = std::unique_ptr<DirectRouter>;

} // namespace OrderRouter
} // namespace Qtsf
