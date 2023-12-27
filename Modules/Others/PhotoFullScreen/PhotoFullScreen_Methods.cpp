#include "PhotoFullScreen.h"
#include "ui_PhotoFullScreen.h"

void PhotoFullScreen::method_setPhoto(QPixmap* image)
{
    QPixmap copy;

    if(image == nullptr)
    {
        close();
    }

    copy = image->copy();

    // Get the primary screen
    QScreen *primaryScreen = QGuiApplication::primaryScreen();

    // Get the screen geometry (including any available screen space)
    QRect screenGeometry = primaryScreen->geometry();

    // Get the screen width and height
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    // For more information, search about an operating system's scale factor;
    copy.setDevicePixelRatio(primaryScreen->devicePixelRatio());

    ui->QLabel_Photo->setGeometry(0, 0, screenWidth, screenHeight);

    // If the image is bigger than the device screen, then scale down accordingly;
    if(copy.width() > screenWidth || copy.height() > screenHeight)
    {
        copy = copy.scaled(screenWidth, screenHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    ui->QLabel_Photo->setPixmap(copy);
}
