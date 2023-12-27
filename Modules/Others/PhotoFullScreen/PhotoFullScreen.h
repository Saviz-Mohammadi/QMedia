#ifndef PHOTOFULLSCREEN_H
#define PHOTOFULLSCREEN_H

#include <QWidget>
#include <QPixmap>
#include <QKeyEvent>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class PhotoFullScreen;
}
QT_END_NAMESPACE

class PhotoFullScreen : public QWidget
{
    Q_OBJECT

public:
    explicit PhotoFullScreen(QWidget *parent = nullptr);
    ~PhotoFullScreen();

private:
    Ui::PhotoFullScreen *ui;

    // Methods
public:
    void method_setPhoto(QPixmap *image = nullptr);

    // Events Override
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // PHOTOFULLSCREEN_H
