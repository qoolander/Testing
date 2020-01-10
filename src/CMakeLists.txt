project(testing)

add_subdirectory(UI)
add_subdirectory(Interpreter)

# The main program
add_executable(prog main.cpp messageHandler.cpp)
target_link_libraries(prog PRIVATE UI)