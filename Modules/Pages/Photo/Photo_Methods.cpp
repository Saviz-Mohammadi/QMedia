#ifdef QT_DEBUG
    #include <QDebug>
#endif

#include "Photo.h"
#include "ui_Photo.h"


void Photo::method_Initialize()
{
    method_DetectAllScreens();
    method_DetectAllWindows();

    // Creating a new SelectionBox, but not showing it yet.
    m_SelectionBox_selection = new SelectionBox(nullptr);

    ui->QDateEdit_date->setDate(QDate::currentDate());
}

void Photo::method_DetectAllScreens()
{
    QStringList screenList;

    if(QGuiApplication::screens().isEmpty())
    {
        ui->QComboBox_ScreenSelection->addItem("No Screens detected");

        return;
    }

    foreach(const QScreen *screen, QGuiApplication::screens())
    {
        screenList.append(screen->name());
    }

    // Adding all detected screens/monitors to "QComboBox_ScreenSelection";
    foreach(const QString &screenName, screenList)
    {
        ui->QComboBox_ScreenSelection->addItem(screenName);
    }
}

void Photo::method_DetectAllWindows()
{
    foreach(QWidget *widget, QApplication::topLevelWidgets())
    {
        QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget);

        // If the cast was not successful, then just go for the next one.
        if (!mainWindow)
        {
            continue;
        }

        // Storing all QMainWindow objects, so we can later "hide()" and "show()";
        m_QList_Windows.append(mainWindow);
    }
}

void Photo::method_TakeScreenShot_FullScreen(const QString &screenName)
{
    // Find the screen with the specified name;
    for (QScreen *screen : QGuiApplication::screens())
    {
        if (screen->name() == screenName)
        {
            m_QScreen_SelectedScreen = screen;
            break;
        }
    }

    // Wait for 850 miliseconds before calling the method;
    // This makes sure that the window has enough time to hide;
    QTimer::singleShot(

        850,
        this,
        [this]() {
            method_GrabScreen();
        });
}

void Photo::method_TakeScreenShot_CustomArea(const QString &screenName, const QRect &rect)
{
    // Find the screen with the specified name.
    for (QScreen *screen : QGuiApplication::screens())
    {
        if (screen->name() == screenName)
        {
            m_QScreen_SelectedScreen = screen;
            break;
        }
    }

    // Wait for 850 miliseconds before calling the method.
    // This makes sure that the window has enough time to hide.
    QTimer::singleShot(

        850,
        this,
        [this, rect]() {
            method_GrabScreen(rect);
        });
}

void Photo::method_GrabScreen()
{
    m_QPixmap_Original = new QPixmap(

        m_QScreen_SelectedScreen->grabWindow(0)
        );

    if(!m_QPixmap_Original->isNull())
    {
        // Creating a copy so that the original one does not get affected;
        m_QPixmap_Thumbnail = new QPixmap(

            m_QPixmap_Original->copy()
            );

        // Set device pixel ratio;
        m_QPixmap_Original->setDevicePixelRatio(

            m_QScreen_SelectedScreen->devicePixelRatio()
            );

        m_QPixmap_Thumbnail->setDevicePixelRatio(

            m_QScreen_SelectedScreen->devicePixelRatio()
            );

        if(m_Quality_CaptureQuality == Quality::High)
        {
            ui->QLabel_Thumbnail->setPixmap(

                m_QPixmap_Thumbnail->scaled(

                    m_QPixmap_Original->width(),
                    m_QPixmap_Original->height(),
                    Qt::AspectRatioMode::KeepAspectRatioByExpanding,
                    Qt::SmoothTransformation
                    )
                );
        }

        else
        {
            ui->QLabel_Thumbnail->setPixmap(

                m_QPixmap_Thumbnail->scaled(

                    m_QPixmap_Original->width(),
                    m_QPixmap_Original->height(),
                    Qt::AspectRatioMode::KeepAspectRatioByExpanding,
                    Qt::FastTransformation
                    )
                );
        }

        // Enable the buttons;
        ui->QPushButton_SaveAs->setEnabled(true);
        ui->QPushButton_ViewInFullScreen->setEnabled(true);
        ui->QToolButton_90Minus->setEnabled(true);
        ui->QToolButton_90Plus->setEnabled(true);

        // Display information;
        method_DisplayImageInformation();

        // Wait for 850 miliseconds before calling the method;
        // This makes sure that the window has enough time to show;
        QTimer::singleShot(

            850,
            this,
            &Photo::method_ShowWindows
            );

        return;
    }


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

    qDebug() << "Failed to capture screen.";

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    emit signal_UpdateStatusBar("Operation capture screen failed...");
}

