#include "PhotoFullScreen.h"
#include "ui_PhotoFullScreen.h"

PhotoFullScreen::PhotoFullScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PhotoFullScreen)
{
    ui->setupUi(this);

    // This will make sure that the memory is freed automatically after the close() slot is called;
    setAttribute(Qt::WA_DeleteOnClose);
}

PhotoFullScreen::~PhotoFullScreen()
{
    delete ui;
}
