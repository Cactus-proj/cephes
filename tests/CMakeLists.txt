# Get googletest
# https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        b514bdc898e2951020cbdca1304b75f5950d1f59  # v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# Add include for tests
include_directories(${CMAKE_SOURCE_DIR}/tests/include)

# Add Tests
function(add_gtest test_name)
    add_executable(${test_name} ${test_name}.cpp)
    target_link_libraries(${test_name} GTest::gtest_main cephes)
    gtest_discover_tests(${test_name})
endfunction()

add_subdirectory(exp_int)
add_subdirectory(gamma)
add_subdirectory(error)
add_subdirectory(bessel)
add_subdirectory(hyper)
add_subdirectory(elliptic)
add_subdirectory(prob)
add_subdirectory(misc)
