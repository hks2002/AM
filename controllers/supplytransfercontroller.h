#ifndef SUPPLYTRANSFERCONTROLLER_H
#define SUPPLYTRANSFERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SupplyTransferController : public ApplicationController
{
    Q_OBJECT
public:
    SupplyTransferController() : ApplicationController() { }

public slots:
    void transferSearch();
    void createTransfer();
    void createPutaway();
    void createTurnIn();
    void cancelTransfer();
    void cancelPutaway();
    void cancelTurnIn();
    void completePutaway();
    void completeTransfer();
    void completeTurnIn();
    void printTransferTicket();
    void issueToAdhoc();
    void issueInventoryNoPR();
    void issueToTask();
    void invTurnIn();
    void predrawInventory();
    void putawayInventory();
    void addNotesToTransfer();
};

#endif // SUPPLYTRANSFERCONTROLLER_H
