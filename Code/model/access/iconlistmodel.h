#ifndef ICONLISTMODEL_H
#define ICONLISTMODEL_H

#include <QAbstractListModel>
#include "model/iconset.h"

/*!
 * This class provides data from an IconSet to be displayed in a QListView
 * widget.
 */
class IconListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    IconSet*  iconSet;

public:
    IconListModel(QObject *parent, IconSet *dataSource);

    /*
     * QAbstractItemModel <i>Overrides</i> begin here. Consult the
     * <a href="http://qt-project.org/doc/qt-4.8/qabstractitemmodel.html">
     * Qt documentation</a> for more information.
     */
    QVariant data (const QModelIndex & index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
};

#endif // ICONLISTMODEL_H
