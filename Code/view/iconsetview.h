#ifndef ICONSETVIEW_H
#define ICONSETVIEW_H

#include <QSettings>
#include <QScrollArea>
#include <QWidget>
#include "layouts/flowlayout.h"

/*!
 * A specialised derivate of QScrollArea, that is targeted towards displaying
 * icons in a GridLayout.
 * Right now it is a very basic implementation, but more functionality
 * will be added soon.
 */
class IconSetView : public QScrollArea
{
    Q_OBJECT

private:
    FlowLayout *galleryLayout;
    QWidget *galleryWidget;
    /*!
     * Used to access the applications settings.
     * It was made a member instead of local instantiation, because it is
     * probably going to be needed more often as configuration options grow.
     */
    QSettings settings;

public:
    /*
     * TODO: Think about redesigning the class in a way that it is passed
     * an IconSet instance once which it uses to load the icons.
     */
    explicit IconSetView(QWidget *parent = 0);
    //! Loads an icon that is located under a specific file path
    void addIconFromFile(QString pathToFile);

signals:

public slots:

};

#endif // ICONSETVIEW_H
