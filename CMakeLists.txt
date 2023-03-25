cmake_minimum_required(VERSION 3.14)

project(rewrite_bt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(rewrite_bt
  main.cpp
  mainwindow.h
  mainwindow.cpp
  canvas.h
  canvas.cpp
)

target_link_libraries(rewrite_bt Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(rewrite_bt Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS rewrite_bt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
