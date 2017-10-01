#ifndef PURCHASINGCONSIGNMENTCONTROLLER_H
#define PURCHASINGCONSIGNMENTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingConsignmentController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingConsignmentController() : ApplicationController() { }

public slots:
    void createAdhocConsignOrder();
    void createConsignOrderForPartRequest();
    void editConsignOrder();
};

#endif // PURCHASINGCONSIGNMENTCONTROLLER_H
