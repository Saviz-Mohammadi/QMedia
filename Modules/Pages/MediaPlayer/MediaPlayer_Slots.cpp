#include "MediaPlayer.h"
#include "ui_MediaPlayer.h"


void MediaPlayer::slot_QAction_MediaPlayer_OpenFile_Triggered()
{
    slot_QToolButton_MediaPlayer_OpenFile_Pressed();
}

void MediaPlayer::slot_QToolButton_MediaPlayer_OpenFile_Pressed()
{
    QString platformVideoFolderPath = QStandardPaths::writableLocation(

        QStandardPaths::PicturesLocation
        );


    // Debug.
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////

#ifdef QT_DEBUG
    if (!platformVideoFolderPath.isEmpty())
    {
        // Use the imageLocation for saving or loading images
        qDebug() << "Video Folder location: " << platformVideoFolderPath;
    }

    else
    {
        // Handle the case where the location couldn't be determined
        qDebug() << "Unable to determine default Video location";
    }
#endif

    // Debug.
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////


    QString filePath = QFileDialog::getOpenFileName(

        this,
        tr("Open Media file"),
        platformVideoFolderPath,
        tr("Video Files (*.mp4 *.mkv *.mov);; Audio Files (*.mp3 *.wav *.ogg);; All Files (*)")
        );


    // Logging.
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
#ifdef QT_DEBUG

    QString separator(76, '=');

    qDebug();
    qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

    if (!filePath.isEmpty())
    {
        qDebug() << "File selected: " << filePath;
    }

    else
    {
        qDebug() << "Unable to determine file.";
    }

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.


    if (filePath.isEmpty())
    {
        // Display message in QStatus bar.
        return;
    }

    m_MediaPlayer->stop();

    m_MediaPlayer->setSource(

        QUrl::fromLocalFile(filePath)
        );

    m_MediaPlayer->play();
}

void MediaPlayer::slot_QToolButton_MediaPlayer_Play_Pressed()
{
    m_MediaPlayer->play();
}

void MediaPlayer::slot_QToolButton_MediaPlayer_Stop_Pressed()
{
    m_MediaPlayer->stop();
}

void MediaPlayer::slot_QToolButton_MediaPlayer_Pause_Pressed()
{
    m_MediaPlayer->pause();
}

void MediaPlayer::slot_QToolButton_MediaPlayer_Rewind_Pressed()
{
    // You can create a setting where you can define how much it will increase/decrease by.
    m_MediaPlayer->setPosition(

        m_MediaPlayer->position() - 1000 // ms (Miliseconds)
        );
}

void MediaPlayer::slot_QToolButton_MediaPlayer_Forward_Pressed()
{
    // You can create a setting where you can define how much it will increase/decrease by.
    m_MediaPlayer->setPosition(

        m_MediaPlayer->position() + 1000 // ms (Miliseconds)
        );
}

void MediaPlayer::slot_QToolButton_MediaPlayer_Loop_Pressed(bool isChecked)
{
    if(isChecked)
    {
        // this->method_SetLoopCount(

        //     MediaPlayer::Count::Infinite
        //     );

        infinite_loop = true;

        return;
    }

    // this->method_SetLoopCount(

    //     MediaPlayer::Count::Once
    //     );

    infinite_loop = false;
}

void MediaPlayer::slot_QToolButton_MediaPlayer_FullScreen_pressed(bool isChecked)
{
    if(isChecked)
    {
        this->parent = parentWidget()->parentWidget();
        qDebug() << "Original Parent Type:" << this->parent->metaObject()->className();
        setParent(nullptr);
        is_inFullScreen = true;
        this->showFullScreen();

        return;
    }

    qDebug() << this->parent->objectName();

    //QTabWidget *tabWidget = qobject_cast<QTabWidget*>(this->parent);
    QTabWidget *tabWidget = qobject_cast<QTabWidget*>(parent);
    //tabWidget->insertTab(-1, this, "Media Player");

    //setParent(parentWidget);
    tabWidget->insertTab(1, this, "Media Player");
    tabWidget->setCurrentIndex(1);
    is_inFullScreen = false;
}

void MediaPlayer::slot_QSlider_MediaPlayer_Audio_Changed(qint64 newVolume)
{
    this->method_SetVolume(

        newVolume
        );
}

void MediaPlayer::slot_QMediaPlayer_Duration_Changed()
{
    ui->QLabel_FullDuration->setText(

        method_ConvertTimeFormat(

            this->method_GetDuration()
            )
        );
}

void MediaPlayer::slot_ChangeCurrentDuration(qint64 position)
{
    ui->QLabel_CurrentTimeStamp->setText(

        method_ConvertTimeFormat(position)
        );
}

void MediaPlayer::slot_QSlider_PositionChanged()
{
    m_MediaPlayer->pause();
    m_MediaPlayer->setPosition(ui->QSlider_Video->value());
    m_MediaPlayer->play();
}

void MediaPlayer::slot_QMediaPlayer_EndHasReached(QMediaPlayer::MediaStatus status)
{
    if(status == QMediaPlayer::EndOfMedia)
    {
        if(infinite_loop == true)
        {
            m_MediaPlayer->play();
        }
    }
}

void MediaPlayer::slot_QComboBox_SpeedChanged(const QString& text)
{
    if(text.trimmed() == "x 0.5 Speed")
    {
        m_MediaPlayer->setPlaybackRate(0.5);
    }

    else if(text.trimmed() == "x 1.0 Speed")
    {
        m_MediaPlayer->setPlaybackRate(1.0);
    }

    else
    {
        m_MediaPlayer->setPlaybackRate(2.0);
    }
}
