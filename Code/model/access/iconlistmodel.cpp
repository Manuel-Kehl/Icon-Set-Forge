#include "iconlistmodel.h"
#include "model/icon.h"
#include <QImage>

IconListModel::IconListModel(QObject *parent, IconSet *iconSet)
    : QAbstractListModel(parent)
{
    this->iconSet = iconSet;
}

QVariant IconListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        // Return the requested image
        int i = index.row();
        const QImage imageData = iconSet->getIcon(i).getRepresentativeImage();

        return imageData;
    }

    // Return empty QVariant if not display role
    return QVariant();
}

int IconListModel::rowCount(const QModelIndex &parent) const
{
    return iconSet->iconCount();
}

