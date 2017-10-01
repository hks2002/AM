#ifndef UNITCONTROLLER_H
#define UNITCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT UnitController : public ApplicationController
{
    Q_OBJECT
public:
    UnitController() : ApplicationController() { }

public slots:
    void measurementSearch();
    void DataTypeSearch();
    void MesurUnitSearch();
    void QtyUnitSearch();
};

#endif // UNITCONTROLLER_H
