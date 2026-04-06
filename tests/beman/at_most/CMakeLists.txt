# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

find_package(GTest REQUIRED)

add_executable(beman.at_most.tests.todo)
target_sources(beman.at_most.tests.todo PRIVATE todo.test.cpp)
target_link_libraries(
    beman.at_most.tests.todo
    PRIVATE beman::at_most GTest::gtest_main
)

add_executable(beman.at_most.tests)
target_sources(beman.at_most.tests PRIVATE at_most.test.cpp)
target_link_libraries(
    beman.at_most.tests
    PRIVATE beman::at_most GTest::gtest GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(beman.at_most.tests.todo)
gtest_discover_tests(beman.at_most.tests)
