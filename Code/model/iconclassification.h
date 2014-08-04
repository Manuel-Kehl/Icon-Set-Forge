#ifndef ICONCLASSIFICATION_H
#define ICONCLASSIFICATION_H

#include <QVector>
#include <QString>

class IconClassification
{
private:
    QString *name;
    IconClassification *parent;
    QVector<IconClassification*> *children;

public:
    IconClassification();
    bool hasParent();
    bool hasChildren();
    IconClassification getParent();
    QVector<IconClassification> getChildren();
    void setParent(IconClassification *parent);
    void addChild(IconClassification *child);
};

#endif // ICONCLASSIFICATION_H
