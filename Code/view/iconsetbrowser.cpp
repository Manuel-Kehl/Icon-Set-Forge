#include <QLabel>
#include <QTreeView>
#include <QListView>
#include "iconsetbrowser.h"
#include "model/iconset.h"
#include "model/access/classificationtreemodel.h"
#include "model/access/iconlistmodel.h"

IconSetBrowser::IconSetBrowser(QWidget *parent) :
    QWidget(parent)
{
    // TODO: A lot :-) This is basically to be considered testing code
    BorderLayout *layout = new BorderLayout(this);

    // List View
    QListView *listView = new QListView(this);
    IconSet *iconSet = new IconSet();
    IconListModel *listModel = new IconListModel(this, iconSet);
    listView->setModel(listModel);

    // Tree View
    QTreeView *treeView = new QTreeView(this);
    ClassificationTreeModel *treeModel = new ClassificationTreeModel(this);
    treeView->setModel(treeModel);

    // Resize columns after the model has been set
    treeView->resizeColumnToContents(0);
    treeView->resizeColumnToContents(1);
    treeView->resizeColumnToContents(2);


    layout->addWidget(listView, BorderLayout::Center);
    layout->addWidget(treeView, BorderLayout::West);
}
