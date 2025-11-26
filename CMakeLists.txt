cmake_minimum_required(VERSION 3.30)
project(Epsilon)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# echo 'export CMAKE_PREFIX_PATH="$HOME/Qt/6.10.1/macos/lib/cmake:$CMAKE_PREFIX_PATH"' >> ~/.zshrc
find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(Epsilon src/Application/main.cpp)

target_link_libraries(Epsilon PRIVATE Qt6::Widgets)
