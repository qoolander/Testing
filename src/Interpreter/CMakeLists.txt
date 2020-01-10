project(testing)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Scripting SHARED Interpreter.cpp MemManager.cpp)