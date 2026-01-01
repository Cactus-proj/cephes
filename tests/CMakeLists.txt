# Get googletest
# https://google.github.io/googletest/quickstart-cmake.html
# GoogleTest requires at least C++17
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        52eb8108c5bdec04579160ae17225d66034bd723  # v1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Prevent GoogleTest from installing itself
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# Add include for tests
include_directories(${CMAKE_SOURCE_DIR}/tests/include)

# Add Tests
function(add_cephes_test_module module_name)
    file(GLOB src_files "${module_name}/*.cpp")
    if(src_files)
        add_executable(test_${module_name} ${src_files})
        target_link_libraries(test_${module_name} GTest::gtest_main cephes)
        gtest_discover_tests(test_${module_name})
    endif()
endfunction()

add_cephes_test_module(exp_int)
add_cephes_test_module(gamma)
add_cephes_test_module(error)
add_cephes_test_module(bessel)
add_cephes_test_module(hyper)
add_cephes_test_module(elliptic)
add_cephes_test_module(prob)
add_cephes_test_module(misc)
