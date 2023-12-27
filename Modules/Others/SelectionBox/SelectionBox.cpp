#include "SelectionBox.h"

SelectionBox::SelectionBox(QWidget* parent, QRubberBand::Shape shape) :
    QRubberBand(shape, parent)
    , isMouseDown(false)
{
    setMouseTracking(true);

    // Create size grips
    QSizeGrip *leftTopGrip = new QSizeGrip(this);
    QSizeGrip *rightTopGrip = new QSizeGrip(this);
    QSizeGrip *leftBottomGrip = new QSizeGrip(this);
    QSizeGrip *rightBottomGrip = new QSizeGrip(this);

    // Create a layout to position the size grips
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(leftTopGrip, 0, 0, 1, 1, Qt::AlignTop | Qt::AlignLeft);
    gridLayout->addWidget(rightTopGrip, 0, 1, 1, 1, Qt::AlignTop | Qt::AlignRight);
    gridLayout->addWidget(leftBottomGrip, 1, 0, 1, 1, Qt::AlignBottom | Qt::AlignLeft);
    gridLayout->addWidget(rightBottomGrip, 1, 1, 1, 1, Qt::AlignBottom | Qt::AlignRight);

    // Set the layout to the widget
    this->setLayout(gridLayout);
}
