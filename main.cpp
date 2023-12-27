#ifdef QT_DEBUG
    #include <QDebug>
#endif

#include <QApplication>
#include <QSysInfo>
#include "MainWindow.h"


void function_setAppInforamtion(const QApplication& application);
void function_DetectOS();

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    function_setAppInforamtion(application);
    function_DetectOS();

    MainWindow mainWindow;
    mainWindow.show();

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

    qDebug() << "Application setup complete.";

    qDebug();
    qDebug() << "[" << separator << "]";
    qDebug() << "[" << separator << "]";
    qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    // Event loop.
    return(application.exec());
}

void function_setAppInforamtion(const QApplication& application)
{
    application.setOrganizationName(

        "Saviz Mohammadi"
        );

    application.setOrganizationDomain(

        "https://github.com/Saviz-Mohammadi"
        );

    application.setApplicationName(

        "QMedia"
        );

    application.setApplicationVersion(

        "0.0.1 Beta"
        );
}

void function_DetectOS()
{
    QString hostOperatingSystem = QSysInfo::productType();

    // Check the operating system type;
    if(hostOperatingSystem == "android")
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

        qDebug() << "Os is: Android";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    }

    else if (hostOperatingSystem == "macos")
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

        qDebug() << "Os is: MacOS";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    }

    else if (hostOperatingSystem == "windows")
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

        qDebug() << "Os is: Windows";

        qDebug();
        qDebug() << "[" << separator << "]";
        qDebug() << "[" << separator << "]";
        qDebug();

#endif
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    // Logging.

    }
}
