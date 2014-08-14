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

void Icon::addClassification(std::shared_ptr<IconClassification> classification)
{
    this->classifications.append(classification);
}

QImage const &Icon::getRepresentativeImage() const
{
    return image;
}
