#include "MediaRecorder.h"
#include "ui_MediaRecorder.h"

MediaRecorder::MediaRecorder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MediaRecorder)
{
    ui->setupUi(this);

    method_Initialize();
    method_ConnectEvents();
}

MediaRecorder::~MediaRecorder()
{
    delete ui;
    delete m_mediaFormat;
}
