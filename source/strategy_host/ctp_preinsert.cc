#include "strategy_host/ctp_preinsert.h"

#include <cstdint>
#include <memory>
#include <thread>
#include <mutex>

#include "common/common/assert.h"
#include "common/common/linked_object.h"

#include "absl/strings/str_cat.h"

namespace Envoy {
namespace StrategyHost {

uint64_t getCurTimestampMicro() {
  uint64_t timeResult;

  struct timeval localTime;
  struct tm *p;
  gettimeofday(&localTime, 0);
  p = localtime(&localTime.tv_sec);
  timeResult = static_cast<uint64_t>(p->tm_hour) * 10000000000;
  // LOGI("timeResult: " << timeResult << "tm_hour: " << p->tm_hour);
  timeResult += static_cast<uint64_t>(p->tm_min) * 100000000;
  // LOGI("timeResult: " << timeResult << "tm_min: " << p->tm_min);
  timeResult += static_cast<uint64_t>(p->tm_sec) * 1000000;
  // LOGI("timeResult: " << timeResult << "tm_sec: " << p->tm_sec);
  timeResult += localTime.tv_usec;
  // LOGI("timeResult: " << timeResult << "localTime.tv_usec: " << localTime.tv_usec);

  return timeResult;
}

CtpPreInsertTrader::CtpPreInsertTrader(int argc, const char* const* argv)
  : options_(argc, argv, &CtpPreInsertTrader::hotRestartVersion, spdlog::level::info),
    flag_running_(false)
{
}

std::string CtpPreInsertTrader::hotRestartVersion(bool hot_restart_enabled) {
#ifdef ENVOY_HOT_RESTART
  if (hot_restart_enabled) {
    return Server::HotRestartImpl::hotRestartVersion();
  }
#else
  UNREFERENCED_PARAMETER(hot_restart_enabled);
#endif
  return "disabled";
}

void CtpPreInsertTrader::switchFlagRunning()
{
    flag_running_ = !flag_running_;
}

// 测试
FutureOrderSharedPtr CtpPreInsertTrader::getScheduledOrder(uint32_t scheduled_order_id) {
    auto it = test_map_.find(scheduled_order_id);
    if (it == test_map_.cend()) {
        return nullptr;
    }

    return it->second;
}

void CtpPreInsertTrader::insertOrder(FutureOrderSharedPtr order)
{
    test_map_.insert(std::make_pair(order->order_id, order));
}

void CtpPreInsertTrader::monitorScheduledOrder()
{
  uint64_t delta = 5000; // micro-seconds
  uint64_t trigger_time;
  uint64_t cur_ts;
  while (true) {
    // 当策略开启标志位时候才去发单
    // LOGI("开始判断是否需要发单");

    // LOGI("flag_running_: " << flag_running_);
    if (flag_running_) {
      // 当前时间 + 提前量 >= trigger_time 时候进行发单
      std::lock_guard<std::mutex> lock(mtx_orderbook_);
      FutureOrderSharedPtr fo = getScheduledOrder(1);

      // delta time: 5000microseonds = 5ms

      if (fo) {
        cur_ts = getCurTimestampMicro();
        // Micro seconds
        trigger_time = static_cast<uint64_t>(fo->trigger_time) * 1000;
        ENVOY_LOG(info, "current ts: {}, current ts + delta: {}, trigger_time: {}",
        cur_ts, cur_ts + delta, trigger_time);
      }
    }
  }
}

} // namespace StrategyHost
} // namespace Envoy