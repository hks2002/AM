#ifndef PURCHASINGINVOICECONTROLLER_H
#define PURCHASINGINVOICECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingInvoiceController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingInvoiceController() : ApplicationController() { }

public slots:
    void poInvoiceSearch();
    void addMiscLine();
    void addPartLine();
    void addInvoiceAttachment();
    void addCharge();
    void addTax();
    void cancelInvoice();
    void createInvoice();
    void editInvoice();
    void editInvoiceAttachment();
    void editInvoiceLine();
    void mapInvoiceLinePoLine();
    void markAsPaid();
    void removeInvoiceAttachment();
    void removeInvoiceLine();
    void removeCharge();
    void removeTax();
    void validateForPayment();
};

#endif // PURCHASINGINVOICECONTROLLER_H
