cmake_minimum_required(VERSION 3.30)
project(Epsilon)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# echo 'export CMAKE_PREFIX_PATH="$HOME/Qt/6.10.1/macos/lib/cmake:$CMAKE_PREFIX_PATH"' >> ~/.zshrc
find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(Epsilon src/Application/main.cpp
        src/Editor/MainWindow.cpp
        src/Editor/MainWindow.h)

target_link_libraries(Epsilon PRIVATE Qt6::Widgets)

# CMake
if(WIN32)
    # Optionally set QTDIR in your environment or replace the HINTS path with your Qt install.
    find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS "$ENV{QTDIR}/bin" "${CMAKE_PREFIX_PATH}/../bin")

    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET Epsilon POST_BUILD
                COMMAND "${WINDEPLOYQT_EXECUTABLE}" --qmldir "${CMAKE_SOURCE_DIR}" "$<TARGET_FILE:Epsilon>"
                COMMENT "Running windeployqt to copy Qt runtime DLLs into the executable folder"
                VERBATIM
        )
    else()
        message(WARNING "windeployqt not found; set `QTDIR` or add Qt bin to `CMAKE_PREFIX_PATH` or PATH for deployment.")
    endif()
endif()