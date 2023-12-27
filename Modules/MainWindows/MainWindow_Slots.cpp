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
