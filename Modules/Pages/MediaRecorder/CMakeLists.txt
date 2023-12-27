add_library(MediaRecorder STATIC
	MediaRecorder.h
	MediaRecorder.cpp
	MediaRecorder_Connections.cpp
	MediaRecorder_Methods.cpp
	MediaRecorder_Slots.cpp
	MediaRecorder.ui
)

target_include_directories(MediaRecorder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MediaRecorder PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)
