#ifndef OPSCAPABILITYCONTROLLER_H
#define OPSCAPABILITYCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OpsCapabilityController : public ApplicationController
{
    Q_OBJECT
public:
    OpsCapabilityController() : ApplicationController() { }

public slots:
    void capabilitySearch();
};

#endif // OPSCAPABILITYCONTROLLER_H
