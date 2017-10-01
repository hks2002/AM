#ifndef MAINTFAULTCONTROLLER_H
#define MAINTFAULTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MaintFaultController : public ApplicationController
{
    Q_OBJECT
public:
    MaintFaultController() : ApplicationController() { }

public slots:
    void faultSearch();
    void addOperationRestriction();
    void assignFault();
    void createFault();
    void deferFault();
    void deferMELTask();
    void deferMinorTask();
    void editFault();
    void createFaultThreshold();
    void editFaultThreshold();
    void deleteFaultThreshold();
    void finishEvaluation();
    void noFualtFound();
    void performCorrectiveActions();
    void requestEngineering();
    void unassignFault();
    void editFailedSystemOnHistoricFault();
};

#endif // MAINTFAULTCONTROLLER_H
