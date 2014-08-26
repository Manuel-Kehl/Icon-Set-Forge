#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view/iconsetbrowser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Connect the action's trigger signal to this classes public "open" signal
    QObject::connect(ui->actionOpen, SIGNAL(triggered()),
                     this, SIGNAL(actionOpenIconSet()));
    QObject::connect(ui->actionDeleteIcon, SIGNAL(triggered()),
                     this, SIGNAL(actionDeleteIcon()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayNewIconSet(IconListModel *iconModel,
                                   ClassificationTreeModel *classificationModel)
{
    IconSetBrowser *newTab =
            new IconSetBrowser(iconModel, classificationModel, this);
    ui->tabWidget->addTab(newTab, "Icon Set");
}
