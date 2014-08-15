#include "model/iconclassification.h"

IconClassification::IconClassification()
{
    //Initialize with null pointer
    parent = nullptr;
}

IconClassification::IconClassification(bool isRoot) : IconClassification()
{
    this->isRoot = isRoot;
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
    if (immutable) {
        return false;
    }

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

bool IconClassification::isNameTakenByChild(QString childName) const
{
    // Compare childName to the name of all children
    for (auto child : children) {
        if (child->getName() == childName) {
            return true;
        }
    }
    return false;
}

bool IconClassification::isConflicting(IconClassification const *other) const
{
    if (!parent->isRootNode()) {
        // siblings on topmost layer do not "conflict", therefore do not
        // count as "conflicting sibling", if parent is root node
        return false;
    }

    // If both share the same parent, they are siblings
    return ((*other).parent == parent);
}

const QString IconClassification::getName() const
{
    return name;
}

void IconClassification::setSelected(bool selected)
{
    this->selected = selected;
}

bool IconClassification::isSelected() const
{
    return selected;
}

void IconClassification::setGroupedBy(bool groupBy)
{
    this->groupBy = groupBy;
}

bool IconClassification::isGroupedBy() const
{
    return groupBy;
}

bool IconClassification::isImmutable() const
{
    return immutable;
}

void IconClassification::setImmutable()
{
    immutable = true;
}

void IconClassification::setParent(IconClassification *parent)
{
    this->parent = parent;
}

bool IconClassification::isRootNode() const
{
    return isRoot;
}

bool IconClassification::hasParent() const
{
    return !(parent == nullptr);
}

bool IconClassification::hasChildren() const
{
    return !children.isEmpty();
}

IconClassification *IconClassification::getParent()
{
    return parent;
}

QVector<std::shared_ptr<IconClassification>> IconClassification::getChildren()
{
    return children;
}

int IconClassification::getChildIndexOf(const IconClassification *child) const
{
    int index = -1;
    for (int i = 0; i < children.size(); i++) {
        // Comparing the name is enough as they must be unique on one level
        if (children.value(i)->getName() == child->getName()) {
            index = i;
        }
    }
    return index;
}

void IconClassification::addInsertCommand(
        std::unique_ptr<InsertCommand> command)
{
    std::shared_ptr<InsertCommand> commandPointer = std::move(command);
    insertCommandChain.append(commandPointer);
}

void IconClassification::performInsertCommandChain(QImage &icon) const
{
    for (auto command : insertCommandChain) {
        command->execute(icon);
    }
}
