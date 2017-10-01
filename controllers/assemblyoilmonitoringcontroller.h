#ifndef ASSEMBLYOILMONITORINGCONTROLLER_H
#define ASSEMBLYOILMONITORINGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AssemblyOilMonitoringController : public ApplicationController
{
    Q_OBJECT
public:
    AssemblyOilMonitoringController() : ApplicationController() { }

public slots:
    void createOilMesurementDefinition();
    void editOilMesurmentDefinition();
    void deleteOilMesurmentDefinition();
};

#endif // ASSEMBLYOILMONITORINGCONTROLLER_H
