#ifndef HRAPPROVALLEVELSCONTROLLER_H
#define HRAPPROVALLEVELSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HrApprovalLevelsController : public ApplicationController
{
    Q_OBJECT
public:
    HrApprovalLevelsController() : ApplicationController() { }

public slots:
    void approvalLevelsSearch();
};

#endif // HRAPPROVALLEVELSCONTROLLER_H
