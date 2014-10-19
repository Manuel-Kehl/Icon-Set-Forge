#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/access/classificationtreemodel.h"
#include "model/access/iconfilterproxymodel.h"

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
    /*!
     * To be called when an IconSet is to be displayed in a new Tab.
     * \param iconModel The Icon data.
     * \param classificationModel The IconClassification data.
     */
    void displayNewIconSet(IconFilterProxyModel *iconModel,
                           ClassificationTreeModel *classificationModel);
signals:
    /*!
     * This signal is emitted when the "openIconSet" action has been triggered.
     */
    void actionOpenIconSet();
    void actionDeleteIcon(int index, int count);

private slots:
    void on_actionDeleteIcon_triggered();
};

#endif // MAINWINDOW_H
