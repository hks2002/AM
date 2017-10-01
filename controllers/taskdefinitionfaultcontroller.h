#ifndef TASKDEFINITIONFAULTCONTROLLER_H
#define TASKDEFINITIONFAULTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TaskDefinitionFaultController : public ApplicationController
{
    Q_OBJECT
public:
    TaskDefinitionFaultController() : ApplicationController() { }

public slots:
    void faultDefinitionSearch();
};

#endif // TASKDEFINITIONFAULTCONTROLLER_H
