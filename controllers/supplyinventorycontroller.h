#ifndef SUPPLYINVENTORYCONTROLLER_H
#define SUPPLYINVENTORYCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SupplyInventoryController : public ApplicationController
{
    Q_OBJECT
public:
    SupplyInventoryController() : ApplicationController() { }

public slots:
    void inventorySearch();
    void partSearch();
    void createInventory();
    void addInventoryAttachment();
    void addQuarantineAction();
    void addQuarantineNote();
    void adjustInvQuantity();
    void allowBaselineSynchronization();
    void archiveInventory();
    void assignDeptToQuarantineAction();
    void assignUserToQuarantineAction();
    void attachInventory();
    void detachInventory();
    void changeAuthority();
    void changeBomItem();
    void changeCustody();
    void changeOwner();
    void condemnInventory();
    void editInventoryAttachment();
    void editInvDetails();
    void editInvSubitems();
    void editInvTasks();
    void editInvUsage();
    void editQuarantineAction();
    void initializeInventoryWarranty();
    void inspectAsServiceable();
    void lockInventory();
    void markAsFound();
    void markInventoryAsInspectionRequired();
    void markInventoryAsRepairRequired();
    void moveInventoryToQuarantine();
    void moveToShop();
    void preventBaselineSynchronization();
    void printCondemnTag();
    void printQuarantineTag();
    void printServiceableTag();
    void printUnserviceableTag();
    void removeInventoryAttachment();
    void removeQuarantineAction();
    void returnToVendor();
    void scrapInventory();
    void synchronizeMaintenance();
    void unarchiveInventory();
    void updateDeadlines();
};

#endif // SUPPLYINVENTORYCONTROLLER_H
