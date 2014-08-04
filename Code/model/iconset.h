#ifndef ICONSET_H
#define ICONSET_H

#include <QVector>
#include "model/icon.h"
#include "model/iconclassification.h"

class IconSet
{
private:
    QVector<IconClassification> classifications;
public:
    IconSet();
};

#endif // ICONSET_H
