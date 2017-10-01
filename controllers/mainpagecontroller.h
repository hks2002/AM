#ifndef MAINPAGECONTROLLER_H
#define MAINPAGECONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT MainPageController : public ApplicationController
{
    Q_OBJECT
public:
    MainPageController() : ApplicationController() { }

public slots:
    void index();
    void assemblyList();
    void taskDefinition();
    void taskLaborSummary();
    void oilConsumptionStatus();
    void licensePendingExpiry();
    void toolsCalibration();
    void looseInventoryDue();
    void pendingExpiry();
    void planningViewer();
    void quarantineCorrectiveActions();
    void supportingRequired_Tasks();
    void faultEvaluation();
    void unassignedAlerts();
    void purchaseRequests();
    void consignmentStockRequests();
    void purchaseOrders();
    void inventoryRequests();
    void inboundOutboundShipments();
    void stockTransfer();
    void issueTurnIn();
    void checkedOutInTools();
    void inventoryReturns();
    void incompleteOverCompleteKits();
    void condemned();
    void inspectionRequired();
    void quarantine();
    void toBeShelved();
    void unserviceableStaging();
    void outForRepair();
    void claims();
    void stockLevel();
    void cycleCount();
    void predrawMonitoring();
    void workPackagesList();
    void fleetDueList();
    void fleetList();
    void assignedWorkList();
    void invoice();
};

#endif // MAINPAGECONTROLLER_H
