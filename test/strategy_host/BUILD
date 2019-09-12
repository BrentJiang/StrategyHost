licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_fuzz_test",
    "envoy_cc_test",
    "envoy_cc_test_binary",
    "envoy_cc_test_library",
    "envoy_package",
    "envoy_select_hot_restart",
)
load(
    "//source/extensions:all_extensions.bzl",
    "envoy_all_extensions",
)

envoy_package()

envoy_cc_test(
    name = "ctp_preinsert_test",
    srcs = ["ctp_preinsert_test.cc"],
    tags = ["ctp"],
    deps = ["//source/strategy_host:ctp_preinsert_lib"],
)

# envoy_cc_test_binary(
#     name = "ctppreinsert_test",
#     srcs = ["ctppreinsert_test.cc"],
#     external_deps = [
#         "benchmark",
#         "googletest",
#     ],
#     deps = [
#         "//test/test_common:environment_lib",
#         "//test/mocks/network:network_mocks",
#     ],
# )
