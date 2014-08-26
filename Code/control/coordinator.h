#ifndef COORDINATOR_H
#define COORDINATOR_H

#include <QObject>
#include <QVector>
#include <memory>
#include "control/iconsetoperator.h"
#include "scannerstrategies/abstractscannerstrategy.h"

class Coordinator : public QObject
{
    Q_OBJECT
private:
    int activeIconSetIndex;
    QVector<std::shared_ptr<IconSetOperator>> openedIconSets;

public:
    explicit Coordinator(QObject *parent = 0);
    /*!
     * This function is responsible for opening an IconSet.
     * The resulting instance is thereafter maintained by this class.
     */
    void openIconSet(std::unique_ptr<AbstractScannerStrategy> scannerStrategy);
    /*!
     * This function displays a filechooser and opens the selected IconSet.
     * The resulting instance is thereafter maintained by this class.
     */
    void openIconSet();

public slots:
    //TODO: Define slots as described in the class diagram

};

#endif // COORDINATOR_H
