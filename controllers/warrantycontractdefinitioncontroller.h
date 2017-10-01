#ifndef WARRANTYCONTRACTDEFINITIONCONTROLLER_H
#define WARRANTYCONTRACTDEFINITIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT WarrantyContractDefinitionController : public ApplicationController
{
    Q_OBJECT
public:
    WarrantyContractDefinitionController() : ApplicationController() { }

public slots:
    void warrantyContractSearch();
    void createWarrantyContract();
    void deleteWarrantyContract();
    void editWarrantyContract();
    void updateWarrantyContract();
    void activateWarrantyContract();
    void deactivateWarrantyContract();
    void expireWarrantyContract();
    void addWarrantyAttachment();
    void removeWarrantyAttachment();
    void editWarrantyAttachment();
    void assignDefnAssembly();
    void assignDefnPart();
    void assignDefnTaskDefinition();
    void unassignDefnAssembly();
    void unassignDefnPart();
    void unassignDefnTaskDefinition();
};

#endif // WARRANTYCONTRACTDEFINITIONCONTROLLER_H
