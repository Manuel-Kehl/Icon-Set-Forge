#ifndef ABSTRACTSCANNERSTRATEGY_H
#define ABSTRACTSCANNERSTRATEGY_H

class AbstractScannerStrategy
{
public:
    AbstractScannerStrategy();
    virtual void scanIcons() = 0;
    virtual void scanClassifications() = 0;
};

#endif // ABSTRACTSCANNERSTRATEGY_H
