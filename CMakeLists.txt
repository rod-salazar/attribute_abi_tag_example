cmake_minimum_required(VERSION 3.24)
project(attribute_abi_tag_example)

set(CMAKE_CXX_STANDARD 20)

add_executable(attribute_abi_tag_example main.cpp abi.h old_abi_user.cpp new_abi_user.cpp)

set_source_files_properties(new_abi_user.cpp PROPERTIES COMPILE_DEFINITIONS NEW_ABI)
