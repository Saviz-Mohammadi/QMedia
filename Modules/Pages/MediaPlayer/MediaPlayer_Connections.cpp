#include "MediaPlayer.h"
#include "ui_MediaPlayer.h"


void MediaPlayer::method_ConnectEvents()
{
    connect(
        ui->QToolButton_OpenFile,
        &QToolButton::clicked,
        this,
        &MediaPlayer::slot_QToolButton_MediaPlayer_OpenFile_Pressed
        );

    connect(
        ui->QToolButton_Play,
        &QToolButton::clicked,
        this,
        &MediaPlayer::slot_QToolButton_MediaPlayer_Play_Pressed
        );

    connect(
        ui->QToolButton_Pause,
        &QToolButton::clicked,
        this,
        &MediaPlayer::slot_QToolButton_MediaPlayer_Pause_Pressed
        );

    connect(
        ui->QToolButton_Rewind,
        &QToolButton::clicked,
        this,
        &MediaPlayer::slot_QToolButton_MediaPlayer_Rewind_Pressed
        );

    connect(
        ui->QToolButton_Forward,
        &QToolButton::clicked,
        this,
        &MediaPlayer::slot_QToolButton_MediaPlayer_Forward_Pressed
        );

    connect(
        ui->QToolButton_Stop,
        &QToolButton::clicked,
        this,
        &MediaPlayer::slot_QToolButton_MediaPlayer_Stop_Pressed
        );

    connect(
        ui->QToolButton_Loop,
        &QToolButton::toggled,
        this,
        &MediaPlayer::slot_QToolButton_MediaPlayer_Loop_Pressed
        );

    connect(
        ui->QToolButton_FullScreen,
        &QToolButton::toggled,
        this,
        &MediaPlayer::slot_QToolButton_MediaPlayer_FullScreen_pressed
        );

    connect(
        this->m_MediaPlayer,
        &QMediaPlayer::durationChanged,
        ui->QSlider_Video,
        &QSlider::setMaximum
        );

    connect(
        this->m_MediaPlayer,
        &QMediaPlayer::mediaStatusChanged,
        this,
        &MediaPlayer::slot_QMediaPlayer_EndHasReached
        );

    connect(
        this->m_MediaPlayer,
        &QMediaPlayer::positionChanged,
        ui->QSlider_Video,
        &QSlider::setValue
        );

    connect(
        this->m_MediaPlayer,
        &QMediaPlayer::positionChanged,
        this,
        &MediaPlayer::slot_ChangeCurrentDuration
        );

    connect(
        ui->QSlider_Video,
        &QSlider::sliderPressed,
        this->m_MediaPlayer,
        &QMediaPlayer::pause
        );

    connect(
        ui->QSlider_Video,
        &QSlider::sliderReleased,
        this,
        // &QMediaPlayer::setPosition
        &MediaPlayer::slot_QSlider_PositionChanged
        );

    connect(
        ui->QSlider_Audio,
        &QSlider::valueChanged,
        this,
        &MediaPlayer::slot_QSlider_MediaPlayer_Audio_Changed
        );

    connect(
        this->m_MediaPlayer,
        &QMediaPlayer::durationChanged,
        this,
        &MediaPlayer::slot_QMediaPlayer_Duration_Changed
        );

    connect(
        ui->QComboBox_Speed,
        &QComboBox::currentTextChanged,
        this,
        &MediaPlayer::slot_QComboBox_SpeedChanged
        );
}
