@IF "%TETRIS_LIBS_DIR%"=="" set TETRIS_LIBS_DIR=YOUR-PATH\TETRIS_LIBS
cmake.exe -DVCPKG_TARGET_TRIPLET="x64-windows" -DCMAKE_TOOLCHAIN_FILE="%TETRIS_LIBS_DIR%\scripts\buildsystems\vcpkg.cmake" -G"Visual Studio 17 2022" ..
