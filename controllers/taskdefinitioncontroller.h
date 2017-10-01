#ifndef TASKDEFINITIONCONTROLLER_H
#define TASKDEFINITIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TaskDefinitionController : public ApplicationController
{
    Q_OBJECT
public:
    TaskDefinitionController() : ApplicationController() { }

public slots:
    void taskDefinitionSearch();
    void TaskOriginatorSearch();
    void TaskSubclassSearch();
    void WorkTypeSearch();
    void previewTaskDefinition();
    void hideDifferences();
    void showDifferences();
    void tagTaskDefinition();
    void untagTaskDefinition();
    void viewTaskHierarchy();
};

#endif // TASKDEFINITIONCONTROLLER_H
