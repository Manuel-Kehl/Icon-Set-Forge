#include "iconsetoperator.h"

IconSetOperator::IconSetOperator(
        std::unique_ptr<AbstractScannerStrategy> scannerStrategy) :
    scannerStrategy(std::move(scannerStrategy)),
    iconSet(std::move(scannerStrategy->loadIconSet()))
{
}
