#include "MediaRecorder.h"
#include "ui_MediaRecorder.h"

void MediaRecorder::slot_QComboBox_RecodingTypeChanged(int index)
{
    switch (index)
    {
    case 0:
        method_ChangeRecordingMode(MediaRecorder::RecordMode::None);

        ui->QGroupBox_AudioSettings->setEnabled(false);
        ui->QGroupBox_VideoSettings->setEnabled(false);
        break;

    case 1:
        method_ChangeRecordingMode(MediaRecorder::RecordMode::AudioOnly);

        ui->QGroupBox_AudioSettings->setEnabled(true);
        ui->QGroupBox_VideoSettings->setEnabled(false);
        break;

    case 2:
        method_ChangeRecordingMode(MediaRecorder::RecordMode::VideoOnly);

        ui->QGroupBox_AudioSettings->setEnabled(false);
        ui->QGroupBox_VideoSettings->setEnabled(true);
        break;

    default:
        method_ChangeRecordingMode(MediaRecorder::RecordMode::Both);

        ui->QGroupBox_AudioSettings->setEnabled(true);
        ui->QGroupBox_VideoSettings->setEnabled(true);
        break;
    }
}

void MediaRecorder::slot_QComboBox_InputDeviceVideoChanged()
{
    // If there are no devices detected;
    if(ui->QComboBox_InputDeviceVideo->count() == 0)
    {
        return;
    }

    this->m_screenCapture->setScreen(

        m_screens.at(ui->QComboBox_InputDeviceVideo->currentIndex())
        );

    m_mediaCaptureSession->setScreenCapture(m_screenCapture);

    // This enables the user to see a preview in the "QVideoWidget";
    m_screenCapture->start();

    // method_ChangeRecordingMode();
}

void MediaRecorder::slot_QComboBox_VideoQualityChanged(int index)
{
    switch (index)
    {
    case 0:
        m_mediaRecorder->setQuality(QMediaRecorder::Quality::HighQuality);
        break;

    case 1:
        m_mediaRecorder->setQuality(QMediaRecorder::Quality::LowQuality);
        break;

    case 2:
        m_mediaRecorder->setQuality(QMediaRecorder::Quality::NormalQuality);
        break;

    case 3:
        m_mediaRecorder->setQuality(QMediaRecorder::Quality::VeryHighQuality);
        break;

    default:
        m_mediaRecorder->setQuality(QMediaRecorder::Quality::VeryLowQuality);
        break;
    }

#ifdef QT_DEBUG

    QString separator(76, '=');

    qDebug();
    qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

    qDebug() << "Video capture quality is now:" << m_mediaRecorder->quality();

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif

}

void MediaRecorder::slot_QComboBox_VideoFrameRateChanged(int index)
{
    switch (index)
    {
    case 0:
        m_mediaRecorder->setVideoFrameRate(

            qreal(30)
            );
        break;

    default:
        m_mediaRecorder->setVideoFrameRate(

            qreal(60)
            );
        break;
    }

#ifdef QT_DEBUG

    QString separator(76, '=');

    qDebug();
    qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

    qDebug() << "Video frame rate is now:" << m_mediaRecorder->videoFrameRate();

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
}

void MediaRecorder::slot_QPushButton_VideoOutputFilePathClicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(

        this,
        tr("Select Folder"),
        ui->QLabel_VideoOutputFilePath->text(),  // Initial directory (optional)
        QFileDialog::ShowDirsOnly
        );

    if (folderPath.isEmpty())
    {

#ifdef QT_DEBUG

        QString separator(76, '=');

        qDebug();
        qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

        qDebug() << "No new path selected for video output!";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif

        return;
    }

    m_videoOutputFolderPath = folderPath;
    ui->QLabel_VideoOutputFilePath->setText(m_videoOutputFolderPath);
}

void MediaRecorder::slot_QComboBox_VideoCodecChanged(int index)
{
    m_mediaFormat->setVideoCodec(

        m_videoFormats.at(ui->QComboBox_FormatVideo->currentIndex())
        );

    // The index corresponds with the list that is cached with an offest of 1 for "None";
    this->m_mediaRecorder->setMediaFormat(

        *m_mediaFormat
        );

#ifdef QT_DEBUG

    QString separator(76, '=');

    qDebug();
    qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

    qDebug() << "Video codec is now:" << m_mediaRecorder->mediaFormat().videoCodec();

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
}

void MediaRecorder::slot_QToolButton_AudioFileNameChanged()
{
    QString input = ui->QLineEdit_AudioFileName->text().trimmed();

    if(input.isEmpty())
    {
        return;
    }

    m_AudioFileName = "/" + input + "_%1(Date)_%2(Hours)_%3(Minutes)_%4(Seconds)";
}

void MediaRecorder::slot_QComboBox_AudioFormatChanged(int index)
{
    switch (index)
    {
    case 0:
        m_recordFormatAudio = MediaRecorder::RecordFormat::ACC;
        break;

    default:
        m_recordFormatAudio = MediaRecorder::RecordFormat::WAV;
        break;
    }
}

