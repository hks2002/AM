#ifndef SUPPLYCYCLECOUNTCONTROLLER_H
#define SUPPLYCYCLECOUNTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SupplyCycleCountController : public ApplicationController
{
    Q_OBJECT
public:
    SupplyCycleCountController() : ApplicationController() { }

public slots:
    void rotableAdjustment();
    void foundUnexpPart();
    void ignoreDiscrepancy();
    void loadCountResults();
    void loadFullCountResults();
    void performCorrections();
    void performCount();
    void performRecount();
    void requestRecount();
    void setNextCountDate();
    void viewRecountResults();
};

#endif // SUPPLYCYCLECOUNTCONTROLLER_H
