#ifndef WARRANTYCONTRACTINITIALIZATIONCONTROLLER_H
#define WARRANTYCONTRACTINITIALIZATIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT WarrantyContractInitializationController : public ApplicationController
{
    Q_OBJECT
public:
    WarrantyContractInitializationController() : ApplicationController() { }

public slots:
    void addAssembly();
    void removeAssembly();
    void addPart();
    void removePart();
    void unassignWarrantyContract();
    void assignWarrantyContract();
};

#endif // WARRANTYCONTRACTINITIALIZATIONCONTROLLER_H
