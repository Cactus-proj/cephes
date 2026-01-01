cmake_minimum_required(VERSION 3.14)
project(cephes
    VERSION 1.0.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
# Ensure Position Independent Code for all targets (required for shared lib)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Tests
option(BUILD_TESTS "Build the tests" OFF)
# Coverage
include(${CMAKE_SOURCE_DIR}/tests/Coverage.cmake)

# libcephes compilation and installation is in its own subdirectory
include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(cephes)

# --- Tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# --- Installation
include(GNUInstallDirs)
install(TARGETS cephes
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES LICENSE.txt License-request-email.txt
    DESTINATION ${CMAKE_INSTALL_DATADIR}/licenses/${PROJECT_NAME}
)
install(FILES README.md docs/features.md docs/doubldoc.md TYPE DOC)
