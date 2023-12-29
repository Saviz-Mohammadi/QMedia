add_library(Credits STATIC
	Credits.h
	Credits.cpp
	Credits_Connections.cpp
	Credits_Methods.cpp
	Credits_Slots.cpp
	Credits.ui
)

target_include_directories(Credits PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Credits PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)

# Make sure if any of your submodules depend on other modules that they are built first by specifying them
target_link_libraries(Credits PUBLIC SelectionBox PhotoFullScreen)
