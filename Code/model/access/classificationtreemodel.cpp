#include <iostream>
#include <memory>
#include "model/access/classificationtreemodel.h"

ClassificationTreeModel::ClassificationTreeModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    root = nullptr;

    //TODO: Remove Testcode
    //=========TESTCODE=================================//
    std::unique_ptr<IconClassification> child1(new IconClassification());
    child1->setName("Child1");
    std::unique_ptr<IconClassification> child2(new IconClassification());
    child2->setName("Child2");
    std::unique_ptr<IconClassification> child3(new IconClassification());
    child3->setName("Child3");
    std::unique_ptr<IconClassification> parent1(new IconClassification());
    parent1->setName("Parent1");
    std::unique_ptr<IconClassification> parent2(new IconClassification());
    parent2->setName("Parent2");
    IconClassification *root = new IconClassification(true);
    root->setName("root");

    parent1->addChild(std::move(child1));
    parent1->addChild(std::move(child2));
    parent2->addChild(std::move(child3));
    root->addChild(std::move(parent1));
    root->addChild(std::move(parent2));

    setRoot(root);
    //=========TESTCODE=================================//
}

void ClassificationTreeModel::setRoot(IconClassification *node)
{
    beginResetModel();
    root = node;
    endResetModel();
}

IconClassification *ClassificationTreeModel::indexToNode(
        const QModelIndex &index) const
{
    if (index.isValid()) {
        return static_cast<IconClassification *>(index.internalPointer());
    } else {
        return root;
    }
}

QModelIndex ClassificationTreeModel::index(int row, int column,
                                           const QModelIndex &parentIndex) const
{
    //If no root is set or invalid row or column, return empty QModelIndex
    if (row < 0 || column < 0 || !root) {
        return QModelIndex();
    }

    //Retrieve child classification via the row parameter
    IconClassification *child = indexToNode(parentIndex)->
            getChildren().value(row).get();

    if (!child) {
        return QModelIndex();
    } else {
        return createIndex(row, column, child);
    }
}

QModelIndex ClassificationTreeModel::parent(const QModelIndex &childIndex) const
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
    int row = grandParent->getChildIndexOf(parent);

    return createIndex(row, 0, parent);
}

int ClassificationTreeModel::rowCount(const QModelIndex &parentIndex) const
{
    if (parentIndex.column() > 0) {
        return 0;
    }

    IconClassification *parent = indexToNode(parentIndex);
    if (!parent) {
        return 0;
    }

    int childCount = parent->getChildren().count();
    return childCount;
}

int ClassificationTreeModel::columnCount(const QModelIndex &parentIndex) const
{
    //TODO: Proper implementation
    return 3;
}

QVariant ClassificationTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    int column = index.column();

    if (role == Qt::DisplayRole) {
        if (column == 0) {
            //First Column: Classification Name
            return indexToNode(index)->getName();
        }
    }

    if (role == Qt::CheckStateRole) {
        IconClassification *node = indexToNode(index);

        if (column == 1) {
            return node->isSelected() ? Qt::Checked : Qt::Unchecked;
        } else if (column == 2) {
            //Grouping is only reasonable, if child classifications exist
            if (node->hasChildren()) {
                return node->isGroupedBy() ? Qt::Checked : Qt::Unchecked;
            }
        }
    }

    return QVariant();
}

QVariant ClassificationTreeModel::headerData(int section,
                                             Qt::Orientation orientation,
                                             int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return "Classification";
            break;
        case 1:
            return "Select";
            break;
        case 2:
            return "Group";
            break;
        default:
            return QVariant();
            break;
        }
    }
    return QVariant();
}

bool ClassificationTreeModel::setData(const QModelIndex &index,
                                      const QVariant &value,
                                      int role)
{
    if (!index.isValid()) {
        return false;
    }

    int column = index.column();

    if (role == Qt::CheckStateRole) {
        IconClassification *node = indexToNode(index);
        Qt::CheckState checked = static_cast<Qt::CheckState>(value.toInt());

        if (column == 1) {
            node->setSelected(checked == Qt::Checked);
        } else if (column == 2) {
            node->setGroupedBy(checked == Qt::Checked);
        }
    }
    //To trigger a UI refresh emit the dataChanged signal
    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags ClassificationTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
             return 0;
    }

    //To enable user interaction with the checkboxes
    return Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
}
