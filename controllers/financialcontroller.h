#ifndef FINANCIALCONTROLLER_H
#define FINANCIALCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT FinancialController : public ApplicationController
{
    Q_OBJECT
public:
    FinancialController() : ApplicationController() { }

public slots:
    void accountSearch();
    void chargesSearch();
    void taxesSearch();
    void tcodeSearch();
    void transactionSearch();
    void CurrencySearch();
    void createAccount();
    void createTcode();
    void adjustAvgUnitPrice();
    void assignAccount();
    void closeAccount();
    void createCharge();
    void createTax();
    void deleteCharge();
    void deleteTax();
    void editAccount();
    void editPartFinancials();
    void editTcode();
    void editVendorCharge();
    void editVendorTax();
    void manageCharges();
    void manageTaxes();
    void modifyCharge();
    void modifyTax();
    void reopenAccount();
};

#endif // FINANCIALCONTROLLER_H
