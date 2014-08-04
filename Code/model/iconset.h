#ifndef ICONSET_H
#define ICONSET_H

#include <QVector>
#include "model/icon.h"
#include "model/iconclassification.h"
#include "control/abstractscannerstrategy.h"

class IconSet
{
private:
    QVector<Icon> icons;
    QVector<IconClassification> classifications;
    AbstractScannerStrategy *scannerStrategy;
public:
    IconSet(AbstractScannerStrategy *scannerStrategy);
    void updateIconSet();
};

#endif // ICONSET_H
