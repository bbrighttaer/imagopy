cmake_minimum_required(VERSION 3.10)
project(imagopy)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC imagopy/*/*.cpp)

FILE(GLOB HEADERS "imagopy/*/*.h")
list(APPEND SRC ${HEADERS})

add_library(imagopy SHARED ${SRC})

target_link_libraries(imagopy ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(imagopy ${Indigo_LIBRARIES})
target_link_libraries(imagopy ${OpenCV_LIBS})
target_link_libraries(imagopy ${Boost_LIBRARIES})