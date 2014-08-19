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

    /*!
     * Reads all icons from a given subdirectory of the theme that is being
     * passed. Takes care of adding the correct classifications to the
     * Icon and adding that icon to the passed vector of icons.
     * \param icons The QVector<Icon>* to add the new Icon instances to.
     * The referenced object will neither be owned nor destroyed, but of course
     * modifications are being made, as long as there is at least one icon in
     * in the specified subfolder.
     * \param directory The icon set's parent directory.
     * \param subDirectory The specific sub directory to look for icons in
     * \param context The "context" IconClassification of the Icon
     * \param size The "size" IconClassification of the Icon
     */
    void readIconsFromDirectory(
            QVector<Icon>* icons,
            const QDir* directory,
            QString subDirectory,
            IconClassification* context,
            IconClassification* size
            );

    /*!
     * Checks if a line starts with a certain string and removes that string
     * from the passed line. CAUTION: Modifies the line, that has been passed!
     * \param line The line to be check and trimmed.
     * \param startsWith The start string to search for
     * \return true if line starts with specified string, false otherwise
     */
    bool startsWithAndTrim(QString& line, QString startsWith);
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
