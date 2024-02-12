cmake_minimum_required(VERSION 3.5)

project(QBudget LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/libs)
# include_directories(src/)

file(GLOB SOURCES "src/*.cpp" "src/*.h" "src/*.hpp" "src/libs/*.cpp" "src/libs/*.h" "src/libs/*.hpp")

# Add test files from Tests/
file(GLOB TEST_SOURCES "Tests/*.cpp" "Tests/*.h" "Tests/*.hpp")

add_executable(QBudget ${SOURCES})

include(GNUInstallDirs)
install(TARGETS QBudget
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Include GoogleTest
include(FetchContent)
FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG main
        )
FetchContent_MakeAvailable(googletest)

# Set up testing
enable_testing()
add_executable(MyTests ${TEST_SOURCES})
target_link_libraries(MyTests PRIVATE gtest_main)
add_test(NAME MyTests COMMAND MyTests)
