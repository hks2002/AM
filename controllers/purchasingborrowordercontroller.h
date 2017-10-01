#ifndef PURCHASINGBORROWORDERCONTROLLER_H
#define PURCHASINGBORROWORDERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingBorrowOrderController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingBorrowOrderController() : ApplicationController() { }

public slots:
    void createBo();
    void convertBorrowToPo();
    void convertBorrowToXchg();
    void createBoForPartRequest();
    void editBo();
};

#endif // PURCHASINGBORROWORDERCONTROLLER_H
