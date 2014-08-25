#ifndef ABSTRACTSCANNERSTRATEGY_H
#define ABSTRACTSCANNERSTRATEGY_H

#include <QVector>
#include <memory>
#include "model/iconclassification.h"
#include "model/icon.h"
#include "model/iconset.h"

/*!
 * An abstract specification for scanning a particular icon set type.
 * By extending this class and overwriting the abstract functions one
 * can define strategies for parsing and accessing different icon sets.
 * This is a good point to join development: Define a scanner strategy for
 * a particular icon set type / structure / format you would like to use
 * with Icon Set Forge.
 */
class AbstractScannerStrategy
{
public:
    AbstractScannerStrategy();
    /*!
     * Function that loads an icon set from a persistent storage.
     * \return The IconSet instance that represents the icon set.
     * std::unique_ptr has been chosen to communicate that an ownership
     * transferation to the caller of this method takes place.
     * A nullptr return statement is to be interpreted as an I/O error.
     */
    virtual std::unique_ptr<IconSet> loadIconSet() = 0;
    /*!
     * Function that saves an icon set to a persistent storage.
     * \param iconSet A reference to the iconset to be saved.
     * It is passed by reference, to avoid copying, because IconSet instances
     * could tend to be rather big. It is of const nature, to communicate that
     * the function will not modify the referenced object.
     * \return true if successful; false if not
     */
    virtual bool saveIconSet(const IconSet &iconSet) = 0;
};

#endif // ABSTRACTSCANNERSTRATEGY_H
