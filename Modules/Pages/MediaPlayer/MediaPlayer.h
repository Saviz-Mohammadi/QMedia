#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QFileDialog>
#include <QFileInfo>
#include <QStandardPaths>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MediaPlayer;
}
QT_END_NAMESPACE

class MediaPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();

private:
    Ui::MediaPlayer *ui;

    // Enums;
private:
    enum Count
    {
        Infinite,
        Once
    };

    // Fields;
private:
    QMediaPlayer* m_MediaPlayer;
    QAudioOutput* m_AudioOutput;
    QVideoWidget* m_VideoWidget;
    QWidget* parent = nullptr;
    bool is_inFullScreen = false;
    bool infinite_loop = false;

    // Methods;
private:
    void method_Initialize();
    void method_ConnectEvents();

    QString method_ConvertTimeFormat(qint64 miliseconds);
    void method_SetMediaFile(const QString& filePath);
    void method_Stop();
    void method_Play();
    void method_Pause();
    void method_Rewind();
    void method_Forward();
    void method_SetLoopCount(const Count& option);
    void method_SetVolume(qint64 newVolume);
    qint64 method_GetDuration();

    // Signals;
signals:
    void signal_UpdateStatusBar(const QString &message, int timeout = int(0));
    void signal_ClearStatusBar();

    // Slots;
public slots:
    void slot_QAction_MediaPlayer_OpenFile_Triggered();

private slots:
    void slot_QToolButton_MediaPlayer_OpenFile_Pressed();
    void slot_QToolButton_MediaPlayer_Play_Pressed();
    void slot_QToolButton_MediaPlayer_Pause_Pressed();
    void slot_QToolButton_MediaPlayer_Rewind_Pressed();
    void slot_QToolButton_MediaPlayer_Forward_Pressed();
    void slot_QToolButton_MediaPlayer_Stop_Pressed();
    void slot_QToolButton_MediaPlayer_Loop_Pressed(bool isChecked);
    void slot_QToolButton_MediaPlayer_FullScreen_pressed(bool isChecked);
    void slot_QSlider_MediaPlayer_Audio_Changed(qint64 newVolume);
    void slot_QMediaPlayer_Duration_Changed();
    void slot_ChangeCurrentDuration(qint64 position);
    void slot_QSlider_PositionChanged();
    void slot_QMediaPlayer_EndHasReached(QMediaPlayer::MediaStatus status);
    void slot_QComboBox_SpeedChanged(const QString& text);
};

#endif // MEDIAPLAYER_H
