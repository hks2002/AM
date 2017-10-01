#ifndef ORGOPERATORCONTROLLER_H
#define ORGOPERATORCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OrgOperatorController : public ApplicationController
{
    Q_OBJECT
public:
    OrgOperatorController() : ApplicationController() { }

public slots:
    void createOperator();
    void deleteOperator();
    void editOperator();
};

#endif // ORGOPERATORCONTROLLER_H
