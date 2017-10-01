#ifndef OPSOILRECORDINGCONTROLLER_H
#define OPSOILRECORDINGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OpsOilRecordingController : public ApplicationController
{
    Q_OBJECT
public:
    OpsOilRecordingController() : ApplicationController() { }

public slots:
    void createOiLRecord();
    void editHistoricOilSnapshot();
    void editOilSnapshot();
};

#endif // OPSOILRECORDINGCONTROLLER_H
