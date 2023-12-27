add_library(Photo STATIC
	Photo.h
	Photo.cpp
	Photo_Connections.cpp
	Photo_Methods.cpp
	Photo_Slots.cpp
	Photo.ui
)

target_include_directories(Photo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Photo PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)

# Make sure if any of your submodules depend on other modules that they are built first by specifying them
target_link_libraries(Photo PUBLIC SelectionBox PhotoFullScreen)
