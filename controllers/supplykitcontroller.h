#ifndef SUPPLYKITCONTROLLER_H
#define SUPPLYKITCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SupplyKitController : public ApplicationController
{
    Q_OBJECT
public:
    SupplyKitController() : ApplicationController() { }

public slots:
    void addKitContent();
    void removeKitContent();
    void editKitContents();
    void createKitInventory();
    void pickItemsForKit();
    void removeInventoryFromKit();
    void sealKit();
    void unsealKit();
};

#endif // SUPPLYKITCONTROLLER_H
