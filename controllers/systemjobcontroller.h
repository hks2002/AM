#ifndef SYSTEMJOBCONTROLLER_H
#define SYSTEMJOBCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SystemJobController : public ApplicationController
{
    Q_OBJECT
public:
    SystemJobController() : ApplicationController() { }

public slots:
    void workItemAdminConsole();
    void resetJobs();
    void runJobs();
};

#endif // SYSTEMJOBCONTROLLER_H
