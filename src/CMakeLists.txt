project(testing)

# All sources that also need to be tested in unit tests go into a static library
add_library(faclib STATIC Factorial.h Factorial.cpp)
target_include_directories(faclib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# The main program
add_executable(prog main.cpp)
target_link_libraries(prog PRIVATE faclib)