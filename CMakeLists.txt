cmake_minimum_required (VERSION 2.6)
project (cpp-cmake-simple)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h" "*.hpp")

add_custom_target(
        cppcheck
        COMMAND cppcheck
        --enable=warning,performance,portability,information,missingInclude
        --std=c++11
        ${SOURCES} ${HEADERS}
)


add_executable(main ${SOURCES} ${HEADERS} README.md)