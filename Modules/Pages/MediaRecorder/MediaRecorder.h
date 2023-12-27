#ifndef MEDIARECORDER_H
#define MEDIARECORDER_H

#include <QWidget>
#include <QGuiApplication>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QAudioDevice>
#include <QAudioInput>
#include <QMediaRecorder>
#include <QMediaFormat>
#include <QScreenCapture>
#include <QFileDialog>
#include <QStandardPaths>
#include <QUrl>
#include <QRegularExpression>
#include <QMainWindow>
#include <QMessageBox>

namespace Ui
{
    class MediaRecorder;
}

class MediaRecorder : public QWidget
{
    Q_OBJECT

public:
    explicit MediaRecorder(QWidget *parent = nullptr);
    ~MediaRecorder();

private:
    Ui::MediaRecorder *ui;

    // Enums
private:
    enum RecordMode
    {
        AudioOnly,
        VideoOnly,
        Both,
        None
    };

    enum RecordFormat
    {
        ACC,
        WAV,
        MKV,
        MP4
    };

    // Fields
private:
    QMediaCaptureSession* m_mediaCaptureSession = nullptr;
    QAudioInput* m_audioInput = nullptr;
    QScreenCapture* m_screenCapture = nullptr;
    QMediaRecorder* m_mediaRecorder = nullptr;
    QMediaDevices* m_mediaDevices = nullptr;
    QMediaFormat* m_mediaFormat = nullptr;

    QList<QAudioDevice> m_audioInputs;
    QList<QScreen*> m_screens;
    QList<QMediaFormat::VideoCodec> m_videoFormats;
    QList<QMediaFormat::AudioCodec> m_audioFormats;

    RecordMode m_recordMode = RecordMode::None;
    RecordFormat m_recordFormatAudio = RecordFormat::ACC;
    RecordFormat m_recordFormatVideo = RecordFormat::MKV;

    QString m_audioOutputFolderPath = "";
    QString m_videoOutputFolderPath = "";

    QString m_AudioFileName = "";
    QString m_VideoFileName = "";
    QString m_DefaultFileName = "/Recording_%1(Date)_%2(Hours)_%3(Minutes)_%4(Seconds)";

    QList<QMainWindow*> m_QList_Windows;

    bool minimize = false;

    // Methods
private:
    void method_Initialize();
    void method_ConnectEvents();
    void method_InitializeObjects();
    void method_DetectAudioInputs();
    void method_DetectScreens();
    void method_DetectAudioFormats();
    void method_DetectVideoFormats();
    void method_applySettings();
    void method_ChangeRecordingMode(MediaRecorder::RecordMode mode);
    void method_MinimizeWindows();
    void method_ShowWindows();

    // Signals
signals:
    void signal_UpdateStatusBar(const QString &message, int timeout = int(0));
    void signal_ClearStatusBar();

    // Slots
private slots:
    // General
    void slot_QComboBox_RecodingTypeChanged(int index);
    void slot_MinizeChanged(bool checked);

    // Audio
    void slot_QComboBox_InputDeviceAudioChanged();
    void slot_QPushButton_AudioOutputFilePathClicked();
    void slot_QComboBox_AudioCodecChanged(int index);
    void slot_QToolButton_AudioFileNameChanged();
    void slot_QComboBox_AudioFormatChanged(int index);

    // Video
    void slot_QComboBox_InputDeviceVideoChanged();
    void slot_QComboBox_VideoQualityChanged(int index);
    void slot_QComboBox_VideoFrameRateChanged(int index);
    void slot_QPushButton_VideoOutputFilePathClicked();
    void slot_QComboBox_VideoCodecChanged(int index);
    void slot_QToolButton_VideoFileNameChanged();
    void slot_QComboBox_VideoFormatChanged(int index);

    // Other
    void slot_StartRecording();
    void slot_StopRecording();

    // For tesitng
    void slot_ErrorOccurred(QMediaRecorder::Error error, const QString& errorString);
};

#endif // MEDIARECORDER_H
