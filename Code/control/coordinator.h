#ifndef COORDINATOR_H
#define COORDINATOR_H

#include <QObject>
#include <QVector>
#include <memory>
#include "control/iconsetoperator.h"
#include "scannerstrategies/abstractscannerstrategy.h"
#include "model/access/classificationtreemodel.h"
#include "model/access/iconlistmodel.h"

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

public slots:
    /*!
     * This function displays a filechooser and opens the selected IconSet.
     * The resulting instance is thereafter maintained by this class.
     */
    void openIconSet();

signals:
    void newIconSetOpened(IconListModel *iconModel,
                          ClassificationTreeModel *ClassificationModel);

};

#endif // COORDINATOR_H
