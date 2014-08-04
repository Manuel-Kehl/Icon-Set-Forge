#include "model/iconset.h"

IconSet::IconSet(AbstractScannerStrategy *scannerStrategy)
{
    this->scannerStrategy = scannerStrategy;
    updateIconSet();
}

void IconSet::updateIconSet()
{
    classifications = scannerStrategy->scanClassifications();
    icons = scannerStrategy->scanIcons();
}
