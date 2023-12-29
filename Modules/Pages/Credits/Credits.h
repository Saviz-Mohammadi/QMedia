#ifndef CREDITS_H
#define CREDITS_H

#include <QObject>
#include <QWidget>
#include <QUrl>
#include <QDesktopServices>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Credits;
}
QT_END_NAMESPACE

class Credits : public QWidget
{
    Q_OBJECT

public:
    explicit Credits(QWidget *parent = nullptr);
    ~Credits();

private:
    Ui::Credits *ui;

    // Fields
private:

    // Methods
private:
    void method_Initialize();
    void method_ConnectEvents();
    void method_DisplayApplicationInformation();

    // Signals
signals:
    void signal_UpdateStatusBar(const QString &message, int timeout = int(0));
    void signal_ClearStatusBar();

    // Slots
private slots:
    void slot_QToolButton_Introduction_OpenPage_Pressed();
};

#endif // CREDITS_H
