cmake_minimum_required (VERSION 2.6)
project (medange)

add_definitions(-std=c++11)

file(GLOB cppsources *.cpp)
add_executable(medange  ${cppsources})
target_link_libraries(medange boost_system boost_filesystem boost_regex boost_thread pthread curl magic)
