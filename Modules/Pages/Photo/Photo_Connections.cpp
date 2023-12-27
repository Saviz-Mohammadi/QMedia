#include "Photo.h"
#include "ui_Photo.h"


void Photo::method_ConnectEvents()
{
    connect(
        ui->QPushButton_Capture,
        &QPushButton::clicked,
        this,
        &Photo::slot_QPushButton_Capture_Clicked
        );

    connect(
        ui->QPushButton_SaveAs,
        &QPushButton::clicked,
        this,
        &Photo::slot_QPushButton_SaveAs_Clicked
        );

    connect(
        ui->QPushButton_ViewInFullScreen,
        &QPushButton::clicked,
        this,
        &Photo::slot_QPushButton_FullScreen_Clicked
        );

    connect(
        ui->QComboBox_CaptureQuality,
        &QComboBox::currentIndexChanged,
        this,
        &Photo::slot_QComboBox_CaptureQuality_Changed
        );

    // Selection box
    connect(
        m_SelectionBox_selection,
        &SelectionBox::accepted,
        this,
        &Photo::slot_SelectionBox_Accepted
        );

    connect(
        m_SelectionBox_selection,
        &SelectionBox::rejected,
        this,
        &Photo::slot_SelectionBox_Rejected
        );

    // Rotation
    connect(
        ui->QToolButton_90Plus,
        &QToolButton::clicked,
        this,
        &Photo::slot_Rotate90Plus
        );

    connect(
        ui->QToolButton_90Minus,
        &QToolButton::clicked,
        this,
        &Photo::slot_Rotate90Minus
        );

    connect(
        ui->QPushButton_OpenImage,
        &QPushButton::clicked,
        this,
        &Photo::slot_QPushButton_OpenImage_Clicked
        );
}
