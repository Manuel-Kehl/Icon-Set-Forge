#include "freedesktopscannerstrategy.h"
#include "model/iconclassification.h"

FreedesktopScannerStrategy::FreedesktopScannerStrategy(QString themeLocation)
{
    if (themeLocation.endsWith("index.theme")) {
        // If path to index.theme has been passed
        // Directly assign indexFile
        std::unique_ptr<QFile> pIndexFile(new QFile(themeLocation));
        this->indexFile = std::move(pIndexFile);

        // And deduce directory from passed parameter
        QFileInfo fileInfo(themeLocation);
        std::unique_ptr<QDir> pDirectory(new QDir(fileInfo.dir()));
        this->directory = std::move(pDirectory);
    } else {
        // If path to directory has been passed
        // Directly assign directory
        std::unique_ptr<QDir> pDirectory(new QDir(themeLocation));
        this->directory = std::move(pDirectory);

        //And deduce indexFile from passed parameter
        std::unique_ptr<QFile> pIndexFile(
                    new QFile(themeLocation + "/index.theme"));
        this->indexFile = std::move(pIndexFile);
    }
}

std::unique_ptr<IconSet> FreedesktopScannerStrategy::loadIconSet()
{

}

bool FreedesktopScannerStrategy::saveIconSet(const IconSet &iconSet)
{

}
