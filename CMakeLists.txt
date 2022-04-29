# Copyright (C) <2019> Intel Corporation
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.6)
project(dlog)

set(DLOG_LIB dlog)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out")

add_library(${DLOG_LIB} SHARED dlog.cc)

set_target_properties(${DLOG_LIB} PROPERTIES PUBLIC_HEADER "dlog.h")
install(TARGETS ${DLOG_LIB}
    LIBRARY DESTINATION ${DESTDIR}/lib
    PUBLIC_HEADER DESTINATION ${DESTDIR}/include)

add_custom_command(TARGET ${DLOG_LIB} POST_BUILD
    COMMAND bash -c "mkdir -p ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/include"
    COMMAND bash -c "cp -v ${CMAKE_CURRENT_SOURCE_DIR}/dlog.h ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/include"
    VERBATIM)

#unittests
add_executable(unittests unittests.cc)
target_link_libraries(unittests ${DLOG_LIB})
