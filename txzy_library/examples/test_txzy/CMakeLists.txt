####################################################### 
#                                                     #  
# Copyright (C) 2014                                  #
# Author: Uriel Martinez                              #
# email: uriel.marherz@gmail.com                      #
#                                                     #
#######################################################

cmake_minimum_required(VERSION 2.8)

set(PROJECTNAME test_txzy)
project(${PROJECTNAME})

find_package(YARP)

set(TXZY_LIBS "/usr/local/lib")
set(CMAKE_CXX_FLAGS "-I$ENV{TXZY_ROOT}/include -L${TXZY_LIBS} -ltxzy -I$ENV{YARP_ROOT}/src/modules/serial")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)


file(GLOB folder_source src/*.cpp)
file(GLOB folder_header include/*.h)
source_group("Source Files" FILES ${folder_source})
source_group("Header Files" FILES ${folder_header})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${YARP_INCLUDE_DIRS})
add_executable(${PROJECTNAME} ${folder_source} ${folder_header})
target_link_libraries(${PROJECTNAME} yarpmod ${CMAKE_CXX_FLAGS} ${YARP_LIBRARIES})
install(TARGETS ${PROJECTNAME} RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)

