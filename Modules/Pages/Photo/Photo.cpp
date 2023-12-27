#include "Photo.h"
#include "ui_Photo.h"

Photo::Photo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Photo)
    , m_isOnFileSystem(false)
    , m_QString_FilePath("")
    , m_QPixmap_Original(nullptr)
    , m_QPixmap_Thumbnail(nullptr)
    , m_QScreen_SelectedScreen(nullptr)
    , m_SelectionBox_selection(nullptr)
{
    ui->setupUi(this);

    method_Initialize();
    method_ConnectEvents();
}

Photo::~Photo()
{
    delete ui;
    delete m_SelectionBox_selection;
    delete m_QPixmap_Original;
    delete m_QPixmap_Thumbnail;
}
