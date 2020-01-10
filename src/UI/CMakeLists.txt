project(testing)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_library(UI SHARED MainWindow.cpp TitleBarWidget.cpp WindowButtons.cpp StatusBar.cpp CodeEditor.cpp MemoryDisplay.cpp)
target_link_libraries(UI PUBLIC Qt5::Widgets Scripting)
