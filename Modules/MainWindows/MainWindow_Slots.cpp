#ifdef QT_DEBUG
    #include <QDebug>
#endif

#include "MainWindow.h"
#include "./ui_MainWindow.h"

void MainWindow::slot_UpdateStatusBar(const QString &message, int timeout)
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

    qDebug() << "MainWindow `slot_UpdateStatusBar` invoked!";
    qDebug() << "Message:" << message;
    qDebug() << "Timeout:" << timeout;

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    ui->QStatusBar_statusBar->showMessage(message, timeout);
}

void MainWindow::slot_ClearStatusBar()
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

    qDebug() << "MainWindow `slot_ClearStatusBar` invoked!";

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    ui->QStatusBar_statusBar->clearMessage();
}

void MainWindow::slot_QActionViewPhotoTab()
{
    ui->QTabWidget_tabWidget->setCurrentIndex(0);
}

void MainWindow::slot_QActionViewMediaPlayerTab()
{
    ui->QTabWidget_tabWidget->setCurrentIndex(1);
}

void MainWindow::slot_QActionViewMediaRecorderTab()
{
    ui->QTabWidget_tabWidget->setCurrentIndex(2);
}

void MainWindow::slot_QActionViewMediaCreditTab()
{
    ui->QTabWidget_tabWidget->setCurrentIndex(3);
}

void MainWindow::slot_QActionOpenImage()
{
    slot_QActionViewPhotoTab();

    ui->QWidget_Tab_Photo->slot_QAction_OpenImage_Triggered();
}

void MainWindow::slot_QActionOpenMedia()
{
    slot_QActionViewMediaPlayerTab();

    ui->QWidget_Tab_MediaPlayer->slot_QAction_MediaPlayer_OpenFile_Triggered();
}

void MainWindow::slot_QActionExit()
{
    this->close();
}
