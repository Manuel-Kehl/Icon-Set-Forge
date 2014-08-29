#ifndef ICONSET_H
#define ICONSET_H

#include <QVector>
#include <memory>
#include "model/icon.h"
#include "model/iconclassification.h"
#include "model/icongroup.h"
#include "model/access/iconsetobserver.h"

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
    //! The IconSetObservers to be notified upon data change
    QVector<IconSetObserver*> observers;
public:
    IconSet(
            std::unique_ptr<QVector<Icon>> icons,
            std::unique_ptr<IconClassification> classifications
            );
    //! Returns the icon at the given index
    const Icon &getIcon(int index) const;
    //! Returns the number of icons contained in the IconSet
    int iconCount() const;
    /*!
     * Deletes a specified number of Icons at the given position
     * \param index The index of the first Icon to be removed
     * \param count The amount of Icons to delete
     */
    void deleteIcon(int index, int count = 1);
    /*!
     * Inserts an Icon at the given position.
     * \param index The position to insert the new Icon
     * \param icon The Icon to insert
     */
    void insertIcon(int index, Icon icon);
    /*!
     * Returns a pointer to the the root classification of this IconSet.
     * The pointer is to be considered as a weak reference, as ownership
     * of the classifications is retained by IconSet.
     */
    IconClassification* getClassifications();
    //! Adds an IconSetObserver to this IconSet
    void addObserver(IconSetObserver* observer);
    //! Notifies all attachted IconSetObservers that data may have changed
    void notifyObservers();
};

#endif // ICONSET_H
