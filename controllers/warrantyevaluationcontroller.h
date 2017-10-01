#ifndef WARRANTYEVALUATIONCONTROLLER_H
#define WARRANTYEVALUATIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT WarrantyEvaluationController : public ApplicationController
{
    Q_OBJECT
public:
    WarrantyEvaluationController() : ApplicationController() { }

public slots:
    void giveUpWarranty();
    void useWarranty();
    void assignTask();
    void assignLabor();
    void assignPart();
    void unassignTask();
    void unassignLabor();
    void unassignPart();
};

#endif // WARRANTYEVALUATIONCONTROLLER_H
