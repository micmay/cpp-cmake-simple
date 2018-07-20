cmake_minimum_required (VERSION 3.6)
project (cpp-cmake-simple)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h" "*.hpp")

find_program(
  CLANG_TIDY_EXE
  NAMES "clang-tidy"
  DOC "Path to clang-tidy executable"
  )
if(NOT CLANG_TIDY_EXE)
  message(FATAL_ERROR "clang-tidy not found.")
else()
  message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
  set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-checks=*,-clang-analyzer-*,-google-*,-format-style=file")
endif()

add_custom_target(
        clangformat
        COMMAND /usr/bin/clang-format
        -i
        ${SOURCES} ${HEADERS}
)

add_executable(main ${SOURCES} ${HEADERS} README.md)

set_target_properties(
 main PROPERTIES
  CXX_STANDARD 11
  CXX_STANDARD_REQUIRED ON
  COMPILE_FLAGS "${WARNING_FLAGS} -Werror -Wall"
)

if(CLANG_TIDY_EXE)
  set_target_properties(
    main PROPERTIES
    CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
  )
endif()