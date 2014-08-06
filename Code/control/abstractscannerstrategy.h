#ifndef ABSTRACTSCANNERSTRATEGY_H
#define ABSTRACTSCANNERSTRATEGY_H

#include <QVector>
#include "model/iconclassification.h"
#include "model/icon.h"

class AbstractScannerStrategy
{
public:
    AbstractScannerStrategy();
    virtual QVector<Icon> scanIcons() = 0;
    virtual IconClassification scanClassifications() = 0;
};

#endif // ABSTRACTSCANNERSTRATEGY_H
