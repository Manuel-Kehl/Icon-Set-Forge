#ifndef ICONCLASSIFICATION_H
#define ICONCLASSIFICATION_H

#include <QVector>
#include <QString>

class IconClassification
{
private:
    QString name;
    IconClassification *parent;
    QVector<IconClassification*> *children;
    bool groupBy = false;
    bool selected = false;

public:
    IconClassification();
    IconClassification(QString name);
    bool hasParent();
    bool hasChildren();
    IconClassification *getParent();
    QVector<IconClassification *> *getChildren();
    void setParent(IconClassification *parent);
    void addChild(IconClassification *child);
    void setName(QString name);
    QString getName();
    bool isSelected();
    bool isGroupedBy();
};

#endif // ICONCLASSIFICATION_H