void MediaRecorder::slot_QToolButton_VideoFileNameChanged()
{
    QString input = ui->QLineEdit_VideoFileName->text().trimmed();

    if(input.isEmpty())
    {
        return;
    }

    m_VideoFileName = "/" + input + "_%1(Date)_%2(Hours)_%3(Minutes)_%4(Seconds)";
}

void MediaRecorder::slot_QComboBox_VideoFormatChanged(int index)
{
    switch (index)
    {
    case 0:
        m_recordFormatVideo = MediaRecorder::RecordFormat::MKV;
        break;

    default:
        m_recordFormatVideo = MediaRecorder::RecordFormat::MP4;
        break;
    }
}

void MediaRecorder::slot_MinizeChanged(bool checked)
{
    minimize = checked;
}

void MediaRecorder::slot_QComboBox_InputDeviceAudioChanged()
{
    // If there are no devices detected;
    if(ui->QComboBox_InputDeviceAudio->count() == 0)
    {
        return;
    }

    this->m_audioInput->setDevice(

        m_audioInputs.at(ui->QComboBox_InputDeviceAudio->currentIndex())
        );

    m_mediaCaptureSession->setAudioInput(m_audioInput);

    // method_ChangeRecordingMode();
}

void MediaRecorder::slot_QPushButton_AudioOutputFilePathClicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(

        this,
        tr("Select Folder"),
        ui->QLabel_AudioOutputFilePath->text(),  // Initial directory (optional)
        QFileDialog::ShowDirsOnly
        );

    if (folderPath.isEmpty())
    {

#ifdef QT_DEBUG

        QString separator(76, '=');

        qDebug();
        qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

        qDebug() << "No new path selected for audio output!";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif

        return;
    }

    m_audioOutputFolderPath = folderPath;
    ui->QLabel_AudioOutputFilePath->setText(m_audioOutputFolderPath);
}

void MediaRecorder::slot_QComboBox_AudioCodecChanged(int index)
{
    m_mediaFormat->setAudioCodec(

        m_audioFormats.at(ui->QComboBox_FormatAudio->currentIndex())
        );

    this->m_mediaRecorder->setMediaFormat(

        *m_mediaFormat
        );

#ifdef QT_DEBUG

    QString separator(76, '=');

    qDebug();
    qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

    qDebug() << "Audio codec is now:" << m_mediaRecorder->mediaFormat().audioCodec();

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
}

