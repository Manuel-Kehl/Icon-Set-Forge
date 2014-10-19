#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QModelIndexList>
#include <QModelIndex>
#include "view/iconsetbrowser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Connect the action's trigger signal to this classes public "open" signal
    QObject::connect(ui->actionOpen, SIGNAL(triggered()),
                     this, SIGNAL(actionOpenIconSet()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayNewIconSet(IconFilterProxyModel *iconModel,
                                   ClassificationTreeModel *classificationModel)
{
    IconSetBrowser *newTab =
            new IconSetBrowser(iconModel, classificationModel, this);
    ui->tabWidget->addTab(newTab, "Icon Set");
}

void MainWindow::on_actionDeleteIcon_triggered()
{
    IconSetBrowser *browser =
            static_cast<IconSetBrowser*>(ui->tabWidget->currentWidget());
    QModelIndexList selectedIcons = browser->getSelectedIcons();

    for (auto selected : selectedIcons) {
        int index = selected.row();
        //OPTIMIZE: Maybe check for coherent ranges and pass count parameter
        emit actionDeleteIcon(index, 1);
    }
}
