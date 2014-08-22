# View Design

The original view implementation is to be considered a "first encouter with Qt Widgets" or "proof of concept" and will naturally be heavily refactored in the following development stages.


## QListView for Displaying Icons

A [QListView](http://qt-project.org/doc/qt-4.8/qlistview.html) seems to be properly suited for displaying icons in place of the inital approach with a GridLayout of QLabels.

One major advantage is the fact, that one can make use of [Qt's Model/View framework](http://qt-project.org/doc/qt-4.8/model-view-programming.html). Therefore another special model implementation (probably derived from [QAbstractListModel](http://qt-project.org/doc/qt-4.8/qabstractlistmodel.html)) is necessary, to provide data for the `QListView`.

Maybe one can handle **filtering** by adding an implementation of [QAbstractProxyModel](http://qt-project.org/doc/qt-4.8/qabstractproxymodel.html). Further investigation has to be done in that regard.

### Edit

No ProxyModel classes are necessary, as the [`access` model classes](MVC.md) could easily vary the returned data according to the connected `IconSet` instances' classifications' filter and group flags.