licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_binary",
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
    name = "ctp2mini_lib",
    srcs = [
        'CTP2mini_V1.3_linux64_api_20190416/libthosttraderapi.so', 
        'CTP2mini_V1.3_linux64_api_20190416/libthostmduserapi.so',
        ],
    hdrs = [
        "CTP2mini_V1.3_linux64_api_20190416/ThostFtdcMdApi.h", 
        "CTP2mini_V1.3_linux64_api_20190416/ThostFtdcTraderApi.h",
        "CTP2mini_V1.3_linux64_api_20190416/ThostFtdcUserApiDataType.h",
        "CTP2mini_V1.3_linux64_api_20190416/ThostFtdcUserApiStruct.h",
    ]
)