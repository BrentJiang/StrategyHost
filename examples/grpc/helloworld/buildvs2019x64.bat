set "var=%cd%"
cd %VCPKG_ROOT% 
vcpkg install c-ares:x64-windows
vcpkg install zlib:x64-windows
vcpkg install abseil:x64-windows
vcpkg install protobuf:x64-windows
cd %var%
cd build
# del CMakeCache.txt
cmake .. -G "Visual Studio 16 2019" -A x64 -DProtobuf_DIR:STRING=%VCPKG_ROOT%/installed/x64-windows/share/protobuf -DgRPC_DIR:STRING=%VCPKG_ROOT%/installed/x64-windows/share/grpc -Dc-ares_DIR:STRING=%VCPKG_ROOT%/installed/x64-windows/share/c-ares -DZLIB_LIBRARY:STRING=%VCPKG_ROOT%/installed/x64-windows/lib/zlib.lib -DZLIB_INCLUDE_DIR=%VCPKG_ROOT%/installed/x64-windows/include -DOPENSSL_ROOT_DIR=%VCPKG_ROOT%/installed/x64-windows/
cd ..
