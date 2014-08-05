#ifndef ICON_H
#define ICON_H

#include <QString>
#include <QVector>
#include "model/iconclassification.h"

class Icon
{
private:
    QString file;
    QVector<IconClassification*> *classifications;
public:
    Icon();
    Icon(QString file);
    void addClassification(IconClassification *classification);
};

#endif // ICON_H
