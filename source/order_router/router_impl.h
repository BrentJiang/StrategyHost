#pragma once

#include <functional>
#include <limits>
#include <memory>
#include <string>

#include "qtsf/order_router/router.h"
#include "qtsf/order_router/adapter.h"

using namespace Envoy;


namespace Qtsf {
namespace OrderRouter {

/**
 * A Router serializes Orders via data flow and will 
 * ensure return status in strict order.
 */
class RouterImpl : public Router {
public:
  virtual ~RouterImpl() = default;
};

using RouterImplPtr = std::unique_ptr<RouterImpl>;

/**
 * A Router transfer order directly to exchanges' API.
 */
class DirectRouterImpl {
public:
  virtual ~DirectRouterImpl() = default;
};

using DirectRouterImplPtr = std::unique_ptr<DirectRouterImpl>;

} // namespace OrderRouter
} // namespace Qtsf
