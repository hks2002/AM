#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MenuController : public ApplicationController
{
    Q_OBJECT
public:
    MenuController() : ApplicationController() { }

public slots:
    void a();
};

#endif // MENUCONTROLLER_H
