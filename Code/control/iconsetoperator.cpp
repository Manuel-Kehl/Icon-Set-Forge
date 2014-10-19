#include "iconsetoperator.h"

IconSetOperator::IconSetOperator(
        std::unique_ptr<AbstractScannerStrategy> scannerStrategy) :
    scannerStrategy(std::move(scannerStrategy)),
    iconSet(std::move(this->scannerStrategy->loadIconSet())),
    iconModel(new  IconListModel(nullptr, iconSet.get())),
    proxyModel(new IconFilterProxyModel()),
    classificationModel(new ClassificationTreeModel(nullptr, iconSet.get()))
{
    proxyModel->setSourceModel(iconModel.get());
}

IconListModel *IconSetOperator::getIconListModel()
{
    return iconModel.get();
}

IconFilterProxyModel *IconSetOperator::getIconFilterProxyModel()
{
    return proxyModel.get();
}

ClassificationTreeModel *IconSetOperator::getClassificationTreeModel()
{
    return classificationModel.get();
}

void IconSetOperator::performCommand(IconSetCommand* command)
{
    //TODO: Check if command will get cleared or not!
    command->setData(iconSet.get());
    undoStack.push(command);
}
