cmake_minimum_required(VERSION 2.6)
# For old gcc and cmake only
macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)
use_cxx11()
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
# Link runTests with what we want to test 
# and the GTest and pthread library
file(GLOB TEST_SOURCES ./*.cpp)
file(GLOB SOURCES ../*.cpp)
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../main.cpp")
add_executable(runTests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
