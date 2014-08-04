#include "model/icon.h"

Icon::Icon(QString file)
{
    this->file = file;
}

void Icon::addClassification(IconClassification *classification)
{
    this->classifications->append(classification);
}
