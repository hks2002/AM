#ifndef ORGAUTHORITYCONTROLLER_H
#define ORGAUTHORITYCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OrgAuthorityController : public ApplicationController
{
    Q_OBJECT
public:
    OrgAuthorityController() : ApplicationController() { }

public slots:
    void authoritySearch();
    void createAuthority();
    void assignFcmodelAuthority();
    void assignInvAuthority();
    void assignUserAuthority();
    void deleteAuthority();
    void editAuthority();
    void unassignFcmodelAuthority();
    void unassignInvAuthority();
    void unassignUserAuthority();
};

#endif // ORGAUTHORITYCONTROLLER_H
