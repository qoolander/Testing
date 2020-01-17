project(testing)
CMAKE_MINIMUM_REQUIRED(VERSION 3.3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_custom_target(
        stylesheet ALL
        COMMAND qtsass ${CMAKE_CURRENT_SOURCE_DIR}/src/style/stylesheet.scss -o ${CMAKE_CURRENT_SOURCE_DIR}/src/res/style/stylesheet.qss
        BYPRODUCTS src/res/style
        COMMENT "Generating qss"
)

add_subdirectory(src)

