#include "Credits.h"
#include "ui_Credits.h"


void Credits::method_ConnectEvents()
{
    connect(
        ui->QToolButton_Introduction_OpenPage,
        &QToolButton::clicked,
        this,
        &Credits::slot_QToolButton_Introduction_OpenPage_Pressed
        );
}
