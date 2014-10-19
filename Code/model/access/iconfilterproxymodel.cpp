#include "iconfilterproxymodel.h"
#include "model/access/iconlistmodel.h"

IconFilterProxyModel::IconFilterProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}

bool IconFilterProxyModel::filterAcceptsRow(
        int source_row, const QModelIndex &source_parent) const
{
    IconListModel* source = static_cast<IconListModel*>(sourceModel());

    if (source->getIconSet()->iconCount() <= source_row) {
        return false;
    }

    Icon icon = source->getIconSet()->getIcon(source_row);

    return icon.isSelected();
}


void IconFilterProxyModel::setSourceModel(QAbstractItemModel *sourceModel)
{
    IconListModel* iconListModel = static_cast<IconListModel*>(sourceModel);
    // Add model to IconSet's observer list
    iconListModel->getIconSet()->addObserver(this);

    // Call setSourceModel of super class
    QSortFilterProxyModel::setSourceModel(sourceModel);
}

void IconFilterProxyModel::update()
{
    this->invalidateFilter();
}


