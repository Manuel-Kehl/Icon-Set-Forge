#ifndef ICONSETTREEMODEL_H
#define ICONSETTREEMODEL_H

#include <QAbstractItemModel>
#include "iconclassification.h"

class IconSetTreeModel : public QAbstractItemModel
{
private:
    IconClassification *root;

    IconClassification *indexToNode(const QModelIndex &index) const;

public:
    IconSetTreeModel(QObject *parent = 0);
    ~IconSetTreeModel();

    void setRoot(IconClassification *node);

    QModelIndex index(int row, int column, const QModelIndex &parentIndex = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &childIndex) const;
    int rowCount(const QModelIndex &parentIndex) const;
    int columnCount(const QModelIndex &parentIndex) const;
    QVariant data(const QModelIndex &index, int role) const;

};

#endif // ICONSETTREEMODEL_H
