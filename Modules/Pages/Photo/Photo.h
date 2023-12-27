#ifndef IMAGECAPTURE_H
#define IMAGECAPTURE_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QTimer>
#include <QPixmap>
#include <QScreen>
#include <QStringList>
#include <QGuiApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include <QRect>
#include <QImageReader>
#include "SelectionBox.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Photo;
}
QT_END_NAMESPACE

class Photo : public QWidget
{
    Q_OBJECT

public:
    explicit Photo(QWidget *parent = nullptr);
    ~Photo();

private:
    Ui::Photo *ui;

    // Enums
private:
    enum Quality
    {
        High,
        Low
    };

    // Fields
private:
    bool m_isOnFileSystem;
    QString m_QString_FilePath;
    QPixmap *m_QPixmap_Original;
    QPixmap *m_QPixmap_Thumbnail;
    Quality m_Quality_CaptureQuality;
    QList<QMainWindow *> m_QList_Windows;
    QScreen *m_QScreen_SelectedScreen;
    SelectionBox *m_SelectionBox_selection;

    // Methods
private:
    void method_Initialize();
    void method_ConnectEvents();
    void method_DetectAllScreens();
    void method_DetectAllWindows();
    void method_TakeScreenShot_FullScreen(const QString &screenName);
    void method_TakeScreenShot_CustomArea(const QString &screenName, const QRect &rect);
    void method_HideWindows();
    void method_ShowWindows();
    void method_SaveScreenShot(const QString &startLocation);
    void method_GrabScreen();
    void method_GrabScreen(const QRect &rect);
    void method_DisplaySelectionBox();
    void method_DisplayImageInformation();
    void method_OpenImage(const QString &startLocation);

    // Signals
signals:
    void signal_UpdateStatusBar(const QString &message, int timeout = int(0));
    void signal_ClearStatusBar();

private slots:
    void slot_QPushButton_Capture_Clicked();
    void slot_QPushButton_SaveAs_Clicked();
    void slot_QPushButton_OpenImage_Clicked();
    void slot_QPushButton_FullScreen_Clicked();
    void slot_QComboBox_CaptureQuality_Changed();
    void slot_SelectionBox_Accepted(const QRect &rect);
    void slot_SelectionBox_Rejected();
    void slot_Rotate90Plus();
    void slot_Rotate90Minus();
};

#endif // IMAGECAPTURE_H
