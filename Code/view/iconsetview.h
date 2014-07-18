#ifndef ICONSETVIEW_H
#define ICONSETVIEW_H

#include <QSettings>
#include <QScrollArea>
#include <QWidget>
#include "layouts/flowlayout.h"

class IconSetView : public QScrollArea
{
    Q_OBJECT

private:
    FlowLayout *galleryLayout;
    QWidget *galleryWidget;
    QSettings settings;

public:
    explicit IconSetView(QWidget *parent = 0);
    void addIconFromFile(QString pathToFile);

signals:

public slots:

};

#endif // ICONSETVIEW_H
