#ifndef PARTSSTOCKNUMBERCONTROLLER_H
#define PARTSSTOCKNUMBERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PartsStockNumberController : public ApplicationController
{
    Q_OBJECT
public:
    PartsStockNumberController() : ApplicationController() { }

public slots:
    void stockSearch();
    void createStockNum();
    void editStockNum();
    void deleteStockNum();
    void createStockLevel();
    void editStockLevel();
    void calcStockLevels();
    void checkStockLevel();
    void removeStockLevel();
    void adjustStockPercentage();
    void assignPartToStockNum();
    void unassignPartFromStockNum();
};

#endif // PARTSSTOCKNUMBERCONTROLLER_H
