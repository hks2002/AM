#ifndef SUPPLYSHIPMENTCONTROLLER_H
#define SUPPLYSHIPMENTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SupplyShipmentController : public ApplicationController
{
    Q_OBJECT
public:
    SupplyShipmentController() : ApplicationController() { }

public slots:
    void shipmentSearch();
    void pickItemsforShipment();
    void createShipment();
    void cancelShipment();
    void sendShipment();
    void receiveShipment();
    void confirmReceipt();
    void addInventoryToLine();
    void addShipmentLine();
    void removeShipmentLine();
    void editShipmentDetails();
    void editShipmentLineDocs();
    void editShipmentLineNotes();
    void editShipmentRouting();
    void moveInventoryToDock();
    void pickItemForShipment();
    void printPickList();
    void addShipmentAttachment();
    void editShipmentAttachment();
    void removeShipmentAttachment();
    void addNotesToShipment();
};

#endif // SUPPLYSHIPMENTCONTROLLER_H
