add_library(MainWindows STATIC
	MainWindow.h
	MainWindow.cpp
	MainWindow_Connections.cpp
	MainWindow_Methods.cpp
	MainWindow_Slots.cpp
	MainWindow.ui
)

target_include_directories(MainWindows PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MainWindows PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)