cmake_minimum_required(VERSION 3.16)

project(HelloCMake LANGUAGES CXX)

# ----------------------------------
# C++ standard
# ----------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------
# Include directories
# ----------------------------------
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/external/extlib/include
)

# ----------------------------------
# Create external library
# ----------------------------------
add_library(extlib
    external/extlib/ext.cpp
)

# ----------------------------------
# Create local library
# ----------------------------------
add_library(dummy_lib
    lib/dummy.cpp
)

# ----------------------------------
# Create executable
# ----------------------------------
add_executable(hello
    src/hello.cpp
)

# ----------------------------------
# Link libraries
# ----------------------------------
target_link_libraries(hello
    PRIVATE
        extlib
        dummy_lib
)

# ----------------------------------
# (Recommended modern way)
# Attach include dirs to targets
# ----------------------------------
target_include_directories(hello
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/external/extlib/include
)
