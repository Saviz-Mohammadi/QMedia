#ifdef QT_DEBUG
    #include <QDebug>
#endif

#include "Credits.h"
#include "ui_Credits.h"


void Credits::method_Initialize()
{

}

void Credits::method_DisplayApplicationInformation(

    )
{
    // Application | Name
    ui->QLabel_Introduction_ApplicationName->setText(

        QApplication::applicationName()
        );

    QString version("%1 (dev/unstable)");

    version = version.arg(

        QApplication::applicationVersion()
        );

    // Application | Version
    ui->QLabel_Introduction_ApplicationVersion->setText(

        version
        );

    // Application | Company
    ui->QLabel_Introduction_ApplicationCompany->setText(

        QApplication::organizationName()
        );

    // Application | URL
    ui->QLabel_Introduction_ApplicationURL->setText(

        QApplication::organizationDomain()
        );

    QString operatingSystemInformation("%1 %2 (%3 bit)");

    operatingSystemInformation = operatingSystemInformation.arg(

        QSysInfo::productType(),
        QSysInfo::productVersion(),
        QSysInfo::currentCpuArchitecture()
        );

    // Application | URL
    ui->QLabel_Introduction_OperatingSystem->setText(

        operatingSystemInformation
        );
}
