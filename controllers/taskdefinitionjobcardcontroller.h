#ifndef TASKDEFINITIONJOBCARDCONTROLLER_H
#define TASKDEFINITIONJOBCARDCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TaskDefinitionJobCardController : public ApplicationController
{
    Q_OBJECT
public:
    TaskDefinitionJobCardController() : ApplicationController() { }

public slots:
    void jobCardSearch();
    void createJic();
    void createJicRevision();
    void deleteJic();
    void duplicateJic();
    void editJic();
    void lockJic();
    void unlockJic();
    void moveJic();
    void obsoleteJic();
    void rejectApprovalJic();
    void requestApprovalJic();
    void restartApprovalJic();
    void approveJic();
    void activateJic();
    void addAttachment();
    void addLabourRequirement();
    void addMeasurement();
    void addPanel();
    void addPartRequirement();
    void addStep();
    void addFigure();
    void addToolRequirement();
    void addZone();
    void addJobCardToRequirement();
    void editAttachment();
    void changeJicStepOrder();
    void editLabourRequirement();
    void editStepOrder();
    void editPartRequirement();
    void editStep();
    void editFigure();
    void editToolRequirement();
    void removeAttachment();
    void removeLabourRequirement();
    void removeMeasurement();
    void removePanel();
    void removePartRequirement();
    void removeStep();
    void removeFigure();
    void removeToolRequirement();
    void removeZone();
    void removeJobCardFromRequirement();
    void showTaskLabourSummary();
    void copyDataFromRequirement();
};

#endif // TASKDEFINITIONJOBCARDCONTROLLER_H
