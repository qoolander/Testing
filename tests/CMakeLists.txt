project(testing)

add_executable(tests testmain.cpp)
target_link_libraries(tests PRIVATE faclib catch)