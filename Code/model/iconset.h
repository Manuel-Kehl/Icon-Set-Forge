#ifndef ICONSET_H
#define ICONSET_H

#include <QVector>
#include <memory>
#include "model/icon.h"
#include "model/iconclassification.h"
#include "model/icongroup.h"

/*!
 * The model representation of an icon set.
 * Contains the set of icons, their corresponding classifications and
 * a QVector of groups, if grouping has been applied.
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
    std::unique_ptr<QVector<IconGroup>> groups;
public:
    IconSet();
    //! Returns the icon at the given index
    const Icon &getIcon(int index) const;
    int iconCount() const;
};

#endif // ICONSET_H
