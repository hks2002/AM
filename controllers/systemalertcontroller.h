#ifndef SYSTEMALERTCONTROLLER_H
#define SYSTEMALERTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SystemAlertController : public ApplicationController
{
    Q_OBJECT
public:
    SystemAlertController() : ApplicationController() { }

public slots:
    void alertSearch();
    void alertSetup();
};

#endif // SYSTEMALERTCONTROLLER_H
