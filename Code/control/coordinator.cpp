#include "coordinator.h"

Coordinator::Coordinator(QObject *parent) :
    QObject(parent)
{
}

void Coordinator::openIconSet(std::unique_ptr<AbstractScannerStrategy> scannerStrategy)
{
    // Create new IconSetOperator which handles all other necessary operations
    std::shared_ptr<IconSetOperator> newOperator(
                new IconSetOperator(std::move(scannerStrategy)));
    openedIconSets.append(newOperator);
}
