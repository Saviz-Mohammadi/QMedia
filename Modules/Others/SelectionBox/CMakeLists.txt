add_library(SelectionBox STATIC
	SelectionBox.h
	SelectionBox.cpp
	SelectionBox_Methods.cpp
	SelectionBox_Events.cpp
)

target_include_directories(SelectionBox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(SelectionBox PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)
