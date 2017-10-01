#ifndef HRROLECONTROLLER_H
#define HRROLECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HrRoleController : public ApplicationController
{
    Q_OBJECT
public:
    HrRoleController() : ApplicationController() { }

public slots:
    void roleSearch();
    void createRole();
    void eidtRole();
    void deleteRole();
    void assignUser();
    void unassignUser();
    void assignToDoList();
    void unassignToDoList();
    void orderToDoList();
    void assignMenusGroupToUser();
    void unassignMenusGroupFromUser();
    void orderMenusGroup();
    void enableDisableAction();
};

#endif // HRROLECONTROLLER_H
