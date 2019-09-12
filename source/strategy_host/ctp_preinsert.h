#pragma once

#include <cstdint>
#include <unordered_map>
#include <mutex>
#include <memory>

#include "common/common/logger.h"

#include "server/options_impl.h"

namespace Envoy {
namespace StrategyHost {
struct FutureOrder
{
    uint32_t order_id;
    uint64_t trigger_time;
};

using FutureOrderSharedPtr = std::shared_ptr<FutureOrder>;

class CtpPreInsertTrader : public Logger::Loggable<Logger::Id::config>
{
public:
    CtpPreInsertTrader(int argc, const char* const* argv);
    void monitorScheduledOrder();
    void switchFlagRunning();
    FutureOrderSharedPtr getScheduledOrder(uint32_t scheduled_order_id);
    void insertOrder(FutureOrderSharedPtr order);

    static std::string hotRestartVersion(bool hot_restart_enabled);

private:
    Envoy::OptionsImpl options_;
    Event::RealTimeSystem real_time_system_;
    std::unordered_map<uint32_t, FutureOrderSharedPtr> test_map_;
    std::mutex mtx_orderbook_;
    bool flag_running_;
};
} // namespace StrategyHost
} // namespace Envoy