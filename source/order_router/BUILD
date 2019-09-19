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

envoy_cc_library(
    name = "order_router_lib",
    deps = [
        "//source/order_router/ctp:ctp2mini_lib",
    ],
)
