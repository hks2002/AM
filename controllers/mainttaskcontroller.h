#ifndef MAINTTASKCONTROLLER_H
#define MAINTTASKCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MaintTaskController : public ApplicationController
{
    Q_OBJECT
public:
    MaintTaskController() : ApplicationController() { }

public slots:
    void addInstalledPart();
    void addLabourRequirement();
    void addNotesToTask();
    void addPartRequirement();
    void addRemovedPart();
    void addTaskDeadline();
    void addTaskMeasurement();
    void addTaskPanel();
    void addTaskStep();
    void addTaskToolRequirement();
    void addTaskZone();
    void addTaskImpact();
    void adjustHoursBilling();
    void allowActualTaskExecution();
    void assignLabour();
    void unassignLabour();
    void assignOpprtnstcTaskToPackage();
    void assignTaskTool();
    void assignTaskToCheck();
    void assignTaskToComponentWorkOrder();
    void cancelTaskOrFault();
    void finishTask();
    void inspectTask();
    void rIITask();
    void changeTaskName();
    void changeTaskStepOrder();
    void collectJic();
    void createAssignedTask();
    void createCheckForFaultOrTask();
    void createPartRequest();
    void createRemovalTaskForInventory();
    void createRepetitiveTaskForFault();
    void createUnassignedAdhocTask();
    void createUnassignedTaskAsNA();
    void createUnassignedTaskFromDefn();
    void editLabourRequirement();
    void editPartRequirement();
    void editSignedPartRequirement();
    void editTaskAction();
    void editTaskAttachments();
    void editTaskInformation();
    void editTaskInstructions();
    void editTaskInterval();
    void editTaskStartValues();
    void editTaskMeasurement();
    void editTaskStep();
    void editTaskImpact();
    void editTaskToolRequirement();
    void editWorkscopeOrder();
    void editWorkcaptureStartValue();
    void editWorkCaptured();
    void editWorkCapturedAfterRelease();
    void editWorkCapturedAfterTaskComplete();
    void editWorkCapturedOnBehalfOf();
    void enableManualScheduling();
    void extendDeadlines();
    void initializeTaskDefinition();
    void initializeTaskWarranty();
    void markAsAdjustBilling();
    void markAsNotApplicable();
    void markAsError();
    void moveDownWorkscopeOrder();
    void moveUpWorkscopeOrder();
    void partsNotReady();
    void partsReady();
    void pauseTask();
    void preventActualTaskExecution();
    void previewTaskCards();
    void printSelectedTaskCards();
    void printTallySheet();
    void printTaskCards();
    void removeInstalledPart();
    void removeLabourRequirement();
    void removePartRequirement();
    void removeRemovedPart();
    void removeTaskDeadline();
    void removeTaskMeasurement();
    void removeTaskPanel();
    void removeTaskStep();
    void removeTaskToolRequirement();
    void removeTaskZone();
    void removeTaskImpact();
    void reschedTask();
    void resetToBaselineDeadline();
    void reviewWorkCaptured();
    void setPlanByDate();
    void setTaskPriority();
    void startTask();
    void terminateTask();
    void toggleSoftDeadline();
    void toolsNotReady();
    void toolsReady();
    void unassignTaskFromCheck();
    void unassignTaskFromComponentWorkOrder();
    void unassignTaskTool();
    void uncollectJic();
    void unlockTask();
    void viewOpportunisticTasks();
    void batchCompleteTask();
    void completeCheckAndSubtasks();
    void completeTask();
};

#endif // MAINTTASKCONTROLLER_H
