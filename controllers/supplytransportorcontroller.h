#ifndef SUPPLYTRANSPORTORCONTROLLER_H
#define SUPPLYTRANSPORTORCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SupplyTransportorController : public ApplicationController
{
    Q_OBJECT
public:
    SupplyTransportorController() : ApplicationController() { }

public slots:
    void TransportBySearch();
    void createTransportor();
    void deleteTransportor();
    void editTransportor();
};

#endif // SUPPLYTRANSPORTORCONTROLLER_H
