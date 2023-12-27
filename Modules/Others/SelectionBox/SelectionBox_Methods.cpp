#include "SelectionBox.h"

void SelectionBox::method_positionAtCenter()
{
    QScreen* primaryScreen = QGuiApplication::primaryScreen();

    QRect rectangle = primaryScreen->availableGeometry();

    int centerX = (rectangle.width() - width()) / 2;
    int centerY = (rectangle.height() - height()) / 2;

    setGeometry(centerX, centerY, 400, 300);
}
