#ifndef ICONSETTREEMODEL_H
#define ICONSETTREEMODEL_H

#include <QAbstractItemModel>
#include "iconclassification.h"

class ClassificationTreeModel : public QAbstractItemModel
{
private:
    IconClassification *root;

    IconClassification *indexToNode(const QModelIndex &index) const;

public:
    ClassificationTreeModel(QObject *parent = nullptr);

    void setRoot(IconClassification *node);

    QModelIndex index(int row, int column, const QModelIndex &parentIndex = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &childIndex) const;
    int rowCount(const QModelIndex &parentIndex) const;
    int columnCount(const QModelIndex &parentIndex) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // ICONSETTREEMODEL_H
