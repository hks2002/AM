#ifndef PURCHASINGCONSIGNMENTEXCHANGECONTROLLER_H
#define PURCHASINGCONSIGNMENTEXCHANGECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingConsignmentExchangeController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingConsignmentExchangeController() : ApplicationController() { }

public slots:
    void createConsignExchangeOrder();
    void editConsginXchgOrder();
    void editToBeReturnedConsignPart();
};

#endif // PURCHASINGCONSIGNMENTEXCHANGECONTROLLER_H
