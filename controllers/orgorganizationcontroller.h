#ifndef ORGORGANIZATIONCONTROLLER_H
#define ORGORGANIZATIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OrgOrganizationController : public ApplicationController
{
    Q_OBJECT
public:
    OrgOrganizationController() : ApplicationController() { }

public slots:
    void organizationSearch();
    void createOrg();
    void editOrg();
    void deleteOrg();
    void assignDepartment();
    void unassignDepartment();
    void assignSubOrg();
    void unassignSubOrg();
    void assignAddress();
    void unassignAddress();
    void assignContactor();
    void unassignContactor();
    void assignVendorToOrganization();
    void unassignVendorFromOrganization();
};

#endif // ORGORGANIZATIONCONTROLLER_H
