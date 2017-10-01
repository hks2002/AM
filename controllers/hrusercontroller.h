#ifndef HRUSERCONTROLLER_H
#define HRUSERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HrUserController : public ApplicationController
{
    Q_OBJECT
public:
    HrUserController() : ApplicationController() { }

public slots:
    void userRoleMapSearch();
    void userSearch();
    void createUser();
    void addMyUserAttachment();
    void addUserAttachment();
    void removeMyUserAttachment();
    void removeUserAttachment();
    void editMyUserAttachment();
    void editUserAttachment();
    void openMyUserAttachment();
    void openUserAttachment();
    void editUser();
    void deleteUser();
    void toggleLockUnlock();
    void assignAuthority();
    void assignLicence();
    void assignRole();
    void assignSkill();
    void unassignAuthority();
    void unassignLicense();
    void unassignRole();
    void unassignSkill();
    void suspendedUserLicence();
    void unsuspendUserLicense();
    void updateLicence();
    void editLicenceExpiryDate();
    void editRoleOrder();
    void addPOAuthorizationLevels();
    void editPOAuthorizationLevels();
    void deletePOAuthorizationLevels();
    void printUserLicense();
    void resetPassword();
    void resetUserPassword();
    void generateCertificate();
    void revokeCertificate();
    void assignToDoList();
    void unassignToDoList();
    void orderToDoList();
    void assignMenusGroupToUser();
    void unassignMenusGroupFromUser();
    void orderMenusGroup();
    void enableDisableAction();
};

#endif // HRUSERCONTROLLER_H
