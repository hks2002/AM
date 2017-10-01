#ifndef MAINTCONTROLLER_H
#define MAINTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MaintController : public ApplicationController
{
    Q_OBJECT
public:
    MaintController() : ApplicationController() { }

public slots:
    void taskSearch();
};

#endif // MAINTCONTROLLER_H
