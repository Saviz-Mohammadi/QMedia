#include "PhotoFullScreen.h"

void PhotoFullScreen::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Enter)
    {
        close();
    }

    // Calling the base class implementation;
    QWidget::keyPressEvent(event);
}

void PhotoFullScreen::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        close();
    }

    // Calling the base class implementation;
    QWidget::mousePressEvent(event);
}
