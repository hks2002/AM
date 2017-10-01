#ifndef SUPPLYPARTREQUESTCONTROLLER_H
#define SUPPLYPARTREQUESTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SupplyPartRequestController : public ApplicationController
{
    Q_OBJECT
public:
    SupplyPartRequestController() : ApplicationController() { }

public slots:
    void partRequestSearch();
    void createAdhocPartRequest();
    void createAdhocPurchaseRequest();
    void createPurchaseRequestForStock();
    void cancelPartRequest();
    void createConsignRequestForStock();
    void createPurchaseRequestForPartRequest();
    void editPartRequestNote();
    void editPartRequestPriority();
    void notInStock();
    void rejectPurchaseRequest();
    void reserveInventoryWithWarnings();
    void reserveLocalInventory();
    void reserveOnOrderInventory();
    void reserveRemoteInventory();
    void stealRemoteReservation();
    void assignPartRequestToMe();
    void unassignPartRequestFromMe();
};

#endif // SUPPLYPARTREQUESTCONTROLLER_H
