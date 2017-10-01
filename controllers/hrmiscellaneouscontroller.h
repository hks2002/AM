#ifndef HRMISCELLANEOUSCONTROLLER_H
#define HRMISCELLANEOUSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HrMiscellaneousController : public ApplicationController
{
    Q_OBJECT
public:
    HrMiscellaneousController() : ApplicationController() { }

public slots:
    void myUserDetailsSearch();
    void myToDoList();
};

#endif // HRMISCELLANEOUSCONTROLLER_H
