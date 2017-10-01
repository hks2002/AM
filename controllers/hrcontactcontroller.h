#ifndef HRCONTACTCONTROLLER_H
#define HRCONTACTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HrContactController : public ApplicationController
{
    Q_OBJECT
public:
    HrContactController() : ApplicationController() { }

public slots:
    void createContactor();
    void editContactor();
    void deleteContactor();
};

#endif // HRCONTACTCONTROLLER_H
