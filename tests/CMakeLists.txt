include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/releases/download/v1.16.0/googletest-1.16.0.tar.gz
  FIND_PACKAGE_ARGS NAMES GTest
)

if(MSVC)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

add_executable(
  int2025_t_tests
  arithmetic_test.cc
  comparison_test.cc
  compatibility_test.cc
  conversion_test.cc
  edge_cases_test.cc
  output_test.cc
)

target_link_libraries(
  int2025_t_tests
  PRIVATE
    int2025_t
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(int2025_t_tests)
