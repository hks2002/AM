#ifndef OPSUSAGERECORDINGCONTROLLER_H
#define OPSUSAGERECORDINGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OpsUsageRecordingController : public ApplicationController
{
    Q_OBJECT
public:
    OpsUsageRecordingController() : ApplicationController() { }

public slots:
    void createUsageRecord();
    void editHistoricUsageSnapshot();
    void editUsageSnapshot();
};

#endif // OPSUSAGERECORDINGCONTROLLER_H
