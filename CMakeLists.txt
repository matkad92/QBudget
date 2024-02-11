cmake_minimum_required(VERSION 3.5)

project(QBudget LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/libs)

file(GLOB SOURCES "src/*.cpp" "src/*.h" "src/*.hpp"" ""src/libs/*.cpp" "src/libs/*.h" "src/libs/*.hpp")

add_executable(QBudget ${SOURCES})

include(GNUInstallDirs)
install(TARGETS QBudget
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
