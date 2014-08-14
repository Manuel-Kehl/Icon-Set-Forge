#ifndef ICONGROUP_H
#define ICONGROUP_H

#include "iconcomponent.h"

/*!
 * This class has no implementation yet, as there is no need for such
 * unless the <b>grouping</b> mechanism is going to be implemented.
 * It resembles the role of the composite in the Icon composite pattern.
 */
class IconGroup : public IconComponent
{
public:
    IconGroup();
    // TODO Implement!
    const QImage& getRepresentativeImage() const;
};

#endif // ICONGROUP_H
