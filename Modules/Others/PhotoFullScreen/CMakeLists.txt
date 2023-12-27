add_library(PhotoFullScreen STATIC
	PhotoFullScreen.h
	PhotoFullScreen.cpp
	PhotoFullScreen_Methods.cpp
	PhotoFullScreen_Events.cpp
	PhotoFullScreen.ui
)

target_include_directories(PhotoFullScreen PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(PhotoFullScreen PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)
