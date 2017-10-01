#ifndef MAINTHISTORICEDITINGCONTROLLER_H
#define MAINTHISTORICEDITINGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MaintHistoricEditingController : public ApplicationController
{
    Q_OBJECT
public:
    MaintHistoricEditingController() : ApplicationController() { }

public slots:
    void addHistoricOperationRestriction();
    void addHistoricPartRequirement();
    void addHistoricTaskMesurment();
    void addHistoricTaskPanel();
    void addHistoricTaskImpact();
    void addHistoricTaskZone();
    void addNotesToHistoricTask();
    void assignFaultToCompletedCheck();
    void assignTaskToCompletedCheck();
    void createHistoricAssignedFault();
    void createHistoricFault();
    void createHistoricWorkpackage();
    void createHistoricTask();
    void editHistoricWorkpackage();
    void editHistoricWorkpackageAttachment();
    void editHistoricFault();
    void editHistoricLabourHistory();
    void editHistoricLabourInformation();
    void editHistoricPartRequirement();
    void editHistoricTaskAction();
    void editHistoricTaskAttachment();
    void editHistoricTaskInformation();
    void editHistoricTaskInstruction();
    void editHistoricTaskMeasurement();
    void editHistoricTaskImpact();
    void packageAndCompleteFault();
    void packageAndCompleteTask();
    void removeHistoricTaskPartRequirement();
    void removeHistoricTaskMesurment();
    void removeHistoricTaskPanel();
    void removeHistoricTaskImpact();
    void removeHistoricTaskZone();
    void unassignFaultFromCompletedCheck();
    void unassignTaskFromCompletedCheck();
    void uncollectJicHistoric();
};

#endif // MAINTHISTORICEDITINGCONTROLLER_H
