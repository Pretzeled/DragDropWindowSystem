cmake_minimum_required(VERSION 3.30)
project(Epsilon)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# echo 'export CMAKE_PREFIX_PATH="$HOME/Qt/6.10.1/macos/lib/cmake:$CMAKE_PREFIX_PATH"' >> ~/.zshrc
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

#add_subdirectory(external/Qt-Advanced-Docking-System)

add_executable(Epsilon src/Application/main.cpp
        src/Editor/MainWindow.cpp
        src/Editor/MainWindow.h
        src/Editor/ViewManager.cpp
        src/Editor/ViewManager.h
        src/Editor/ViewSplitter.cpp
        src/Editor/ViewSplitter.h
        src/Editor/Pane.cpp
        src/Editor/Pane.h
        src/Editor/CustomTabBar.cpp
        src/Editor/FluidTabBar.h
        src/Editor/FloatingTabWidget.cpp
        src/Editor/FloatingTabWidget.h
)


target_link_libraries(Epsilon PUBLIC Qt6::Widgets ) #ads::qtadvanceddocking-qt6

#target_include_directories(Epsilon PUBLIC
#       "/external/Qt-Advanced-Docking-System/src"
#)