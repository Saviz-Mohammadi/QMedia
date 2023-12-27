#ifdef QT_DEBUG
    #include <QDebug>
#endif

#include "MediaPlayer.h"
#include "ui_MediaPlayer.h"


void MediaPlayer::method_Initialize()
{
    m_MediaPlayer = new QMediaPlayer(
        this
        );

    m_AudioOutput = new QAudioOutput(
        this
        );

    m_VideoWidget = ui->QVideoWidget_Screen;


    // Setting the initial volume level.
    m_AudioOutput->setVolume(70 / 100.0);
    ui->QSlider_Audio->setSliderPosition(m_AudioOutput->volume() * 100.0);


    m_MediaPlayer->setAudioOutput(

        m_AudioOutput
        );

    m_MediaPlayer->setVideoOutput(

        m_VideoWidget
        );
}

void MediaPlayer::method_SetLoopCount(const Count& option)
{
    if(option == Count::Infinite)
    {
        m_MediaPlayer->setLoops(

            QMediaPlayer::Infinite
            );
    }

    else if(option == Count::Once)
    {
        m_MediaPlayer->setLoops(

            QMediaPlayer::Once
            );
    }
}

void MediaPlayer::method_SetVolume(qint64 newVolume)
{
    m_AudioOutput->setVolume(

        // Volume needs to be between 1-0. Therefore, we divide it by 100.
        (qreal) newVolume / 100.0
        );
}

qint64 MediaPlayer::method_GetDuration()
{
    return m_MediaPlayer->duration();
}

QString MediaPlayer::method_ConvertTimeFormat(qint64 miliseconds)
{
    int secs = miliseconds / 1000;
    int mins = (secs / 60) % 60;
    int hours = (secs / 3600);
    secs = secs % 60;

    QString formatted = QString("%1:%2:%3");

    formatted = formatted.arg(hours, 2, 10, QLatin1Char('0'))
                    .arg(mins, 2, 10, QLatin1Char('0'))
                    .arg(secs, 2, 10, QLatin1Char('0'));

    return(formatted);
}
