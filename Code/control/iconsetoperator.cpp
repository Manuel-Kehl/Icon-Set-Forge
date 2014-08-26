#include "iconsetoperator.h"

IconSetOperator::IconSetOperator(
        std::unique_ptr<AbstractScannerStrategy> scannerStrategy) :
    scannerStrategy(std::move(scannerStrategy)),
    iconSet(std::move(this->scannerStrategy->loadIconSet())),
    iconModel(new  IconListModel(nullptr, iconSet.get())),
    classificationModel(new ClassificationTreeModel(nullptr, iconSet.get()))
{
}

IconListModel *IconSetOperator::getIconListModel()
{
    return iconModel.get();
}

ClassificationTreeModel *IconSetOperator::getClassificationTreeModel()
{
    return classificationModel.get();
}
