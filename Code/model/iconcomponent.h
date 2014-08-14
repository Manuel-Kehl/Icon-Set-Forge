#ifndef ICONCOMPONENT_H
#define ICONCOMPONENT_H

#include <QImage>

/*!
 * The component base class for the Icon composite pattern.
 * It has been added to avoid major refactoring when the grouping
 * mechanism is added in the futre, but does not have an important
 * role yet.
 */
class IconComponent
{
public:
    IconComponent();
    /*!
     * Returns the QImage, that is used for being displayed in by the UI.
     * Returning a Reference to const is used to indicate, that the recipient
     * is neither meant to modify nor meant to own the QImage instance.
     */
    virtual const QImage& getRepresentativeImage() const = 0;
};

#endif // ICONCOMPONENT_H
