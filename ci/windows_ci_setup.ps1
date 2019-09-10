mkdir "$env:TOOLS_BIN_DIR"

$wc = New-Object System.Net.WebClient
$wc.DownloadFile("https://github.com/bazelbuild/bazelisk/releases/download/v1.0/bazelisk-windows-amd64.exe", "$env:TOOLS_BIN_DIR\bazel.exe")
