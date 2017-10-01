#ifndef PURCHASINGREQUESTFORQUOTECONTROLLER_H
#define PURCHASINGREQUESTFORQUOTECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingRequestForQuoteController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingRequestForQuoteController() : ApplicationController() { }

public slots:
    void rfqSearch();
    void createAdhocRfq();
    void addMiscLine();
    void addPartLine();
    void addCharge();
    void addTax();
    void addAttachment();
    void addNote();
    void addVendorToRfq();
    void assignReqToRfq();
    void assignRfqLineToPo();
    void cancelRfq();
    void closeRfq();
    void createPoFromRfqLine();
    void createRfq();
    void editRfq();
    void editRfqAttachment();
    void editRfqLines();
    void editVendorQuote();
    void printRfq();
    void removeCharge();
    void removeTax();
    void removeRfqAttachment();
    void removeRfqLine();
    void removeVendorFromRfq();
    void sendRfq();
    void unassignReqToRfq();
};

#endif // PURCHASINGREQUESTFORQUOTECONTROLLER_H
