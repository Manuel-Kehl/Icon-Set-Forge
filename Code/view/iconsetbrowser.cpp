#include <QLabel>
#include <QTreeView>
#include "iconsetbrowser.h"
#include "iconsetview.h"
#include "model/iconsettreemodel.h"

IconSetBrowser::IconSetBrowser(QWidget *parent) :
    QWidget(parent)
{
    //TODO: A lot :-) This is basically to be considered testing code
    BorderLayout *layout = new BorderLayout(this);
    IconSetView *testView = new IconSetView(this);
    QTreeView *treeView = new QTreeView(this);
    IconSetTreeModel *treeModel = new IconSetTreeModel();
    treeView->setModel(treeModel);

    //Resize columns after the model has been set
    treeView->resizeColumnToContents(0);
    treeView->resizeColumnToContents(1);
    treeView->resizeColumnToContents(2);

    layout->addWidget(testView, BorderLayout::Center);
    layout->addWidget(treeView, BorderLayout::West);
}
