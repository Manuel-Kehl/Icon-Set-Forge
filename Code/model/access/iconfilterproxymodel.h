#ifndef ICONFILTERPROXYMODEL_H
#define ICONFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "model/access/iconsetobserver.h"
#include "model/iconset.h"

class IconFilterProxyModel : public QSortFilterProxyModel, IconSetObserver
{
    Q_OBJECT
public:
    explicit IconFilterProxyModel(QObject *parent = 0);

    // Overrides from QSortFilterProxyModel
    bool filterAcceptsRow(
            int source_row, const QModelIndex &source_parent) const;
    void setSourceModel(QAbstractItemModel *sourceModel);
    // IconSetObserver's update function
    void update();
};

#endif // ICONFILTERPROXYMODEL_H
