#include "model/iconclassification.h"

IconClassification::IconClassification()
{
    //Initialize with null pointer
    parent = nullptr;
}

bool IconClassification::addChild(std::unique_ptr<IconClassification> child)
{
    // Transfer of ownership. std::move makes it an rvalue, so it can be moved
    std::shared_ptr<IconClassification> childSharedPointer(std::move(child));

    //Check if name is already taken and return if so, if so
    if (isNameTakenByChild(childSharedPointer->getName())) {
        return false;
    }

    // By setting a parent in this function it is ensured, that there are no
    // "orphaned child nodes". Only the "root node" has no parent assigned to it
    childSharedPointer->setParent(this);

    children.append(childSharedPointer);

    return true;
}

bool IconClassification::setName(QString name)
{
    // For distinguishability all IconClassifications on the same layer (with
    // the same parent) must have different names: Check if name exists among
    // siblings of this node and return "no success" (false), if so
    if (parent) { // Only check if parent is existant
        if (parent->isNameTakenByChild(name)) {
            return false;
        }
    }

    // If possible, set the new name and return "success" (true)
    this->name = name;
    return true;
}

bool IconClassification::isNameTakenByChild(QString childName)
{
    // Compare childName to the name of all children
    for (auto child : children) {
        if (child->getName() == childName) {
            return true;
        }
    }
    return false;
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
    return !children.isEmpty();
}

const IconClassification *IconClassification::getParent()
{
    return parent;
}

QVector<std::shared_ptr<IconClassification>> IconClassification::getChildren()
{
    return children;
}
