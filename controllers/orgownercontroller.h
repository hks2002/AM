#ifndef ORGOWNERCONTROLLER_H
#define ORGOWNERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OrgOwnerController : public ApplicationController
{
    Q_OBJECT
public:
    OrgOwnerController() : ApplicationController() { }

public slots:
    void ownerSearch();
    void createOwner();
    void deleteOwner();
    void editOwner();
};

#endif // ORGOWNERCONTROLLER_H
