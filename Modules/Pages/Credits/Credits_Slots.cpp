#include "Credits.h"

void Credits::slot_QToolButton_Introduction_OpenPage_Pressed(

    )
{
    QDesktopServices::openUrl(

        QUrl(QApplication::organizationDomain())
        );
}
