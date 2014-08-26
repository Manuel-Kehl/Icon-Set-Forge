#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/access/classificationtreemodel.h"
#include "model/access/iconlistmodel.h"

namespace Ui {
class MainWindow;
}

/*!
 * The main user interface class of the application.
 * It provides a context for loading (multiple) icon sets and a menu
 * to interact with.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_actionOpen_triggered();

public slots:
    void displayNewIconSet(IconListModel *iconModel,
                           ClassificationTreeModel *classificationModel);
signals:
    void actionOpenIconSet();

};

#endif // MAINWINDOW_H
