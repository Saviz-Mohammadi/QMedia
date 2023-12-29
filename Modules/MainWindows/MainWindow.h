#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // Enums
private:

    // Fields
private:

    // Methods
private:
    void method_ConnectEvents();

    // Signals
signals:

    // Slots
private slots:
    void slot_QActionViewPhotoTab();
    void slot_QActionViewMediaPlayerTab();
    void slot_QActionViewMediaRecorderTab();
    void slot_QActionViewMediaCreditTab();
    void slot_QActionOpenImage();
    void slot_QActionOpenMedia();
    void slot_QActionExit();

    void slot_UpdateStatusBar(const QString &message, int timeout = int(0));
    void slot_ClearStatusBar();
};

#endif // MAINWINDOW_H
