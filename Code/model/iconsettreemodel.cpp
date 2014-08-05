#include "model/iconsettreemodel.h"

IconSetTreeModel::IconSetTreeModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    root = nullptr;
}

IconSetTreeModel::~IconSetTreeModel()
{
    delete root;
}

void IconSetTreeModel::setRoot(IconClassification *node)
{
    delete root;
    root = node;
    reset();
}

IconClassification *IconSetTreeModel::indexToNode(const QModelIndex &index) const
{
    if (index.isValid()) {
        return static_cast<IconClassification *>(index.internalPointer());
    } else {
        return root;
    }
}

QModelIndex IconSetTreeModel::index(int row, int column, const QModelIndex &parentIndex) const
{
    //If no root is set or invalid row or column, return empty QModelIndex
    if (row < 0 || column < 0 || !root) {
        return QModelIndex();
    }

    //Retrieve child classification via the row parameter
    IconClassification *child = indexToNode(parentIndex)->getChildren()->value(row);

    if (!child) {
        return QModelIndex();
    } else {
        return createIndex(row, column, child);
    }
}

QModelIndex IconSetTreeModel::parent(const QModelIndex &childIndex) const
{
    indexToNode(childIndex)->getParent();
}

int IconSetTreeModel::rowCount(const QModelIndex &parentIndex) const
{
    if (parentIndex.column() > 0) {
        return 0;
    }

    IconClassification *parent = indexToNode(parentIndex);
    if (!parent) {
        return 0;
    }

    return parent->getChildren()->count();
}

int IconSetTreeModel::columnCount(const QModelIndex &parentIndex) const
{
    //TODO: Proper implementation
    return 2;
}

QVariant IconSetTreeModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}
