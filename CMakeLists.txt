cmake_minimum_required(VERSION 3.16)
project(ray-tracer C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default to Release if no build type was given
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Put executables in bin/
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# ---- Core library ----
add_library(raytracer 
  src/geometry.c
  src/object.c
  src/ppm.c
)
target_include_directories(raytracer PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

target_compile_options(raytracer PRIVATE -Wall -Wextra)

# Math functions (sqrt, sin, cos, ...) live in libm on Linux
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
  target_link_libraries(raytracer PUBLIC ${MATH_LIBRARY})
endif()

# ---- Executables / tests from tests/ ----
set(RT_PROGRAMS
  axis
  display-object
  intersect-test
  ppm-test
  transform-test
)

foreach(prog IN LISTS RT_PROGRAMS)
  add_executable(${prog} tests/${prog}.c)
  target_link_libraries(${prog} PRIVATE raytracer)
  target_compile_options(${prog} PRIVATE -Wall -Wextra)
endforeach()

# ---- Optional: run the tests with `ctest` ----
enable_testing()
add_test(NAME ppm-test       COMMAND ppm-test)
add_test(NAME transform-test COMMAND transform-test)
add_test(NAME intersect-test COMMAND intersect-test)