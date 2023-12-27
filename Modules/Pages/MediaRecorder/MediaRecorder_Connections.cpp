#include "MediaRecorder.h"
#include "ui_MediaRecorder.h"


void MediaRecorder::method_ConnectEvents()
{
    // General
    connect(
        ui->QComboBox_RecordingType,
        &QComboBox::currentIndexChanged,
        this,
        &MediaRecorder::slot_QComboBox_RecodingTypeChanged
        );

    // Audio
    connect(
        ui->QPushButton_AudioOutputFilePath,
        &QPushButton::clicked,
        this,
        &MediaRecorder::slot_QPushButton_AudioOutputFilePathClicked
        );

    connect(
        ui->QToolButton_AudioFileName,
        &QToolButton::clicked,
        this,
        &MediaRecorder::slot_QToolButton_AudioFileNameChanged
        );

    connect(
        ui->QComboBox_FormatAudio,
        &QComboBox::currentIndexChanged,
        this,
        &MediaRecorder::slot_QComboBox_AudioCodecChanged
        );

    connect(
        ui->QComboBox_AudioFormat,
        &QComboBox::currentIndexChanged,
        this,
        &MediaRecorder::slot_QComboBox_AudioFormatChanged
        );

    // Video
    connect(
        ui->QComboBox_InputDeviceVideo,
        &QComboBox::currentIndexChanged,
        this,
        &MediaRecorder::slot_QComboBox_InputDeviceVideoChanged
        );

    connect(
        ui->QComboBox_FormatVideo,
        &QComboBox::currentIndexChanged,
        this,
        &MediaRecorder::slot_QComboBox_VideoCodecChanged
        );

    connect(
        ui->QComboBox_FrameRate,
        &QComboBox::currentIndexChanged,
        this,
        &MediaRecorder::slot_QComboBox_VideoFrameRateChanged
        );

    connect(
        ui->QComboBox_VideoQuality,
        &QComboBox::currentIndexChanged,
        this,
        &MediaRecorder::slot_QComboBox_VideoQualityChanged
        );

    connect(
        ui->QPushButton_VideoOutputFilePath,
        &QPushButton::clicked,
        this,
        &MediaRecorder::slot_QPushButton_VideoOutputFilePathClicked
        );

    connect(
        m_mediaRecorder,
        &QMediaRecorder::errorOccurred,
        this,
        &MediaRecorder::slot_ErrorOccurred
        );

    connect(
        ui->QToolButton_VideoFileName,
        &QToolButton::clicked,
        this,
        &MediaRecorder::slot_QToolButton_VideoFileNameChanged
        );

    connect(
        ui->QComboBox_VideoFormat,
        &QComboBox::currentIndexChanged,
        this,
        &MediaRecorder::slot_QComboBox_VideoFormatChanged
        );

    // Recording
    connect(
        ui->QCheckBox_Minimize,
        &QCheckBox::clicked,
        this,
        &MediaRecorder::slot_MinizeChanged
        );

    connect(
        ui->QPushButton_Start,
        &QPushButton::clicked,
        this,
        &MediaRecorder::slot_StartRecording
        );

    connect(
        ui->QPushButton_Stop,
        &QPushButton::clicked,
        this,
        &MediaRecorder::slot_StopRecording
        );
}
