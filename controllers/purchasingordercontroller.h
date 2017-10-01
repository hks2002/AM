#ifndef PURCHASINGORDERCONTROLLER_H
#define PURCHASINGORDERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingOrderController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingOrderController() : ApplicationController() { }

public slots:
    void orderSearch();
    void PaymentTermsSearch();
};

#endif // PURCHASINGORDERCONTROLLER_H
