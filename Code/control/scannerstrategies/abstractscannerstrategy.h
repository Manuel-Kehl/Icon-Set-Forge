#ifndef ABSTRACTSCANNERSTRATEGY_H
#define ABSTRACTSCANNERSTRATEGY_H

#include <QVector>
#include <memory>
#include "model/iconclassification.h"
#include "model/icon.h"

/*!
 * An abstract specification for scanning a particular icon set type.
 * By extending this class and overwriting the abstract functions one
 * can define strategies for parsing and accessing different icon sets.
 * This is a good point to join development: Define a scanner strategy for
 * a particular icon set type / structure / format you would like to use
 * manage with Icon Set Forge.
 */
class AbstractScannerStrategy
{
public:
    AbstractScannerStrategy();
    /*!
     * Function that returns all icons contained in an icon set.
     * \return the QVector of icons contained in an icon set.
     * std::unique_ptr has been chosen to communicate that an ownership
     * transferation to the caller of this method takes place.
     */
    virtual std::unique_ptr<QVector<Icon>> scanIcons() = 0;
    /*!
     * Function that returns all classifications contained in an icon set.
     * \return the root IconClassification with all classifications assigned
     * as children organized in a tree structure.
     * std::unique_ptr has been chosen to communicate that an ownership
     * transferation to the caller of this method takes place.
     */
    virtual std::unique_ptr<IconClassification> scanClassifications() = 0;
};

#endif // ABSTRACTSCANNERSTRATEGY_H
