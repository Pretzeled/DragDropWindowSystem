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
        src/Editor/FluidTabBar.cpp
        src/Editor/FluidTabBar.h
        src/Editor/FloatingTabWidget.cpp
        src/Editor/FloatingTabWidget.h
)


target_link_libraries(Epsilon PUBLIC Qt6::Widgets ) #ads::qtadvanceddocking-qt6

if(WIN32)
    find_program(WINDEPLOYQT_EXE NAMES windeployqt.exe windeployqt)

    if(NOT WINDEPLOYQT_EXE)
        message(WARNING "windeployqt not found. Add Qt bin to PATH or set WINDEPLOYQT_EXE.")
    else()
        add_custom_command(TARGET Epsilon POST_BUILD
                COMMAND "${WINDEPLOYQT_EXE}"
                --dir "$<TARGET_FILE_DIR:Epsilon>"
                --qmldir "${CMAKE_SOURCE_DIR}"   # remove if not using QML
                "$<TARGET_FILE:Epsilon>"
                COMMENT "Running windeployqt to copy Qt DLLs/plugins to output dir"
        )
    endif()
endif()

#target_include_directories(Epsilon PUBLIC
#       "/external/Qt-Advanced-Docking-System/src"
#)