#ifndef ICONSETOPERATOR_H
#define ICONSETOPERATOR_H

#include <QUndoStack>
#include <memory>
#include "model/iconset.h"
#include "scannerstrategies/abstractscannerstrategy.h"

class IconSetOperator
{
private:    
    std::unique_ptr<AbstractScannerStrategy> scannerStrategy;
    std::unique_ptr<IconSet> iconSet;
    QUndoStack undoStack;

public:
    /*!
     * Loads an IconSet as described by the passed AbstractScannerStrategy.
     * \param scannerStrategy The AbstractScannerStrategy to use for loading
     * the actual icon set.
     */
    IconSetOperator(std::unique_ptr<AbstractScannerStrategy> scannerStrategy);
    //TODO: Define functions for operations on IconSets
};

#endif // ICONSETOPERATOR_H
