#include "Credits.h"
#include "ui_Credits.h"

Credits::Credits(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Credits)
{
    ui->setupUi(this);

    method_Initialize();
    method_ConnectEvents();
    method_DisplayApplicationInformation();
}

Credits::~Credits()
{
    delete ui;
}
