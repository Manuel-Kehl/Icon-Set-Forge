#ifndef ICONSETTREEMODEL_H
#define ICONSETTREEMODEL_H

#include <QAbstractItemModel>
#include "iconclassification.h"

/*!
 * Provides access to the underlying IconClassification tree.
 * Can be passed to a QTreeView for visualising.
 *
 */
class ClassificationTreeModel : public QAbstractItemModel
{
private:
    /*!
     * Stores the a pointer to the root node, from which the whole tree is
     * accessed and parsed
     */
    IconClassification *root;

    /*!
     * A function that gets the <i>internal pointer</i> out of a
     * QModelIndex. In this particular implementation this pointer then
     * represents the IconClassification node that belongs to the index.
     * \param index The QModelIndex to get the internal pointer from
     * \return The internal pointer of the index or this
     * ClassificationTreeModel's root pointer if the index is invalid
     */
    IconClassification *indexToNode(const QModelIndex &index) const;

public:
    ClassificationTreeModel(QObject *parent = nullptr);
    //! Sets a differnt root node
    void setRoot(IconClassification *node);

    /*
     * QAbstractItemModel <i>Overrides</i> begin here. Consult the
     * <a href="http://qt-project.org/doc/qt-4.8/qabstractitemmodel.html">
     * Qt documentation</a> for more information.
     */
    QModelIndex index(int row, int column, const QModelIndex &parentIndex = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &childIndex) const;
    int rowCount(const QModelIndex &parentIndex) const;
    int columnCount(const QModelIndex &parentIndex) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // ICONSETTREEMODEL_H
