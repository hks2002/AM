#ifndef MAINTWORKPACKAGECONTROLLER_H
#define MAINTWORKPACKAGECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MaintWorkPackageController : public ApplicationController
{
    Q_OBJECT
public:
    MaintWorkPackageController() : ApplicationController() { }

public slots:
    void addCheckAttachments();
    void addCostLineItem();
    void createWorkpackageBuilder();
    void addNotesToCheck();
    void cancelCheck();
    void clearWorkscope();
    void commitScope();
    void completeCheck();
    void completeAsUnserviceable();
    void createBlankCheck();
    void createComponentWorkOrder();
    void createServiceCheck();
    void createTurnCheck();
    void delayCheck();
    void editCheck();
    void editCheckAttachments();
    void editCostLineItem();
    void editLockedCostLineItem();
    void editTallyLineNo();
    void editWorkpackageBuilder();
    void deleteWorkpackageBuilder();
    void enforceNsvTasks();
    void generateWorkscope();
    void ignoreNsvTasks();
    void lockCostLineItemsActual();
    void lockCostLineItemsExp();
    void lockCostLineItemsInitExp();
    void previewRelease();
    void printAllTaskCards();
    void printIssueList();
    void removeCostLineItem();
    void requestParts();
    void scheduleRescheduleCheck();
    void setIssueToAccounts();
    void setRepairOrderLineNumbers();
    void signCheckOrWo();
    void startCheck();
    void uncommitScope();
    void unstartCheck();
    void updateJobCardToLatestRevision();
    void viewJobCardsWithNewerRevision();
};

#endif // MAINTWORKPACKAGECONTROLLER_H
