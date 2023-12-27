#include "MediaPlayer.h"
#include "ui_MediaPlayer.h"

MediaPlayer::MediaPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MediaPlayer)
{
    ui->setupUi(this);

    method_Initialize();
    method_ConnectEvents();
}

MediaPlayer::~MediaPlayer()
{
    delete ui;
}
