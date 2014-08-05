#ifndef ICONSETTREEMODEL_H
#define ICONSETTREEMODEL_H

#include <QAbstractItemModel>

class IconSetTreeModel : public QAbstractItemModel
{
private:
    Node *root;
    Node *indexToNode(const QModelIndex &index) const;

public:
    IconSetTreeModel(QObject *parent = 0);
    ~IconSetTreeModel();
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
};

#endif // ICONSETTREEMODEL_H
