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

QModelIndex IconSetTreeModel::index(int row, int column, const QModelIndex &parent) const
{

}
