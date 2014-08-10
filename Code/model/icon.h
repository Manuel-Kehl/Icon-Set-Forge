#ifndef ICON_H
#define ICON_H

#include <QString>
#include "model/iconclassification.h"

/*!
 * Describes a single icon.
 * Includes both the image itself as well as all associated classifications.
 */
class Icon
{
private:
    QString file;
    IconClassification* classifications;
public:
    Icon();
    Icon(QString file);
    //!Adds a classification to the icon's classifications
    void addClassification(IconClassification *classification);
};

#endif // ICON_H