void Photo::method_GrabScreen(const QRect &rect)
{
    m_QPixmap_Original = new QPixmap(

        m_QScreen_SelectedScreen->grabWindow(
            0,
            rect.x(),
            rect.y(),
            rect.width(),
            rect.height()
            )
        );

    // Probably not a good idea to manipulate the orginal one. Make a copy to be displayed in the thumbnail;
    if(!m_QPixmap_Original->isNull())
    {
        // Creating a copy so that the original one does not get affected;
        m_QPixmap_Thumbnail = new QPixmap(m_QPixmap_Original->copy());

        // Set device pixel ratio;
        m_QPixmap_Original->setDevicePixelRatio(

            m_QScreen_SelectedScreen->devicePixelRatio()
            );

        m_QPixmap_Thumbnail->setDevicePixelRatio(

            m_QScreen_SelectedScreen->devicePixelRatio()
            );

        if(m_Quality_CaptureQuality == Quality::High)
        {
            ui->QLabel_Thumbnail->setPixmap(

                m_QPixmap_Thumbnail->scaled(

                    m_QPixmap_Original->width(),
                    m_QPixmap_Original->height(),
                    Qt::AspectRatioMode::KeepAspectRatioByExpanding,
                    Qt::SmoothTransformation
                    )
                );
        }

        else
        {
            ui->QLabel_Thumbnail->setPixmap(

                m_QPixmap_Thumbnail->scaled(

                    m_QPixmap_Original->width(),
                    m_QPixmap_Original->height(),
                    Qt::AspectRatioMode::KeepAspectRatioByExpanding,
                    Qt::FastTransformation
                    )
                );
        }

        // Enable the buttons;
        ui->QPushButton_SaveAs->setEnabled(true);
        ui->QPushButton_ViewInFullScreen->setEnabled(true);
        ui->QToolButton_90Minus->setEnabled(true);
        ui->QToolButton_90Plus->setEnabled(true);

        // Display image information;
        method_DisplayImageInformation();

        // Wait for 850 miliseconds before calling the method;
        // This makes sure that the window has enough time to show;
        QTimer::singleShot(

            850,
            this,
            &Photo::method_ShowWindows
            );

        return;
    }

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

    qDebug() << "Failed to capture screen.";

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    emit signal_UpdateStatusBar("Operation capture screen failed...");
}

void Photo::method_DisplaySelectionBox()
{
    m_SelectionBox_selection->method_positionAtCenter();

    m_SelectionBox_selection->show();
}

void Photo::method_DisplayImageInformation()
{
    // If file is located on the system;
    if(m_isOnFileSystem == true)
    {
        QFileInfo fileInfo(m_QString_FilePath);

        // Retrieve the creation date
        QDateTime creationDateTime = fileInfo.birthTime();
        QDate creationDate = creationDateTime.date();

        // Set the creation date to the QDateEdit widget
        ui->QDateEdit_date->setDate(creationDate);

        // Get image information
        QImage image(m_QString_FilePath);

        // Get the size of the file in bytes
        qint64 fileSizeInBytes = fileInfo.size();

        // Convert bytes to kilobytes
        double fileSizeInKB = static_cast<double>(fileSizeInBytes) / 1024;

        // Convert kilobytes to megabytes
        double fileSizeInMB = fileSizeInKB / 1024;

        // Set a threshold for displaying in KB or MB
        double thresholdKB = 1024.0;

        QString fileInformation;

        // Print or use the image size
        if (fileSizeInKB < thresholdKB)
        {
           fileInformation = QString("Resolution %1 x %2 - Size %3 KB").arg(image.width()).arg(image.height()).arg(fileSizeInKB);
        }

        else
        {
            fileInformation = QString("Resolution %1 x %2 - Size %3 MB").arg(image.width()).arg(image.height()).arg(fileSizeInMB);
        }

        ui->QLabel_SizeInfo->setText(fileInformation);

        // Create a QImageReader for the image
        QImageReader imageReader(m_QString_FilePath);

        ui->QLabel_ImageFormat->setText(imageReader.format().toUpper());
        ui->QLabel_FilePath->setText(fileInfo.filePath());

        return;
    }

    // If file is captured currently in the program;
    QString fileInformation = "Resolution 0 x 0 - Size 0 KB";

    if(m_QPixmap_Original != nullptr)
    {
        fileInformation = QString("Resolution %1 x %2 - Size 0 KB")
                              .arg(m_QPixmap_Original->width())
                              .arg(m_QPixmap_Original->height());
    }

    ui->QLabel_SizeInfo->setText(fileInformation);
    ui->QLabel_FilePath->setText("No Path detected");
    ui->QDateEdit_date->setDate(QDate::currentDate());
    ui->QLabel_ImageFormat->setText("None");
}

