#ifndef TASKDEFINITIONMASTERPANELCARDCONTROLLER_H
#define TASKDEFINITIONMASTERPANELCARDCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TaskDefinitionMasterPanelCardController : public ApplicationController
{
    Q_OBJECT
public:
    TaskDefinitionMasterPanelCardController() : ApplicationController() { }

public slots:
    void mpcSearch();
    void approveMpc();
    void createMasterPanelCard();
    void createRevisionMasterPanelCard();
    void deleteMasterPanelCard();
    void duplicateMasterPanelCard();
    void editMasterPanelCard();
    void editAttachment();
    void lockMpc();
    void unlockMpc();
    void obsoleteMasterPanelCard();
    void activateMasterPanelCard();
    void rejectApprovalMpc();
    void requestApprovalMpc();
    void restartApprovalMpc();
    void addAttachment();
    void addPanel();
    void addZone();
    void removeAttachment();
    void removePanel();
    void removeZone();
};

#endif // TASKDEFINITIONMASTERPANELCARDCONTROLLER_H
