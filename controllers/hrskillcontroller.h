#ifndef HRSKILLCONTROLLER_H
#define HRSKILLCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HrSkillController : public ApplicationController
{
    Q_OBJECT
public:
    HrSkillController() : ApplicationController() { }

public slots:
    void skillSearch();
    void LabourSkillSearch();
};

#endif // HRSKILLCONTROLLER_H
