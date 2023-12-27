#ifndef SELECTIONBOX_H
#define SELECTIONBOX_H

#include <QGuiApplication>
#include <QPainter>
#include <QPaintEvent>
#include <QRubberBand>
#include <QSizeGrip>
#include <QGridLayout>

class SelectionBox : public QRubberBand
{
    Q_OBJECT
public:
    explicit SelectionBox(QWidget *parent = nullptr, QRubberBand::Shape shape = QRubberBand::Shape::Rectangle);

    // Fields;
private:
    bool isMouseDown;
    QPoint prevMousePoint;

    // Signals;
signals:
    void rejected();
    void accepted(const QRect& dimensions);

    // Methods;
public:
    void method_positionAtCenter();

    // Events Override;
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // SELECTIONBOX_H
