#include <chrono>
#include <list>
#include <string>

#include "common/config/well_known_names.h"
#include "common/json/json_loader.h"

#include "strategy_host/ctp_preinsert.h"

#include "extensions/stat_sinks/well_known_names.h"

#include "test/common/upstream/utility.h"
#include "test/mocks/common.h"
#include "test/mocks/network/mocks.h"
#include "test/mocks/server/mocks.h"
#include "test/test_common/environment.h"
#include "test/test_common/utility.h"

#include "fmt/printf.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;

namespace Envoy {
namespace StrategyHost {

class CppPreInsertTest : public testing::Test {
protected:
  CppPreInsertTest()
      : api_(Api::createApiForTest()),
        cluster_manager_factory_(server_.admin(), server_.runtime(), server_.stats(),
                                 server_.threadLocal(), server_.random(), server_.dnsResolver(),
                                 server_.sslContextManager(), server_.dispatcher(),
                                 server_.localInfo(), server_.secretManager(),
                                 server_.messageValidationContext(), *api_, server_.httpContext(),
                                 server_.accessLogManager(), server_.singletonManager()) {}

  Api::ApiPtr api_;
  NiceMock<Server::MockInstance> server_;
  Upstream::ProdClusterManagerFactory cluster_manager_factory_;
};

TEST_F(CppPreInsertTest, LoopInterval) {
  envoy::config::bootstrap::v2::Bootstrap bootstrap;

  CtpPreInsertTrader trader;
  trader.switchFlagRunning();
  trader.monitorScheduledOrder();

  EXPECT_EQ(std::chrono::milliseconds(5000), config.statsFlushInterval());
}

} // namespace Server
} // namespace Envoy
