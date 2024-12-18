###############################################################################################
#   File Name: CMakeLists.txt                                                                 #
#   Copyright (c) 2024 GitHubTea                                                              #
#                                                                                             #
#   This software is distributed under the MIT License.                                       #
#   For more details on the MIT License, please refer to the LICENSE file in this project.    #
#   This software is provided "as is," without any warranty of any kind.                      #
#                                                                                             #
#   Author: GitHubTea                                                                         #
#   Date: 2024-11-28                                                                          #
###############################################################################################

cmake_minimum_required(VERSION 3.14)
project(INHA_OSAP_001_GitHubTea)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(./)
message(${CMAKE_HOME_DIRECTORY})

add_executable(
  avl_tree_test
  test/OSAP_001_GitHubTea_AVLtree_test.cpp
  
  source/OSAP_001_GitHubTea_Node.cpp
)
target_link_libraries(
  avl_tree_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(avl_tree_test)