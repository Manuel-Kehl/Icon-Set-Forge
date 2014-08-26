#ifndef ICONLISTMODEL_H
#define ICONLISTMODEL_H

#include <QAbstractListModel>
#include "model/iconset.h"
#include "model/access/iconsetobserver.h"

/*!
 * This class provides data from an IconSet to be displayed in a QListView
 * widget.
 */
class IconListModel : public QAbstractListModel, IconSetObserver
{
    Q_OBJECT

private:
    IconSet*  iconSet;

public:
    IconListModel(QObject *parent, IconSet *dataSource);
    //! Observer's update function, that emits the dataChanged signal
    void update();
    /*
     * QAbstractItemModel <i>Overrides</i> begin here. Consult the
     * <a href="http://qt-project.org/doc/qt-4.8/qabstractitemmodel.html">
     * Qt documentation</a> for more information.
     */
    QVariant data (const QModelIndex & index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
};

#endif // ICONLISTMODEL_H
