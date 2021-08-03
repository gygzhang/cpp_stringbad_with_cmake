#https://www.hahack.com/codes/cmake/
cmake_minimum_required(VERSION 3.0.0)
project(cpp_stringbad VERSION 0.1.0)

# include(CTest)
# enable_testing()

aux_source_directory(. DIR_SRCS)
add_executable(main ${DIR_SRCS})
# add_executable(cpp_stringbad main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
