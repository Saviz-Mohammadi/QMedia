#include "Photo.h"
#include "ui_Photo.h"

#include "PhotoFullScreen.h"

void Photo::slot_QPushButton_Capture_Clicked()
{
    m_isOnFileSystem = false;
    m_QString_FilePath = "";

    QString selectedCaptureMode = ui->QComboBox_CaptureMode->currentText();

    method_HideWindows();

    if(selectedCaptureMode == "Full screen")
    {
        // You could just put the entire function right here;
        method_TakeScreenShot_FullScreen(

            ui->QComboBox_ScreenSelection->currentText()
        );

        return;
    }

    method_DisplaySelectionBox();
}

void Photo::slot_QComboBox_CaptureQuality_Changed()
{
    QString option = ui->QComboBox_CaptureQuality->currentText();

    if(option == "High")
    {
        m_Quality_CaptureQuality = Quality::High;

        return;
    }

    m_Quality_CaptureQuality = Quality::Low;
}

void Photo::slot_SelectionBox_Accepted(const QRect &rect)
{
    method_TakeScreenShot_CustomArea(

        ui->QComboBox_ScreenSelection->currentText(),
        rect
        );

    m_SelectionBox_selection->hide();
}

void Photo::slot_SelectionBox_Rejected()
{
    m_SelectionBox_selection->hide();
}

void Photo::slot_Rotate90Plus()
{
    *m_QPixmap_Original = m_QPixmap_Original->transformed(QTransform().rotate(90));
    *m_QPixmap_Thumbnail = m_QPixmap_Thumbnail->transformed(QTransform().rotate(90));

    ui->QLabel_Thumbnail->setPixmap(*m_QPixmap_Thumbnail);
}

void Photo::slot_Rotate90Minus()
{
    *m_QPixmap_Original = m_QPixmap_Original->transformed(QTransform().rotate(-90));
    *m_QPixmap_Thumbnail = m_QPixmap_Thumbnail->transformed(QTransform().rotate(-90));

    ui->QLabel_Thumbnail->setPixmap(*m_QPixmap_Thumbnail);
}

void Photo::slot_QPushButton_SaveAs_Clicked()
{
    QString imageLocation = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);

    // You should check if imageLocation is empty and act accordingly.

    method_SaveScreenShot(imageLocation);
}

void Photo::slot_QPushButton_OpenImage_Clicked()
{
    QString imageLocation = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);

    method_OpenImage(imageLocation);
}

void Photo::slot_QPushButton_FullScreen_Clicked()
{
    PhotoFullScreen *photoView = new PhotoFullScreen(nullptr);

    photoView->showFullScreen();
    photoView->method_setPhoto(m_QPixmap_Original);
}
