#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view/iconsetbrowser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
}

void MainWindow::displayNewIconSet(IconListModel *iconModel,
                                   ClassificationTreeModel *classificationModel)
{
    IconSetBrowser *newTab =
            new IconSetBrowser(iconModel, classificationModel, this);
    ui->tabWidget->addTab(newTab, "Icon Set");
}
