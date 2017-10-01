#ifndef TASKDEFINITIONREQUIREMENTCONTROLLER_H
#define TASKDEFINITIONREQUIREMENTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TaskDefinitionRequirementController : public ApplicationController
{
    Q_OBJECT
public:
    TaskDefinitionRequirementController() : ApplicationController() { }

public slots:
    void requirementSearch();
    void createReq();
    void createReqRevision();
    void deleteReq();
    void duplicateReq();
    void editReq();
    void initializeReq();
    void activateReq();
    void moveReq();
    void obsoleteReq();
    void approveReq();
    void rejectApprovalReq();
    void reqLock();
    void reqUnlock();
    void requestApprovalReq();
    void restartApprovalReq();
    void addComplianceToRefDoc();
    void addAttachment();
    void addFollowingTask();
    void addLabourRequirement();
    void addMeasurement();
    void addMeasureSpecificSchedulingRule();
    void addPanel();
    void addPartRequirement();
    void addPartSpecificSchedulingRule();
    void addPartTransformation();
    void addSchedulingRule();
    void addStep();
    void addTailNoSpecificSchedRule();
    void addTooluirement();
    void addZone();
    void addTaskDependenceRelation();
    void editReqMeasurementOrder();
    void changeReqStepOrder();
    void editAttachment();
    void editLabourRequirement();
    void editMeasureSpecificSchedulingRule();
    void editPartRequirement();
    void editPartSpecificSchedulingRule();
    void editSchedulingRules();
    void editStep();
    void editTailNoSpecificSchedRule();
    void editToolRequirement();
    void printImpactReport();
    void removeComplianceFromRefDoc();
    void removeAttachment();
    void removeFollowingTask();
    void removeLabourRequirement();
    void removeMeasurement();
    void removeMeasureSpecificSchedulingRule();
    void removePanel();
    void removePartRequirement();
    void removePartSpecificSchedulingRule();
    void removePartTransformation();
    void removeSchedulingRule();
    void removeStep();
    void removeTailNoSpecificSchedRule();
    void removeToolRequirement();
    void removeReqZone();
    void removeTaskDependenceRelation();
    void assignReqPart();
    void unassignReqPart();
    void unassignRefDocConfigSlot();
    void unassignRefDocPart();
    void addNrLaborEstimation();
    void allowTaskDefinitionExecution();
    void editNrLaborEstimation();
    void removeNrLaborEstimation();
    void preventTaskDefinitionExecution();
    void showTaskLabourSummary();
};

#endif // TASKDEFINITIONREQUIREMENTCONTROLLER_H
