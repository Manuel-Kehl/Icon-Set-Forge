#include "deleteiconcommand.h"

DeleteIconCommand::DeleteIconCommand(int index, int count) :
    index(index), count(count)
{

}

void DeleteIconCommand::redo()
{
    // Add all Icons to the list, for later reconstruction
    for (int i = index; i < (index + count); i++) {
        deletedIcons->append(data->getIcon(i));
    }

    // Delete the actual Icons
    data->deleteIcon(index, count);
}

void DeleteIconCommand::undo()
{
    // Iterate deletedIcons in reverse Order
    for (int i = deletedIcons->size(); i > 0; i--) {
        // Insert previously deleted Icon into IconSet
        data->insertIcon(i, deletedIcons->at(i));
    }
}
