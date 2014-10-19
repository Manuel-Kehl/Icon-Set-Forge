#include <QLabel>
#include <QTreeView>
#include <memory>
#include "iconsetbrowser.h"
#include "model/access/classificationtreemodel.h"
#include "model/access/iconfilterproxymodel.h"

IconSetBrowser::IconSetBrowser(IconFilterProxyModel *iconModel,
                               ClassificationTreeModel *classificationModel,
                               QWidget *parent) :    QWidget(parent)
{
    // TODO: A lot :-) This is basically to be considered testing code
    BorderLayout *layout = new BorderLayout(this);

    // List Views
    listView = new QListView(this);

    // Set up List View to display Icons
    listView->setViewMode(QListView::IconMode);
    listView->setGridSize(QSize(100, 100));
    listView->setResizeMode(QListView::Adjust);
    listView->setWordWrap(true);
    listView->setModel(iconModel);

    // Tree View
    QTreeView *treeView = new QTreeView(this);
    treeView->setModel(classificationModel);

    // Resize columns after the model has been set
    treeView->resizeColumnToContents(0);
    treeView->resizeColumnToContents(1);
    treeView->resizeColumnToContents(2);

    layout->addWidget(listView, BorderLayout::Center);
    layout->addWidget(treeView, BorderLayout::West);
}

QModelIndexList IconSetBrowser::getSelectedIcons()
{
    return listView->selectionModel()->selectedIndexes();
}
