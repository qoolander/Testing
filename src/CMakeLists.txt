project(testing)

add_subdirectory(UI)
add_subdirectory(Interpreter)

find_package(Qt5 COMPONENTS Core REQUIRED)
set(CMAKE_AUTORCC ON)

# The main program
add_executable(prog main.cpp messageHandler.cpp res.qrc)
target_link_libraries(prog PRIVATE UI)

add_dependencies(prog stylesheet) #calculate qss prebuild