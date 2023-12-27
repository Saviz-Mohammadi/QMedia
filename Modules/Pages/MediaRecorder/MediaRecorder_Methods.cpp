#ifdef QT_DEBUG
    #include <QDebug>
#endif

#include "MediaRecorder.h"
#include "ui_MediaRecorder.h"


void MediaRecorder::method_Initialize()
{
    method_InitializeObjects();

    method_DetectAudioInputs();
    method_DetectScreens(); // The same as video inputs.

    method_DetectAudioFormats();
    method_DetectVideoFormats();


    m_audioOutputFolderPath = QStandardPaths::writableLocation(

        QStandardPaths::MusicLocation
        );

    m_videoOutputFolderPath = QStandardPaths::writableLocation(

        QStandardPaths::MoviesLocation
        );

    QRegularExpression regex("[a-zA-Z]*");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);

    ui->QLineEdit_AudioFileName->setValidator(validator);
    ui->QLineEdit_VideoFileName->setValidator(validator);

    ui->QLabel_AudioOutputFilePath->setText(m_audioOutputFolderPath);
    ui->QLabel_VideoOutputFilePath->setText(m_videoOutputFolderPath);

    foreach(QWidget* widget, QApplication::topLevelWidgets())
    {
        QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget);

        // If the cast was not successful, then just go for the next one.
        if (!mainWindow)
        {
            continue;
        }

        m_QList_Windows.append(

            mainWindow
            );
    }

    method_applySettings();
    method_ChangeRecordingMode(MediaRecorder::RecordMode::None);
}

void MediaRecorder::method_InitializeObjects()
{
    m_mediaCaptureSession = new QMediaCaptureSession(this);
    m_mediaDevices = new QMediaDevices(this);
    m_mediaFormat = new QMediaFormat();
    m_audioInput = new QAudioInput(this);
    m_screenCapture = new QScreenCapture(this);
    m_mediaRecorder = new QMediaRecorder(this);
}

void MediaRecorder::method_DetectAudioInputs()
{
    m_audioInputs = m_mediaDevices->audioInputs();

    if(m_audioInputs.isEmpty())
    {

#ifdef QT_DEBUG

        QString separator(76, '=');

        qDebug();
        qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

        qDebug() << "No audio inputs detected!";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif

        return;
    }

    foreach (QAudioDevice audioDevice, m_audioInputs)
    {
        ui->QComboBox_InputDeviceAudio->addItem(

            audioDevice.description()
            );
    }
}

void MediaRecorder::method_DetectScreens()
{
    m_screens = QGuiApplication::screens();

    if(m_screens.isEmpty())
    {

#ifdef QT_DEBUG

        QString separator(76, '=');

        qDebug();
        qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

        qDebug() << "No screens detected! (video input)";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif

        return;
    }

    foreach (QScreen* screen, m_screens)
    {
        ui->QComboBox_InputDeviceVideo->addItem(

            screen->name()
            );
    }
}

void MediaRecorder::method_DetectAudioFormats()
{
    // Detect which audio formats the operating system can encode (support).
    m_audioFormats = m_mediaFormat->supportedAudioCodecs(QMediaFormat::Encode);

    if(m_audioFormats.isEmpty())
    {

#ifdef QT_DEBUG

        QString separator(76, '=');

        qDebug();
        qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

        qDebug() << "No audio formats detected!";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif

        return;
    }

    foreach (QMediaFormat::AudioCodec codec, m_audioFormats)
    {
        ui->QComboBox_FormatAudio->addItem(

            QMediaFormat::audioCodecName(codec)
            );
    }
}

void MediaRecorder::method_DetectVideoFormats()
{
    // Detect which video formats the operating system can encode (support).
    m_videoFormats = m_mediaFormat->supportedVideoCodecs(QMediaFormat::Encode);

    if(m_videoFormats.isEmpty())
    {

#ifdef QT_DEBUG

        QString separator(76, '=');

        qDebug();
        qDebug() << __FILE__ << "| Line:" << __LINE__ << "| Time:" << __TIME__;
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

        qDebug() << "No video formats detected!";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif

        return;
    }

    foreach (QMediaFormat::VideoCodec codec, m_videoFormats)
    {
        ui->QComboBox_FormatVideo->addItem(

            QMediaFormat::videoCodecName(codec)
            );
    }
}

void MediaRecorder::method_applySettings()
{

    // The best way to handle this section with default arguments is to call the slots as if they were invoked for defaults.
    m_mediaRecorder->setQuality(QMediaRecorder::Quality::HighQuality);
    m_mediaRecorder->setVideoFrameRate(qreal(30));
    //m_mediaRecorder->setOutputLocation(QUrl::fromLocalFile("C:/Users/Saviz/Desktop/test.mp4"));


    //m_mediaCaptureSession->setAudioInput(m_audioInput);
    m_mediaCaptureSession->setRecorder(m_mediaRecorder);
    m_mediaCaptureSession->setScreenCapture(m_screenCapture);
    m_mediaCaptureSession->setVideoOutput(ui->widget);

    // audioInput->setDevice()
}

void MediaRecorder::method_ChangeRecordingMode(MediaRecorder::RecordMode mode)
{
    switch (mode)
    {
    case MediaRecorder::RecordMode::None:
        m_recordMode = RecordMode::None;

        m_mediaCaptureSession->setAudioInput(nullptr);
        m_mediaCaptureSession->setScreenCapture(nullptr);
        break;

    case MediaRecorder::RecordMode::AudioOnly:
        m_recordMode = RecordMode::AudioOnly;

        m_mediaCaptureSession->setAudioInput(m_audioInput);
        m_mediaCaptureSession->setScreenCapture(nullptr);
        break;

    case MediaRecorder::RecordMode::VideoOnly:
        m_recordMode = RecordMode::VideoOnly;

        m_mediaCaptureSession->setAudioInput(nullptr);
        m_mediaCaptureSession->setScreenCapture(m_screenCapture);
        break;

    default:
        m_recordMode = RecordMode::Both;

        m_mediaCaptureSession->setAudioInput(m_audioInput);
        m_mediaCaptureSession->setScreenCapture(m_screenCapture);
        break;
    }
}

void MediaRecorder::method_MinimizeWindows()
{
    foreach(QMainWindow* mainWindow, m_QList_Windows)
    {
        mainWindow->showMinimized();
    }
}

void MediaRecorder::method_ShowWindows()
{
    foreach(QMainWindow* mainWindow, m_QList_Windows)
    {
        mainWindow->showMaximized();
    }
}
