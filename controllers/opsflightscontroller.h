#ifndef OPSFLIGHTSCONTROLLER_H
#define OPSFLIGHTSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OpsFlightsController : public ApplicationController
{
    Q_OBJECT
public:
    OpsFlightsController() : ApplicationController() { }

public slots:
    void addNotesToFlight();
    void completeFlight();
    void createFlightDisruption();
    void editFlight();
    void editFlightDisruption();
};

#endif // OPSFLIGHTSCONTROLLER_H
