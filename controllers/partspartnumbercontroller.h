#ifndef PARTSPARTNUMBERCONTROLLER_H
#define PARTSPARTNUMBERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PartsPartNumberController : public ApplicationController
{
    Q_OBJECT
public:
    PartsPartNumberController() : ApplicationController() { }

public slots:
    void manufacturerSearch();
    void MTBURComparison();
    void createManufacturer();
    void addPartIncompatibility();
    void addTaskIncompatibility();
    void removePartIncompatibility();
    void removeTaskIncompatibility();
    void assignCapability();
    void unassignCapability();
    void addPartRepairVendor();
    void addPartUnitOfCount();
    void addPurchaseVendor();
    void addPurchaseVendorPrice();
    void approvePart();
    void assignAlternatePart();
    void assignExchangePart();
    void assignExchangeVendor();
    void assignPartRepairLocation();
    void changeBatchToSerialized();
    void changeSerializedToBatch();
    void changeSerializedToTracked();
    void changeTrackedToSerialized();
    void createAlternatePart();
    void createPart();
    void createUnitOfCount();
    void deleteManufacturer();
    void deletePart();
    void editExchangeVendorDetails();
    void editInterchgOrd();
    void editManufacturer();
    void editPart();
    void editPartRepairVendor();
    void editPartUnitOfCount();
    void editPurchaseVendor();
    void obsoletePart();
    void removePartRepairVendor();
    void removePartUnitOfCount();
    void removePurchaseVendor();
    void setAsPreferredVendor();
    void setPrefPartRepairVendor();
    void setPrefPurchaseVendor();
    void unassignExchangePartVendor();
    void unassignPartRepairLocation();
    void createTechData();
    void editTechData();
    void deletTechData();
    void createReliabilityUnit();
    void editReliabilityUnit();
    void deletReliabilityUnit();
    void priceAdjustment();
};

#endif // PARTSPARTNUMBERCONTROLLER_H
