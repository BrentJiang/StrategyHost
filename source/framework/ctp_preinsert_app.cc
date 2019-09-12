#include "strategy_host/ctp_preinsert.h"

#include "absl/debugging/symbolize.h"

int main(int argc, char** argv)
{
  (void)argc;
#ifndef __APPLE__
  // absl::Symbolize mostly works without this, but this improves corner case
  // handling, such as running in a chroot jail.
  absl::InitializeSymbolizer(argv[0]);
#endif

  Envoy::StrategyHost::CtpPreInsertTrader trader(argc, argv);
  trader.switchFlagRunning();
  trader.monitorScheduledOrder();

  return 0;
}