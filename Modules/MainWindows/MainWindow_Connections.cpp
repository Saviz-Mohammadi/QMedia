#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "Photo.h"
#include "MediaPlayer.h"
#include "MediaRecorder.h"

void MainWindow::method_ConnectEvents()
{
    // QActions - File
    connect(
        ui->QAction_OpenImage,
        &QAction::triggered,
        this,
        &MainWindow::slot_QActionOpenImage
        );

    connect(
        ui->QAction_OpenMedia,
        &QAction::triggered,
        this,
        &MainWindow::slot_QActionOpenMedia
        );

    connect(
        ui->QAction_Exit,
        &QAction::triggered,
        this,
        &MainWindow::slot_QActionExit
        );

    // QActions - View
    connect(
        ui->QActionPhotoTab,
        &QAction::triggered,
        this,
        &MainWindow::slot_QActionViewPhotoTab
        );

    connect(
        ui->QActionMediaPlayerTab,
        &QAction::triggered,
        this,
        &MainWindow::slot_QActionViewMediaPlayerTab
        );

    connect(
        ui->QAction_MediaRecorderTab,
        &QAction::triggered,
        this,
        &MainWindow::slot_QActionViewMediaRecorderTab
        );

    connect(
        ui->QAction_CreditsTab,
        &QAction::triggered,
        this,
        &MainWindow::slot_QActionViewMediaCreditTab
        );

    // Modules
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
