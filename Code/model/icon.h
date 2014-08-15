#ifndef ICON_H
#define ICON_H

#include <QImage>
#include <QVector>
#include <memory>
#include "model/iconclassification.h"
#include "model/iconcomponent.h"

/*!
 * Describes a single icon.
 * Includes both the image itself as well as pointers to associated
 * classifications.
 */
class Icon : public IconComponent
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
    /*!
     * Assigns this Icon to the specified IconClassification.
     * This function is to be used upon scanning an IconSet, but <b>not</b>
     * for inserting an Icon into a new IconClassification.
     * Use Icon::insertIntoClassification() instead, as otherwise the
     * InsertCommands will not be performed on the Icon which will result
     * in Icons that do not meet the IconClassification's requirements.
     * E.g. a 128x128 pixel Icon in the 24x24 resolution IconClassification.
     * \param classification
     * \sa Icon::insertIntoClassification()
     */
    void addClassification(std::shared_ptr<IconClassification> classification);
    /*!
     * Assigns this Icon to the specified IconClassification and performs the
     * chain of InsertCommands defined by the IconClassification.
     * Use this function for inserting new Icons or moving/copying existing
     * Icons into another IconClassification.
     * \param classification
     */
    void insertIntoClassification(
            std::shared_ptr<IconClassification> classification);
    const QImage &getRepresentativeImage() const;
};

#endif // ICON_H
