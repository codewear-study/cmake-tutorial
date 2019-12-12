# set minimum cmake version
cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial VERSION 1.0.0)

# add the executable
add_executable(Tutorial tutorial.cc)

# pass the version number
configure_file(TutorialConfig.hh.config TutorialConfig.hh)

target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
