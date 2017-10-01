#ifndef TASKDEFINITIONBLOCKCONTROLLER_H
#define TASKDEFINITIONBLOCKCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TaskDefinitionBlockController : public ApplicationController
{
    Q_OBJECT
public:
    TaskDefinitionBlockController() : ApplicationController() { }

public slots:
    void createBlock();
    void createBlockRevision();
    void deleteBlock();
    void duplicateBlock();
    void editBlock();
    void activateBlock();
    void initializeBlock();
    void lockBlock();
    void unlockBlock();
    void approveBlock();
    void moveBlock();
    void obsoleteBlock();
    void rejectApprovalBlock();
    void requestApprovalBlock();
    void restartApprovalBlock();
    void addAttachment();
    void addPartSpecificSchedulingRule();
    void addSchedulingRule();
    void addTailNoSpecificSchedRule();
    void addReqToBlock();
    void editBlockAttachment();
    void editPartSpecificSchedulingRule();
    void editSchedulingRules();
    void editTailNoSpecificSchedRule();
    void editReqMapping();
    void removeAttachment();
    void removePartSpecificSchedulingRule();
    void removeSchedulingRule();
    void removeTailNoSpecificSchedRule();
    void removeReqFromBlock();
};

#endif // TASKDEFINITIONBLOCKCONTROLLER_H
