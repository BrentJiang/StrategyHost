licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_binary",
    "envoy_cc_library",
    "envoy_cc_platform_dep",
    "envoy_cc_posix_library",
    "envoy_cc_win32_library",
    "envoy_google_grpc_external_deps",
    "envoy_package",
)
load(
    "//source/extensions:all_extensions.bzl",
    "envoy_all_extensions",
    "envoy_windows_extensions",
)
load("//bazel:repositories.bzl", "NOBORINGSSL_SKIP_TARGETS", "PPC_SKIP_TARGETS")

envoy_package()

alias(
    name = "framework",
    actual = ":framework-static",
)

envoy_cc_binary(
    name = "framework-static",
    stamped = True,
    deps = ["framework_main_entry_lib"],
)

envoy_cc_library(
    name = "framework_common_lib",
    deps = [
        "//source/common/event:libevent_lib",
        "//source/common/network:utility_lib",
        "//source/common/stats:stats_lib",
        "//source/common/stats:thread_local_store_lib",
        "//source/server:drain_manager_lib",
        "//source/server:options_lib",
        "//source/server:listener_hooks_lib",
        "//source/strategy_host:strategy_host_lib",
    ] + select({
        "//bazel:windows_x86_64": envoy_windows_extensions(),
        "//bazel:linux_ppc": envoy_all_extensions(PPC_SKIP_TARGETS),
        "//bazel:boringssl_disabled": envoy_all_extensions(NOBORINGSSL_SKIP_TARGETS),
        "//conditions:default": envoy_all_extensions(),
    }),
)

envoy_cc_library(
    name = "framework_main_entry_lib",
    srcs = ["framework.cc"],
    external_deps = [
        "abseil_symbolize",
    ],
    deps = [
        ":main_framework_lib",
        "//source/exe:platform_impl_lib",
    ],
)

envoy_cc_library(
    name = "main_framework_lib",
    srcs = ["main_framework.cc"],
    hdrs = ["main_framework.h"],
    deps = [
        ":framework_common_lib",
        "//source/exe:platform_impl_lib",
        "//source/exe:process_wide_lib",
        "//source/common/api:os_sys_calls_lib",
        "//source/common/common:compiler_requirements_lib",
        "//source/common/common:perf_annotation_lib",
        "//source/common/stats:symbol_table_creator_lib",
        "//source/server:hot_restart_lib",
        "//source/server:hot_restart_nop_lib",
        "//source/server/config_validation:server_lib",
        "//source/strategy_host:strategy_host_lib",
    ] + select({
        "//bazel:disable_signal_trace": [],
        "//conditions:default": [
            "//source/common/signal:sigaction_lib",
            "//source/exe:terminate_handler_lib",
        ],
    }),
)
