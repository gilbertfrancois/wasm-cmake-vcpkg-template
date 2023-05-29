cmake_minimum_required(VERSION 3.22)

if(WASM)
  set(VCPKG_TARGET_TRIPLET "wasm32-emscripten")
  set(VCPKG_CHAINLOAD_TOOLCHAIN_FILE
      "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"
      CACHE STRING "emscripten toolchain file")
endif()
set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

project(wasm-cmake-vcpkg-template)

add_subdirectory(wasm_run_once)
add_subdirectory(wasm_library)
add_subdirectory(wasm_main_loop)
add_subdirectory(wasm_memory)
add_subdirectory(wasm_memory_malloc)
add_subdirectory(wasm_export_from_js)
