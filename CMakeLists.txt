cmake_minimum_required(VERSION 3.22)

if(WITH_WASM)
  set(VCPKG_TARGET_TRIPLET "wasm32-emscripten")
  set(VCPKG_CHAINLOAD_TOOLCHAIN_FILE
      "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"
      CACHE STRING "emscripten toolchain file")
endif()
set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

project(emscripten-wasm-template)

if(EMSCRIPTEN)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS=ccall,cwrap")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS=ccall,cwrap")
  set(CMAKE_EXECUTABLE_SUFFIX ".js")

  message(STATUS "Emscripten detected")
  message(STATUS "VCPKG_TARGET_TRIPLET: ${VCPKG_TARGET_TRIPLET}")
  message(STATUS "CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
  message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
  message(STATUS "Build dir: ${CMAKE_BINARY_DIR}")
endif()

add_compile_options(-Wall)
add_executable(main src/c/main.c)

install(TARGETS main DESTINATION ${CMAKE_SOURCE_DIR}/dist)
if(EMSCRIPTEN)
  install(FILES ${CMAKE_BINARY_DIR}/main.wasm DESTINATION ${CMAKE_SOURCE_DIR}/dist)
  install(FILES ${CMAKE_SOURCE_DIR}/src/html/index.html DESTINATION ${CMAKE_SOURCE_DIR}/dist)
endif()
