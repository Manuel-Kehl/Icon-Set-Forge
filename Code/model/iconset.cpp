#include "model/iconset.h"

IconSet::IconSet()
{

}

const Icon &IconSet::getIcon(int index) const
{
    return icons->at(index);
}

const int IconSet::iconCount() const
{
    return icons->size();
}
