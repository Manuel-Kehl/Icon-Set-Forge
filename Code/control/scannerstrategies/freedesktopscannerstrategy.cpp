#include <QTextStream>
#include <QImageReader>
#include <QStringList>
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
    // --------------------<Local Variables>----------------------------------//
    // The icons of the resulting IconSet
    std::unique_ptr<QVector<Icon>> icons(new QVector<Icon>());
    // The root classification of the resulting IconSet
    std::unique_ptr<IconClassification>
            classifications(new IconClassification(true));
    classifications->setName("root");

    // The 2nd level classifications of the result IconSet: "context" & "size"
    // This is where sub classifications like "apps, actions" or "22, 24, 64"
    // are to be added during the parsing process.
    // In the final step they have to be added to classifications before
    // the result IconSet is generated.
    std::unique_ptr<IconClassification>
            classificationSize(new IconClassification());
    std::unique_ptr<IconClassification>
            classificationContext(new IconClassification());

    // IconClassifications for the context and size of the recently observered
    // directory. Are reset to nullptr after they have been added to the
    // classifications variable and the next directory description is being
    // searched for.
    std::unique_ptr<IconClassification> recentContext = nullptr;
    std::unique_ptr<IconClassification> recentSize = nullptr;

    // A list that stores the directores specified in the index.theme file
    QStringList directories;
    // --------------------</Local Variables>---------------------------------//

    // Open index.theme file for read access
    if (!indexFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Return nullptr, if it was not possible to gain read access
        return nullptr;
    }

    QTextStream in(indexFile.get());
    // Read line by line until EOF
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("Directories")) {
            // Remove the "Directories=" substring
            line.remove(0, 12);
            // Tokenize the directory list
            directories = line.split(",");
        }

        // Skip to next line, if the directories variable has no valid entries
        if (directories.isEmpty()) {
            continue;
        }

        // Check if line is the beginning of a new directory description
        if (line.startsWith("[")) {
            // The line's content without "[" and "]"
            QString subDirectory(line.remove(0,1));
            subDirectory.chop(1);

            // If beginning of a new directory description
            if (directories.contains(subDirectory)) {
                // If the recentContext and recentSize of the former
                // directory have been initialized properly they have to
                // be processed, before approaching the next directory
                if (recentContext != nullptr && recentSize != nullptr) {
                    readIconsFromDirectory(
                                icons.get(),
                                directory.get(),
                                subDirectory,
                                recentContext.get(),
                                recentSize.get()
                                );

                    // Add as child and transfer ownership via std::move
                    classificationSize->addChild(std::move(recentSize));
                    classificationContext->addChild(std::move(recentContext));
                }
            }
        }
    }

    //Add context and size classifications to root classification
    classifications->addChild(std::move(classificationSize));
    classifications->addChild(std::move(classificationContext));

    std::unique_ptr<IconSet> result(new IconSet(
                                        std::move(icons),
                                        std::move(classifications))
                                    );
    return result;
}

bool FreedesktopScannerStrategy::saveIconSet(const IconSet &iconSet)
{

}

void FreedesktopScannerStrategy::readIconsFromDirectory(
        QVector<Icon> *icons,
        const QDir *directory,
        QString subDirectory,
        IconClassification *context,
        IconClassification *size)
{
    QDir destinationDirectory = *directory;
    destinationDirectory.cd(subDirectory);
    QStringList entryList = destinationDirectory.entryList(
                QDir::Files |
                QDir::NoSymLinks | //TODO: Also process symlinks in a proper way
                QDir::NoDotAndDotDot |
                QDir::Readable
                );

    // Iterate over all files in the sub directory
    for (auto file : entryList) {
        QImageReader imageReader(file);
        QImage image = imageReader.read();

        // Only proceed, if reading was successful
        // TODO: Maybe add proper error / exception handling
        if (!image.isNull()) {
            Icon newIcon(image);
            newIcon.addClassification(
                        std::shared_ptr<IconClassification>(context));
            newIcon.addClassification(
                        std::shared_ptr<IconClassification>(size));

            icons->append(newIcon);
        }
    }
}
