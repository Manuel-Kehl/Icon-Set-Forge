#include "model/iconset.h"

IconSet::IconSet(std::unique_ptr<AbstractScannerStrategy> scannerStrategy)
{
    // Transfer ownership from the argument to the member variable
    this->scannerStrategy = std::move(scannerStrategy);
    updateIconSet();
}

void IconSet::updateIconSet()
{
    // Transfer ownership of return values. Rvalues are move implicitly
    this->classifications = scannerStrategy->scanClassifications();
    this->icons = scannerStrategy->scanIcons();
}
