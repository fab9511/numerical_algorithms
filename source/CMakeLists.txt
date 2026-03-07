cmake_minimum_required(VERSION 3.15)
project(Project_1_calc_cos)

include_directories("${PROJECT_SOURCE_DIR}/include")
add_subdirectory(my_lib)
add_executable(prog main.c)

#linkowanie biblioteki do głównego kodu
target_link_libraries(
  prog PUBLIC my_library 
)
