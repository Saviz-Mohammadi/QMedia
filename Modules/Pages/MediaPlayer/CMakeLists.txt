add_library(MediaPlayer STATIC
	MediaPlayer.h
	MediaPlayer.cpp
	MediaPlayer_Connections.cpp
	MediaPlayer_Methods.cpp
	MediaPlayer_Slots.cpp
        MediaPlayer.ui
)

target_include_directories(MediaPlayer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MediaPlayer PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)
