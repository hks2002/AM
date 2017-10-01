#ifndef SUPPLYTOOLCONTROLLER_H
#define SUPPLYTOOLCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SupplyToolController : public ApplicationController
{
    Q_OBJECT
public:
    SupplyToolController() : ApplicationController() { }

public slots:
    void toolSearch();
    void checkInTool();
    void checkOutTool();
};

#endif // SUPPLYTOOLCONTROLLER_H
