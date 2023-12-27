#include "SelectionBox.h"

void SelectionBox::paintEvent(QPaintEvent *event)
{
    QRubberBand::paintEvent(event);

    QPainter painter(this);

    painter.setPen(QPen(Qt::black,2));

    if (width() > 10 && height() > 10) {
        // Set the text
        QString text = QString("%1 width x %2 height").arg(width()).arg(height());

        // Get the font metrics for the current font
        QFontMetrics fontMetrics(font());

        // Calculate the center position
        int textWidth = fontMetrics.horizontalAdvance(text);
        int textHeight = fontMetrics.height();
        int x = (width() - textWidth) / 2;
        int y = (height() - textHeight) / 2;

        // Draw the text
        painter.drawText(x, y, text);
    }
}

void SelectionBox::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Capture the initial position of mouse cursor.
        prevMousePoint = event->globalPosition().toPoint();

        isMouseDown = true;
    }
}

void SelectionBox::mouseMoveEvent(QMouseEvent *event)
{
    if (isMouseDown == true)
    {
        // Capture the new position of mouse cursor.
        QPoint currMousePoint = event->globalPosition().toPoint();

        // Calculate the distance.
        QPoint distance = event->globalPosition().toPoint() - prevMousePoint;

        // Calculate the new position.
        int newX = x() + distance.x();
        int newY = y() + distance.y();

        // Get the screen geometry.
        QScreen* primaryScreen = QGuiApplication::primaryScreen();

        QRect rectangle = primaryScreen->availableGeometry();

        // Ensure the new position is within the screen boundaries.
        newX = qBound(rectangle.left(), newX, rectangle.right() - width());
        newY = qBound(rectangle.top(), newY, rectangle.bottom() - height());

        // Move to the new position.
        this->move(newX, newY);

        // Update the previous mouse point.
        prevMousePoint = currMousePoint;
    }
}

void SelectionBox::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Reset the `isMouseDown` flag to false, so that it does not indefinitely keep dragging.
        isMouseDown = false;
    }
}

void SelectionBox::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape:
        emit rejected();
        break;

    case Qt::Key_Enter:
    case Qt::Key_Return:
        emit accepted(this->geometry());
        break;

    default:
        QRubberBand::keyPressEvent(event);
        break;
    }
}
