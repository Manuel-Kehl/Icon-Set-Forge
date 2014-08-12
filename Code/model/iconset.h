#ifndef ICONSET_H
#define ICONSET_H

#include <QVector>
#include <memory>
#include "model/icon.h"
#include "model/iconclassification.h"
#include "control/scannerstrategies/abstractscannerstrategy.h"

/*!
 * The model representation of an icon set.
 * Contains the set of icons, their corresponding classifications and an
 * AbstractScannerStrategy used to load the icon set.
 * All data is owned by the IconSet instance and therefore its lifetime
 * bound to the scope of that class. To realise this, std::unique_ptrs are
 * being used for members.
 */
class IconSet
{
private:
    std::unique_ptr<QVector<Icon>> icons;
    /*!
     * The root element of the IconClassification tree is only liable
     * for storing and referencing classifications. The classifications
     * itself are represented by its children.
     */
    std::unique_ptr<IconClassification> classifications;
    std::unique_ptr<AbstractScannerStrategy> scannerStrategy;
public:
    /*!
     * Creates an IconSet with a given AbstractScannerStrategy
     * \param scannerStrategy is a std::unique_ptr to communicate, that the
     * function acts as a "parameter consuming sink" and therefore
     * takes ownership of the passed strategy
     */
    IconSet(std::unique_ptr<AbstractScannerStrategy> scannerStrategy);
    //! Reloads all data corresponding to the IconSet's AbstractScannerStrategy
    void updateIconSet();
};

#endif // ICONSET_H
