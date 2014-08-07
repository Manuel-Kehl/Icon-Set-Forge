#ifndef ICONSET_H
#define ICONSET_H

#include <QVector>
#include <QSharedPointer>
#include "model/icon.h"
#include "model/iconclassification.h"
#include "control/scannerstrategies/abstractscannerstrategy.h"

class IconSet
{
private:
    QVector<QSharedPointer<Icon>> icons;
    IconClassification classifications;
    AbstractScannerStrategy *scannerStrategy;
public:
    IconSet(AbstractScannerStrategy *scannerStrategy);
    void updateIconSet();
};

#endif // ICONSET_H
