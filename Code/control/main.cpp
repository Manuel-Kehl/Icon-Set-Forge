#include "view/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("mank319");
    QCoreApplication::setOrganizationDomain("manuel-kehl.de");
    QCoreApplication::setApplicationName("Icon Set Forge");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
