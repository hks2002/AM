#ifndef ORGREGBODYCONTROLLER_H
#define ORGREGBODYCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OrgRegBodyController : public ApplicationController
{
    Q_OBJECT
public:
    OrgRegBodyController() : ApplicationController() { }

public slots:
    void RegBodyDocSearch();
};

#endif // ORGREGBODYCONTROLLER_H
