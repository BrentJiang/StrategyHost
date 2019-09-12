licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_package",
)
load(
    "//source/extensions:all_extensions.bzl",
    "envoy_all_extensions",
    "envoy_windows_extensions",
)
load("//bazel:repositories.bzl", "NOBORINGSSL_SKIP_TARGETS", "PPC_SKIP_TARGETS")

envoy_package()

envoy_cc_library(
    name = "ctp_preinsert_lib",
    srcs = ["ctp_preinsert.cc"],
    hdrs = ["ctp_preinsert.h"],
    external_deps = [
        "abseil_node_hash_map",
        "abseil_optional",
    ],
    deps = [
        "//source/server:options_lib",
        "//source/common/common:logger_lib",
        "//source/common/common:minimal_logger_lib",
        "//source/common/common:linked_object",
        "//source/common/event:real_time_system_lib",
    ],
)

envoy_cc_library(
    name = "strategy_host_lib",
    srcs = ["strategy_host.cc"],
    hdrs = ["strategy_host.h"],
    external_deps = [
        "abseil_node_hash_map",
        "abseil_optional",
    ],
    deps = [
        "//source/server:configuration_lib",
        "//source/server:connection_handler_lib",
        "//source/server:guarddog_lib",
        "//source/server:listener_hooks_lib",
        "//source/server:listener_manager_lib",
        "//source/server:ssl_context_manager_lib",
        "//source/server:worker_lib",
        "//include/envoy/event:dispatcher_interface",
        "//include/envoy/event:signal_interface",
        "//include/envoy/event:timer_interface",
        "//include/envoy/network:dns_interface",
        "//include/envoy/server:drain_manager_interface",
        "//include/envoy/server:instance_interface",
        "//include/envoy/server:listener_manager_interface",
        "//include/envoy/server:options_interface",
        "//include/envoy/server:process_context_interface",
        "//include/envoy/stats:stats_macros",
        "//include/envoy/tracing:http_tracer_interface",
        "//include/envoy/upstream:cluster_manager_interface",
        "//source/common/access_log:access_log_manager_lib",
        "//source/common/api:api_lib",
        "//source/common/buffer:buffer_lib",
        "//source/common/common:cleanup_lib",
        "//source/common/common:logger_lib",
        "//source/common/common:mutex_tracer_lib",
        "//source/common/common:utility_lib",
        "//source/common/common:version_lib",
        "//source/common/config:utility_lib",
        "//source/common/grpc:async_client_manager_lib",
        "//source/common/grpc:context_lib",
        "//source/common/http:codes_lib",
        "//source/common/http:context_lib",
        "//source/common/init:manager_lib",
        "//source/common/local_info:local_info_lib",
        "//source/common/memory:heap_shrinker_lib",
        "//source/common/memory:stats_lib",
        "//source/common/protobuf:utility_lib",
        "//source/common/router:rds_lib",
        "//source/common/runtime:runtime_lib",
        "//source/common/secret:secret_manager_impl_lib",
        "//source/common/singleton:manager_impl_lib",
        "//source/common/stats:symbol_table_creator_lib",
        "//source/common/stats:thread_local_store_lib",
        "//source/common/upstream:cluster_manager_lib",
        "//source/common/upstream:health_discovery_service_lib",
        "//source/server:overload_manager_lib",
        "//source/server/http:admin_lib",
        "//source/server:server_lib",
        "@envoy_api//envoy/config/bootstrap/v2:bootstrap_cc",
    ],
)
