#ifndef ICON_H
#define ICON_H

#include <QImage>
#include <QVector>
#include <memory>
#include "model/iconclassification.h"

/*!
 * Describes a single icon.
 * Includes both the image itself as well as pointers to associated classifications.
 */
class Icon
{
private:
    //! The image data of the Icon
    QImage image;
    /*!
     * Holds a list of all IconClassifications this Icon applies to.
     * Ownership between the IconClassification is shared between respective
     * parent and this Icon instance. Therefore std::shared_ptr is used.
     */
    QVector<std::shared_ptr<IconClassification>> classifications;
public:
    Icon();
    Icon(QImage image);
    //! Adds a classification to the Icon's classifications
    void addClassification(std::shared_ptr<IconClassification> classification);
    QImage getImage() const;
};

#endif // ICON_H
