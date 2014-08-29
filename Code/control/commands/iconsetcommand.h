#ifndef ICONSETCOMMAND_H
#define ICONSETCOMMAND_H

#include <QUndoCommand>
#include "model/iconset.h"

class IconSetCommand : public QUndoCommand
{
private:
    //! The IconSet instance to perform the command on
    IconSet* data;

public:
    IconSetCommand();
    /*!
     * Sets a pointer to the IconSet that this IconSetCommand operates on.
     * To be called whenever an IconSetCommand is passed to IconSetOperator.
     */
    void setData(IconSet* data);
};

#endif // ICONSETCOMMAND_H
