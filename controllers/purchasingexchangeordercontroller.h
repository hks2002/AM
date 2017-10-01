#ifndef PURCHASINGEXCHANGEORDERCONTROLLER_H
#define PURCHASINGEXCHANGEORDERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingExchangeOrderController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingExchangeOrderController() : ApplicationController() { }

public slots:
    void createEo();
    void convertPoToXchg();
    void convertXchgToPo();
    void createEoForInv();
    void createEoForPartRequest();
    void createRemovalTaskForReturnInventory();
    void editEo();
    void selectReturnInventory();
};

#endif // PURCHASINGEXCHANGEORDERCONTROLLER_H
