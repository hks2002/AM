#ifndef PURCHASINGPRICECONTROLLER_H
#define PURCHASINGPRICECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PurchasingPriceController : public ApplicationController
{
    Q_OBJECT
public:
    PurchasingPriceController() : ApplicationController() { }

public slots:
    void addVendorPartPrice();
    void editVendorPartPrice();
    void obsoleteVendorPartPrice();
};

#endif // PURCHASINGPRICECONTROLLER_H
