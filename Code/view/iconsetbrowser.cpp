#include "iconsetbrowser.h"
#include "iconsetview.h"
#include <QLabel>

IconSetBrowser::IconSetBrowser(QWidget *parent) :
    QWidget(parent)
{
    //TODO: A lot :-)
    BorderLayout *layout = new BorderLayout(this);
    IconSetView *testView = new IconSetView(this);

    layout->addWidget(testView, BorderLayout::Center);
}
