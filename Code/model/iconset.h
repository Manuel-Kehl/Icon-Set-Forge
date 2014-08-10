#ifndef ICONSET_H
#define ICONSET_H

#include <QVector>
#include <QSharedPointer>
#include "model/icon.h"
#include "model/iconclassification.h"
#include "control/scannerstrategies/abstractscannerstrategy.h"

/*!
 * The model representation of an icon set.
 * Contains the set of icons, their corresponding classifications and an
 * AbstractScannerStrategy used to load the icon set.
 */
class IconSet
{
private:
    QVector<QSharedPointer<Icon>> icons;    
    /*!
     * The root element of the IconClassification tree is only liable
     * for storing and referencing classifications. The classifications
     * itself are represented by its children.
     */
    IconClassification classifications;
    AbstractScannerStrategy *scannerStrategy;
public:
    IconSet(AbstractScannerStrategy *scannerStrategy);    
    //! Reloads all data corresponding to the IconSet's AbstractScannerStrategy
    void updateIconSet();
};

#endif // ICONSET_H
