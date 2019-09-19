#pragma once

#include "qtsf/order_router/adapter.h"

using namespace Envoy;


namespace Qtsf {
namespace OrderRouter {

/**
 * A CtpAdapter transfer order to CTP.
 */
class CtpAdapter : public Adapter {
public:
  virtual ~CtpAdapter() = default;
  virtual int sendOrder(OrderReqPtr& orderReq);
};

using CtpAdapterPtr = std::unique_ptr<CtpAdapter>;

} // namespace OrderRouter
} // namespace Qtsf
