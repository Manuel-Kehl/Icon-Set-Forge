#include <QLabel>
#include <QTreeView>
#include "iconsetbrowser.h"
#include "iconsetview.h"
#include "model/iconsettreemodel.h"

IconSetBrowser::IconSetBrowser(QWidget *parent) :
    QWidget(parent)
{
    //TODO: A lot :-)
    BorderLayout *layout = new BorderLayout(this);
    IconSetView *testView = new IconSetView(this);
    QTreeView *treeView = new QTreeView(this);
    IconSetTreeModel *treeModel = new IconSetTreeModel();
    treeView->setModel(treeModel);

    layout->addWidget(testView, BorderLayout::Center);
    layout->addWidget(treeView, BorderLayout::West);
}
