#include "model/icon.h"

Icon::Icon()
{
    // Default constructor needed for creating a QVector of type Icon
    // TODO: Find out if there is a more elegant solution
}

Icon::Icon(QImage image)
{
    this->image = image;
}

void Icon::addClassification(IconClassification *classification)
{
    this->classifications->addChild(classification);
}
