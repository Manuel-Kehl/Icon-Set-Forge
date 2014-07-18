#ifndef ICONSETVIEW_H
#define ICONSETVIEW_H

#include <QSettings>
#include <QScrollArea>
#include <QWidget>
#include "flowlayout.h"

class IconSetView : public QScrollArea
{
    FlowLayout *galleryLayout;
    QWidget *content;
    QSettings settings;
    Q_OBJECT
public:
    explicit IconSetView(QWidget *parent = 0);
    void addIconFromFile(QString pathToFile);

signals:

public slots:

};

#endif // ICONSETVIEW_H
