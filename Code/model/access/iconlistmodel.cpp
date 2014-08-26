#include "iconlistmodel.h"
#include "model/icon.h"
#include <QImage>

IconListModel::IconListModel(QObject *parent, IconSet *dataSource)
    : QAbstractListModel(parent)
{
    this->iconSet = dataSource;
}

void IconListModel::update()
{
    QModelIndex start = createIndex(0,0);
    QModelIndex end = createIndex(rowCount(), 0);
    //TODO think about optmization by not emitting dataChanged for ALL icons
    emit dataChanged(start, end);
}

QVariant IconListModel::data(const QModelIndex &index, int role) const
{
    int i = index.row();

    // DecorationRole: The Image itself
    if (role == Qt::DecorationRole) {
        // Return the requested image
        const QImage imageData = iconSet->getIcon(i).getRepresentativeImage();
        return imageData;
    // DisplayRole: The text to be displayed under the image
    } else if (role == Qt::DisplayRole) {
        const QString name = iconSet->getIcon(i).getName();
        return name;
    }

    // Return empty QVariant if not display role
    return QVariant();
}

int IconListModel::rowCount(const QModelIndex &parent) const
{
    return iconSet->iconCount();
}

