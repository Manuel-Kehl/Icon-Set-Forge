#include "iconsetview.h"
#include <qlabel.h>

IconSetView::IconSetView(QWidget *parent) :
    QScrollArea(parent)
{
    galleryLayout = new FlowLayout(this);
    galleryWidget = new QWidget(this);
    galleryWidget->setLayout(galleryLayout);

    //Add galleryWidget to the QScrollArea, important: Widget resizable
    this->setWidgetResizable(true);
    this->setWidget(galleryWidget);
}

void IconSetView::addIconFromFile(QString pathToFile)
{
    //Read and Scale the Image
    QImage image(pathToFile);
    int size = settings.value("appearance/icons/size", 120).toInt();
    image = image.scaled(size, size, Qt::KeepAspectRatio);

    //Add Image to a QLabel that is then added to the galleryLayout
    QPixmap pixmap(QPixmap::fromImage(image));
    QLabel *imageLabel = new QLabel(galleryWidget);
    imageLabel->setPixmap(pixmap);
    galleryLayout->addWidget(imageLabel);
}
