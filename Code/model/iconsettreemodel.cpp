#include "model/iconsettreemodel.h"
#include "iostream"

IconSetTreeModel::IconSetTreeModel(QObject *parent) : QAbstractItemModel(parent)
{
    root = nullptr;

    //TODO: Remove Testcode
    //=========TESTCODE=================================//
    IconClassification *child1 = new IconClassification("Child1");
    IconClassification *child2 = new IconClassification("Child2");
    IconClassification *child3 = new IconClassification("Child3");
    IconClassification *parent1 = new IconClassification("Parent1");
    IconClassification *parent2 = new IconClassification("Parent2");
    IconClassification *root = new IconClassification("root");

    parent1->addChild(child1);
    parent1->addChild(child2);
    parent2->addChild(child3);
    root->addChild(parent1);
    root->addChild(parent2);

    setRoot(root);
    //=========TESTCODE=================================//
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
    IconClassification *child  = indexToNode(childIndex);
    if (!child) {
        return QModelIndex();
    }

    IconClassification *parent = child->getParent();
    if (!parent) {
        return QModelIndex();
    }

    //Parent's parent is necessary for finding out the parent's row
    IconClassification *grandParent = parent->getParent();
    if (!grandParent) {
        return QModelIndex();
    }
    int row = grandParent->getChildren()->indexOf(parent);

    return createIndex(row, 0, parent);
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

    int childCount = parent->getChildren()->count();
    return childCount;
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
