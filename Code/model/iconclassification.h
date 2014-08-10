#ifndef ICONCLASSIFICATION_H
#define ICONCLASSIFICATION_H

#include <QVector>
#include <QString>

/*!
 * Defines a way of classifying icons.
 * Possible "real life examples" include resolution, category or target device.
 * It is used to filter and group icons by certain criteria. Organizing
 * IconClassifications in a tree structure is possible by adding children.
 */
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
    //! To be called when the user has selected icons by this classification
    void setSelected(bool selected);
    //! Returns if this classification has been selected
    bool isSelected();
    //! To be called when the user has grouped icons by this classification
    void setGroupedBy(bool groupBy);
    //! Return if this classification has been set to group icons by
    bool isGroupedBy();
};

#endif // ICONCLASSIFICATION_H
