#include "model/iconclassification.h"

IconClassification::IconClassification()
{
    children = new QVector<IconClassification*>();
    //Initialize with null pointer
    parent = nullptr;
}

IconClassification::IconClassification(QString name) : IconClassification()
{
    this->setName(name);
}

void IconClassification::addChild(IconClassification *child)
{
    children->append(child);
    child->setParent(this);
}

void IconClassification::setName(QString name)
{
    this->name = name;
}

QString IconClassification::getName()
{
    return name;
}

void IconClassification::setSelected(bool selected)
{
    this->selected = selected;
}

bool IconClassification::isSelected()
{
    return selected;
}

void IconClassification::setGroupedBy(bool groupBy)
{
    this->groupBy = groupBy;
}

bool IconClassification::isGroupedBy()
{
    return groupBy;
}

void IconClassification::setParent(IconClassification *parent)
{
    this->parent = parent;
}

bool IconClassification::hasParent()
{
    return !(parent == nullptr);
}

bool IconClassification::hasChildren()
{
    return children->size() > 0;
}

IconClassification *IconClassification::getParent()
{
    return parent;
}

QVector<IconClassification *> *IconClassification::getChildren()
{
    return children;
}



//TODO: Write a proper destructor for releasingn allocated ressources.
