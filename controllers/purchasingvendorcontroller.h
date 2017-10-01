#ifndef PURCHASINGVENDORCONTROLLER_H
#define PURCHASINGVENDORCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingVendorController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingVendorController() : ApplicationController() { }

public slots:
    void vendorSearch();
    void createVendor();
    void addVendorAccount();
    void addVendorAttachment();
    void approveVendorOrderType();
    void deleteVendor();
    void editApprovalDetails();
    void editVendor();
    void editVendorAttachment();
    void markVendorAccountAsDefault();
    void printVendorReliability();
    void removeVendorAccount();
    void removeVendorAttachment();
    void unapproveVendorOrderType();
    void warningVendorOrderType();
};

#endif // PURCHASINGVENDORCONTROLLER_H