void Photo::method_OpenImage(const QString &startLocation)
{
    QString filePath = QFileDialog::getOpenFileName(

        this,
        tr("Open file"),
        startLocation,
        tr("PNG (*.png);; JPEG (*.jpg *.jpeg);; All Files (*.*)")
        );

    if (filePath.isEmpty())
    {

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

        qDebug() << "Open image dialog canceled...";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

        emit signal_UpdateStatusBar("Operation open image was canceled...");

        return;
    }

    QPixmap pixmap(filePath);

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

    qDebug() << "Image path:" << filePath;

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    emit signal_UpdateStatusBar(

        QString("File choosen: ").append(filePath)
        );


    if(m_QPixmap_Original == nullptr)
    {
        m_QPixmap_Original = new QPixmap(pixmap.copy());
        m_QPixmap_Thumbnail = new QPixmap(pixmap.copy());
    }

    else
    {
        delete m_QPixmap_Original;
        delete m_QPixmap_Thumbnail;

        m_QPixmap_Original = new QPixmap(pixmap.copy());
        m_QPixmap_Thumbnail = new QPixmap(pixmap.copy());
    }

    // Set device pixel ratio;
    m_QPixmap_Original->setDevicePixelRatio(

        m_QScreen_SelectedScreen->devicePixelRatio()
        );

    m_QPixmap_Thumbnail->setDevicePixelRatio(

        m_QScreen_SelectedScreen->devicePixelRatio()
        );

    ui->QLabel_Thumbnail->setPixmap(*m_QPixmap_Thumbnail);

    m_isOnFileSystem = true;
    m_QString_FilePath = filePath;

    ui->QPushButton_SaveAs->setEnabled(true);
    ui->QPushButton_ViewInFullScreen->setEnabled(true);
    ui->QToolButton_90Minus->setEnabled(true);
    ui->QToolButton_90Plus->setEnabled(true);

    method_DisplayImageInformation();
}

void Photo::slot_QAction_OpenImage_Triggered()
{
    slot_QPushButton_OpenImage_Clicked();
}

void Photo::method_HideWindows()
{
    foreach(QMainWindow *mainWindow, m_QList_Windows)
    {
        mainWindow->hide();
    }
}

void Photo::method_ShowWindows()
{
    foreach(QMainWindow *mainWindow, m_QList_Windows)
    {
        mainWindow->show();
    }
}

void Photo::method_SaveScreenShot(const QString &startLocation)
{
    // If there is no image to save, then just terminate.
    if(!m_QPixmap_Original)
    {
        return;
    }

    QString filePath = QFileDialog::getSaveFileName(

        this,
        tr("Save file as"),
        startLocation,
        tr("PNG (*.png);; JPEG (*.jpg *.jpeg);; All Files (*.*)")
        );

    // If the user canceled, then filePath will be empty, so terminate.
    if(filePath.isEmpty())
    {

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

        qDebug() << "Save image dialog canceled...";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

        emit signal_UpdateStatusBar("Operation save file was canceled...");

        return;
    }

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

    qDebug() << "Save image location:" << filePath;

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    QString fileFormat = QFileInfo(filePath).suffix().toLower();

    bool success = m_QPixmap_Original->save(

        filePath,
        fileFormat.toUtf8().constData()
        );

    if(!success)
    {
        QMessageBox::information(
            this,
            "Operation failed!",
            "An internal error occured! Try attempting to save file again to fix the issue.",
            QMessageBox::Ok
            );
    }

    m_isOnFileSystem = true;
    m_QString_FilePath = filePath;

    method_DisplayImageInformation();
}
