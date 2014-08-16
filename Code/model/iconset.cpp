#include "model/iconset.h"

IconSet::IconSet() :
    icons(new QVector<Icon>),
    classifications(new IconClassification),
    groups(new QVector<IconGroup>)
{

}

const Icon &IconSet::getIcon(int index) const
{
    return icons->at(index);
}

int IconSet::iconCount() const
{
    return icons->size();
}
