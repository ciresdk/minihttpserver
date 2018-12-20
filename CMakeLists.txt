cmake_minimum_required (VERSION 2.8)

# support c++11
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

project (httpserv)

aux_source_directory(. DIR_SRCS)

add_executable(httpserv ${DIR_SRCS})