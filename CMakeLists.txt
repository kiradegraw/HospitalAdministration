cmake_minimum_required(VERSION 2.8.9)
project(Hospital)

set(EXECUTABLE_NAME hospital)

# Set compilers
#set(CMAKE_C_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)

# Check for c++11 flag
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# Set compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
 
# Add source files
file(GLOB SOURCES "src/*.cpp")
 
# Add the executable (non-progressive)
add_executable(${EXECUTABLE_NAME} ${SOURCES})