void MediaRecorder::slot_StartRecording()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();

    int hours = currentDateTime.time().hour();
    int minutes = currentDateTime.time().minute();
    int seconds = currentDateTime.time().second();

    if(m_AudioFileName.isEmpty())
    {
        m_AudioFileName = m_DefaultFileName;
    }

    if(m_VideoFileName.isEmpty())
    {
        m_VideoFileName = m_DefaultFileName;
    }

    QString finalOutputFileName;


    switch (m_recordMode)
    {
    case MediaRecorder::RecordMode::AudioOnly:
        finalOutputFileName = m_AudioFileName.arg(currentDateTime.toString("yyyyMMMMdddd"))
              .arg(hours)
              .arg(minutes)
              .arg(seconds);
        break;

    default:
        finalOutputFileName = m_VideoFileName.arg(currentDateTime.toString("yyyyMMMMdddd"))
              .arg(hours)
              .arg(minutes)
              .arg(seconds);
        break;
    }



    // Determine output paths
    switch (m_recordMode)
    {
    case MediaRecorder::RecordMode::VideoOnly:
        m_mediaRecorder->setOutputLocation(

            QUrl::fromLocalFile(m_videoOutputFolderPath + finalOutputFileName)
            );
        break;

    case MediaRecorder::RecordMode::AudioOnly:
        m_mediaRecorder->setOutputLocation(

            QUrl::fromLocalFile(m_audioOutputFolderPath + finalOutputFileName)
            );
        break;

    default:
        m_mediaRecorder->setOutputLocation(

            QUrl::fromLocalFile(m_videoOutputFolderPath + finalOutputFileName)
            );
        break;
    }


    // Wanting to record audio or video or both (m_recordMode) is a completely different thing in comparison to
    // being able to record them (Are the devices set for them for one reason or another). For this reason this
    // check is crucial for contiueng or not;
    bool can_continue = true;
    bool audioDeviceIsSet = true;
    bool videoDeviceISSet = true;

    QMessageBox messageBox;

    messageBox.setIcon(

        QMessageBox::Warning
        );

    messageBox.setWindowTitle(

        "Warning"
        );

    messageBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    int result = int();

    // Determine devices and weather user wishes to continue
    switch (m_recordMode)
    {
    case MediaRecorder::RecordMode::None:
        QMessageBox::critical(

            this,
            "Nothing to record",
            "Recording mode set to None."
            );

        can_continue = false;
        break;

    case MediaRecorder::RecordMode::VideoOnly:
        videoDeviceISSet = m_screenCapture->screen() != nullptr;

        if(videoDeviceISSet)
        {
            messageBox.close();
            break;
        }

        messageBox.setText(

            "No video device for recording was selected/found. Do you wish to continue?"
            );

        result = messageBox.exec();
        break;

    case MediaRecorder::RecordMode::AudioOnly:
        audioDeviceIsSet = !m_audioInput->device().isNull();

        if(audioDeviceIsSet)
        {
            messageBox.close();
            break;
        }

        messageBox.setText(

            "No audio device for recording was selected/found. Do you wish to continue?"
            );

        result = messageBox.exec();
        break;

    default:
        audioDeviceIsSet = !m_audioInput->device().isNull();
        videoDeviceISSet = m_screenCapture->screen() != nullptr;

        if(audioDeviceIsSet && videoDeviceISSet)
        {
            messageBox.close();
            break;
        }

        messageBox.setText(

            "A video or audio device for recording was not selected/found. Do you wish to continue?"
            );

        result = messageBox.exec();
        break;
    }


    if (result == QMessageBox::Cancel)
    {
        can_continue = false;
    }


    if(!can_continue)
    {

#ifdef QT_DEBUG

        QString separator(76, '=');

        qDebug();
        qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

        qDebug() << "Aborting recording!";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif

        return;
    }


    // Set the correct media file format.
    switch (m_recordMode)
    {
    case MediaRecorder::RecordMode::AudioOnly:
        if(m_recordFormatAudio == MediaRecorder::RecordFormat::ACC)
        {
            m_mediaFormat->setFileFormat(QMediaFormat::AAC);
            m_mediaRecorder->setMediaFormat(*m_mediaFormat);
            break;
        }

        else
        {
            m_mediaFormat->setFileFormat(QMediaFormat::Wave);
            m_mediaRecorder->setMediaFormat(*m_mediaFormat);
            break;
        }

        break;

    case MediaRecorder::RecordMode::VideoOnly:
        if(m_recordFormatVideo == MediaRecorder::RecordFormat::MKV)
        {
            m_mediaFormat->setFileFormat(QMediaFormat::Matroska);
            m_mediaRecorder->setMediaFormat(*m_mediaFormat);
            break;
        }

        else
        {
            m_mediaFormat->setFileFormat(QMediaFormat::MPEG4);
            m_mediaRecorder->setMediaFormat(*m_mediaFormat);
            break;
        }

        break;

    default:
        if(m_recordFormatVideo == MediaRecorder::RecordFormat::MKV)
        {
            m_mediaFormat->setFileFormat(QMediaFormat::Matroska);
            m_mediaRecorder->setMediaFormat(*m_mediaFormat);
            break;
        }

        else
        {
            m_mediaFormat->setFileFormat(QMediaFormat::MPEG4);
            m_mediaRecorder->setMediaFormat(*m_mediaFormat);
            break;
        }

        break;
    }

    // Set the whole container to false. This will disable all widgets;
    ui->QGroupBox_AudioSettings->setEnabled(false);
    ui->QGroupBox_VideoSettings->setEnabled(false);
    ui->QGroupBox_GeneralSettings->setEnabled(false);
    ui->QPushButton_Start->setEnabled(false);
    ui->QPushButton_Stop->setEnabled(true);

    emit signal_UpdateStatusBar("Recording in progress...");

    // Try and minimize first before recording;
    if(minimize)
    {
        method_MinimizeWindows();
    }

    m_mediaRecorder->record();
}

void MediaRecorder::slot_StopRecording()
{
    // Enable correct ui elements based on mode;
    switch (m_recordMode)
    {
    case MediaRecorder::RecordMode::AudioOnly:
        ui->QGroupBox_AudioSettings->setEnabled(true);
        ui->QGroupBox_GeneralSettings->setEnabled(true);
        ui->QPushButton_Start->setEnabled(true);
        ui->QPushButton_Stop->setEnabled(false);
        break;

    case MediaRecorder::RecordMode::VideoOnly:
        ui->QGroupBox_VideoSettings->setEnabled(true);
        ui->QGroupBox_GeneralSettings->setEnabled(true);
        ui->QPushButton_Start->setEnabled(true);
        ui->QPushButton_Stop->setEnabled(false);
        break;

    default:
        ui->QGroupBox_AudioSettings->setEnabled(true);
        ui->QGroupBox_VideoSettings->setEnabled(true);
        ui->QGroupBox_GeneralSettings->setEnabled(true);
        ui->QPushButton_Start->setEnabled(true);
        ui->QPushButton_Stop->setEnabled(false);
        break;
    }

    emit signal_UpdateStatusBar("Recording stopped...");

    // We call this before `showWindows()`, so that it does not accidentally capture the window itself.
    m_mediaRecorder->stop();

    if(minimize)
    {
        method_ShowWindows();
    }
}

void MediaRecorder::slot_ErrorOccurred(QMediaRecorder::Error error, const QString &errorString)
{
    qDebug() << errorString;

    QMessageBox::critical(

        this,
        tr("Recording error"),
        errorString
        );
}
