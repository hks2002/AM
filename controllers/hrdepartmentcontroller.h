#ifndef HRDEPARTMENTCONTROLLER_H
#define HRDEPARTMENTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HrDepartmentController : public ApplicationController
{
    Q_OBJECT
public:
    HrDepartmentController() : ApplicationController() { }

public slots:
    void departmentSearch();
    void createDepartment();
    void deleteDepartment();
    void editDepartment();
    void assignSubDepartment();
    void unassignSubDepartment();
    void assignOrg();
    void unassignOrg();
    void assignUsers();
    void unassignUsers();
};

#endif // HRDEPARTMENTCONTROLLER_H
