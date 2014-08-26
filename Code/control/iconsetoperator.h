#ifndef ICONSETOPERATOR_H
#define ICONSETOPERATOR_H

#include <QUndoStack>
#include <memory>
#include "model/iconset.h"
#include "scannerstrategies/abstractscannerstrategy.h"
#include "model/access/classificationtreemodel.h"
#include "model/access/iconlistmodel.h"

class IconSetOperator
{
private:    
    //! The scanner used for loading and saving the maintained IconSet
    std::unique_ptr<AbstractScannerStrategy> scannerStrategy;
    //! The IconSet maintained by this IconSetOperator
    std::unique_ptr<IconSet> iconSet;
    //! Provides acces to the icon data for the view classes
    std::unique_ptr<IconListModel> iconModel;
    //! Provides acces to the classifications for the view classes
    std::unique_ptr<ClassificationTreeModel> classificationModel;
    //! Keeps track of applied actions to allow undo/redo
    QUndoStack undoStack;

public:
    /*!
     * Loads an IconSet as described by the passed AbstractScannerStrategy.
     * \param scannerStrategy The AbstractScannerStrategy to use for loading
     * the actual icon set.
     */
    IconSetOperator(std::unique_ptr<AbstractScannerStrategy> scannerStrategy);
    //TODO: Define functions for operations on IconSets

    IconListModel* getIconListModel();
    ClassificationTreeModel* getClassificationTreeModel();
};

#endif // ICONSETOPERATOR_H
