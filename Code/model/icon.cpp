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

bool Icon::addClassification(
        std::shared_ptr<IconClassification> newClassification)
{
    // Check all existing classifications for possible conflicts
    for (std::shared_ptr<IconClassification> classification : classifications) {
        if(newClassification->isConflicting(classification.get())) {
            return false;
        }
    }

    this->classifications.append(newClassification);
    return true;
}

bool Icon::insertIntoClassification(
            std::shared_ptr<IconClassification> newClassification)
{
    bool success = addClassification(newClassification);
    if (success) {
        // Perform InsertCommands on Icon's image data upon insertion
        newClassification->performInsertCommandChain(image);
    }

    return success;
}

QImage const &Icon::getRepresentativeImage() const
{
    return image;
}
