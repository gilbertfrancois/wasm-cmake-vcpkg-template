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

project(wasm-cmake-vcpkg-template)

add_compile_options(-Wall)
if (DEFINED EMSCRIPTEN)
	add_executable(main src/c/main.c)
	set(CMAKE_EXECUTABLE_SUFFIX ".js")
	# set_target_properties(main PROPERTIES COMPILE_FLAGS "-Os -s SIDE_MODULE=1 ")
	# set_target_properties(main PROPERTIES LINK_FLAGS    "-Os -s WASM=1 -s SIDE_MODULE=1 -s STANDALONE_WASM --no-entry")
else()
	add_executable(main src/c/main.c)
endif()

install(TARGETS main DESTINATION ${CMAKE_SOURCE_DIR}/dist)
if(DEFINED EMSCRIPTEN)
  # install(FILES ${CMAKE_BINARY_DIR}/main.wasm DESTINATION ${CMAKE_SOURCE_DIR}/dist)
  install(FILES ${CMAKE_SOURCE_DIR}/src/html/index.html DESTINATION ${CMAKE_SOURCE_DIR}/dist)
endif()
