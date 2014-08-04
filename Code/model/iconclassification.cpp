#include "model/iconclassification.h"

IconClassification::IconClassification(QString name)
{
    this->name = name;
    children = new QVector<IconClassification*>();
    //Initialize with null pointer
    parent = nullptr;
}

void IconClassification::addChild(IconClassification *child)
{
    children->append(child);
    child->setParent(this);
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

//TODO: Write a proper destructor for releasingn allocated ressources.
