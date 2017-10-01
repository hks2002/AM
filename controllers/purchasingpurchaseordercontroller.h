#ifndef PURCHASINGPURCHASEORDERCONTROLLER_H
#define PURCHASINGPURCHASEORDERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingPurchaseOrderController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingPurchaseOrderController() : ApplicationController() { }

public slots:
    void createAdHocPo();
    void addMiscLineIssued();
    void addMiscLineUnissued();
    void addPartLineIssued();
    void addPartLineUnissued();
    void addPoAttachment();
    void addPoNote();
    void addCharge();
    void addTax();
    void aogOverride();
    void assignOrderWarranty();
    void assignPoPartRequest();
    void authorizePo();
    void cancelPo();
    void closePo();
    void convertRoToXchg();
    void createPoForPart();
    void createPoForPartRequest();
    void editPo();
    void editAttachment();
    void editLineIssued();
    void editLineUnissued();
    void editPoNumber();
    void issuePo();
    void markNoWarranty();
    void printPo();
    void rejectOrder();
    void removePoAttachment();
    void removeLineIssued();
    void removeLineUnissued();
    void removeCharge();
    void removeTax();
    void reopenPo();
    void requestAuthorization();
    void unassignOrderWarranty();
    void unassignPoPartRequest();
    void unauthorizePo();
};

#endif // PURCHASINGPURCHASEORDERCONTROLLER_H
