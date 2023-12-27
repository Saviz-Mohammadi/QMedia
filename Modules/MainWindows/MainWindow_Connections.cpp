#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "Photo.h"
#include "MediaPlayer.h"
#include "MediaRecorder.h"

void MainWindow::method_ConnectEvents()
{
    connect(
        ui->QWidget_Tab_Photo,
        &Photo::signal_UpdateStatusBar,
        this,
        &MainWindow::slot_UpdateStatusBar
        );

    connect(
        ui->QWidget_Tab_Photo,
        &Photo::signal_ClearStatusBar,
        this,
        &MainWindow::slot_ClearStatusBar
        );

    connect(
        ui->QWidget_Tab_MediaPlayer,
        &MediaPlayer::signal_UpdateStatusBar,
        this,
        &MainWindow::slot_UpdateStatusBar
        );

    connect(
        ui->QWidget_Tab_MediaPlayer,
        &MediaPlayer::signal_ClearStatusBar,
        this,
        &MainWindow::slot_ClearStatusBar
        );

    connect(
        ui->QWidget_Tab_MediaRecorder,
        &MediaRecorder::signal_UpdateStatusBar,
        this,
        &MainWindow::slot_UpdateStatusBar
        );

    connect(
        ui->QWidget_Tab_MediaRecorder,
        &MediaRecorder::signal_ClearStatusBar,
        this,
        &MainWindow::slot_ClearStatusBar
        );
}
