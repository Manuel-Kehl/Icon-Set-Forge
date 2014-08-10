#ifndef ICON_H
#define ICON_H

#include <QString>
#include "model/iconclassification.h"

class Icon
{
private:
    QString file;
    IconClassification* classifications;
public:
    Icon();
    Icon(QString file);
    void addClassification(IconClassification *classification);
};

#endif // ICON_H
