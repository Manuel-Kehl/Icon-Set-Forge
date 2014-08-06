#include "model/classificationtreemodel.h"
#include "iostream"

ClassificationTreeModel::ClassificationTreeModel(QObject *parent) : QAbstractItemModel(parent)
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

ClassificationTreeModel::~ClassificationTreeModel()
{
    delete root;
}

void ClassificationTreeModel::setRoot(IconClassification *node)
{
    delete root;
    root = node;
    reset();
}

IconClassification *ClassificationTreeModel::indexToNode(const QModelIndex &index) const
{
    if (index.isValid()) {
        return static_cast<IconClassification *>(index.internalPointer());
    } else {
        return root;
    }
}

QModelIndex ClassificationTreeModel::index(int row, int column, const QModelIndex &parentIndex) const
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
    int row = grandParent->getChildren()->indexOf(parent);

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

    int childCount = parent->getChildren()->count();
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

QVariant ClassificationTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
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

bool ClassificationTreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
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
