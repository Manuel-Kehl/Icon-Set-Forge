#ifndef DELETEICONCOMMAND_H
#define DELETEICONCOMMAND_H

#include <QVector>
#include <memory>
#include "control/commands/iconsetcommand.h"

class DeleteIconCommand : public IconSetCommand
{
private:
    //! The index of the icon to delete
    int index;
    //! The amount of icons to delete
    int count;
    //! Vector to keep track of the Icon instances deleted with this command
    std::unique_ptr<QVector<Icon>> deletedIcons;


public:
    DeleteIconCommand(int index, int count);

    void redo();
    void undo();
};

#endif // DELETEICONCOMMAND_H
