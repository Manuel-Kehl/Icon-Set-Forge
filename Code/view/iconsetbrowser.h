#ifndef ICONSETBROWSER_H
#define ICONSETBROWSER_H

#include <QWidget>
#include <QListView>
#include <QModelIndexList>
#include "layouts/borderlayout.h"
#include "model/access/classificationtreemodel.h"
#include "model/access/iconlistmodel.h"

/*!
 * A special QWidget derivate that contains an IconSetView and a QTreeView
 * for filtering and grouping the icons by different classifications.
 * Every IconSet that is being loaded is displayed in an extra tab, that
 * contains one instance of this widget for displaying the icon set.
 */
class IconSetBrowser : public QWidget
{
    Q_OBJECT
private:
    //! The QListView responsible for displaying the icons
    QListView *listView;

public:
    explicit IconSetBrowser(IconListModel *iconModel,
                            ClassificationTreeModel *classificationModel,
                            QWidget *parent = 0);

    /*!
     * Returns the index of the currently selected Icon.
     */
    QModelIndexList getSelectedIcons();
signals:

public slots:

};

#endif // ICONSETBROWSER_H
