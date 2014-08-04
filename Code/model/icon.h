#ifndef ICON_H
#define ICON_H

#include <QString>
#include <QVector>
#include "control/abstractscannerstrategy.h"
#include "model/iconclassification.h"

class Icon
{
private:
    QString file;
    QVector<IconClassification*> *classifications;
    AbstractScannerStrategy *scannerStrategy;
public:
    Icon();
};

#endif // ICON_H
