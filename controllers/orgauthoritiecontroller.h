#ifndef ORGAUTHORITIECONTROLLER_H
#define ORGAUTHORITIECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OrgAuthoritieController : public ApplicationController
{
    Q_OBJECT
public:
    OrgAuthoritieController() : ApplicationController() { }

public slots:
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

#endif // ORGAUTHORITIECONTROLLER_H
