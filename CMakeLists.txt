cmake_minimum_required(VERSION 3.10...3.20)

project(influxdb_requests VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(influxREQ main.cpp)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG aac5058a15e9ad5ad393973dc6fe44d7614a7f55) # the commit hash for 1.6.0
FetchContent_MakeAvailable(cpr)

target_link_libraries(influxREQ PRIVATE cpr::cpr)
