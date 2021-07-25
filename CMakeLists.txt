cmake_minimum_required(VERSION 3.0)

SET(PROJ_NAME "engine")
PROJECT(${PROJ_NAME})

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "include/*.h")

if(WIN32)
  add_subdirectory("SFML-2.5.1")
  # WIN32 := subsystem is windows instead of console?
  add_executable(${PROJ_NAME} WIN32 ${SOURCES})
else(WIN32)
  add_executable(${PROJ_NAME} ${SOURCES})
endif()

#add_executable(game src/main.cpp src/point.cpp)

target_link_libraries(${PROJ_NAME} sfml-graphics)

