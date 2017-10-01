#ifndef SYSTEMINFORMATIONCONTROLLER_H
#define SYSTEMINFORMATIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SystemInformationController : public ApplicationController
{
    Q_OBJECT
public:
    SystemInformationController() : ApplicationController() { }

public slots:
    void systemInformation();
};

#endif // SYSTEMINFORMATIONCONTROLLER_H
