#ifndef FREEDESKTOPSCANNERSTRATEGY_H
#define FREEDESKTOPSCANNERSTRATEGY_H

#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <memory>
#include "abstractscannerstrategy.h"

class FreedesktopScannerStrategy : public AbstractScannerStrategy
{
private:
    std::unique_ptr<QDir> directory;
    std::unique_ptr<QFile> indexFile;

public:
    /*!
     * Creates a FreedesktopScannerStrategy for the given theme location.
     * \param themeLocation Can be either the index.theme file or the
     * theme's parent directory.
     */
    FreedesktopScannerStrategy(QString themeLocation);

    // Overrides of AbstractScannerStrategy Methods
    std::unique_ptr<IconSet> loadIconSet();
    bool saveIconSet(const IconSet &iconSet);
};

#endif // FREEDESKTOPSCANNERSTRATEGY_H
