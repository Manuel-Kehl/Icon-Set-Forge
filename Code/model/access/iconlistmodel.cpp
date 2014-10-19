#include "iconlistmodel.h"
#include "model/icon.h"
#include <QImage>

IconListModel::IconListModel(QObject *parent, IconSet *dataSource)
    : QAbstractListModel(parent)
{
    this->iconSet = dataSource;
    dataSource->addObserver(this);
}

void IconListModel::update()
{
    QModelIndex start = createIndex(0,0);
    QModelIndex end = createIndex(rowCount(), 0);
    //OPTIMIZE think about optmization by not emitting dataChanged for ALL icons
    emit dataChanged(start, end);
}

IconSet *IconListModel::getIconSet()
{
    return iconSet;
}

QVariant IconListModel::data(const QModelIndex &index, int role) const
{
    int i = index.row();
    Icon icon = iconSet->getIcon(i);

    // DecorationRole: The Image itself
    if (role == Qt::DecorationRole) {
        // Return the requested image
        const QImage imageData = icon.getRepresentativeImage();
        return imageData;
    // DisplayRole: The text to be displayed under the image
    } else if (role == Qt::DisplayRole) {
        const QString name = iconSet->getIcon(i).getName();
        return name;
    }

    // Return empty QVariant if above criteria not matched
    return QVariant();
}

int IconListModel::rowCount(const QModelIndex &parent) const
{
    return iconSet->iconCount();
}

