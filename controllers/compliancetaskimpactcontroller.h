#ifndef COMPLIANCETASKIMPACTCONTROLLER_H
#define COMPLIANCETASKIMPACTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ComplianceTaskImpactController : public ApplicationController
{
    Q_OBJECT
public:
    ComplianceTaskImpactController() : ApplicationController() { }

public slots:
    void addHistoricTask();
    void addRefDoc();
    void addReq();
    void addTask();
    void editHistoricTask();
    void editRefDoc();
    void editReq();
    void editTask();
    void removeHistoricTask();
    void removeRefDoc();
    void removeReq();
    void removeTask();
    void viewComplianceReport();
};

#endif // COMPLIANCETASKIMPACTCONTROLLER_H
