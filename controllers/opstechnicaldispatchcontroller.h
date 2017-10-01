#ifndef OPSTECHNICALDISPATCHCONTROLLER_H
#define OPSTECHNICALDISPATCHCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OpsTechnicalDispatchController : public ApplicationController
{
    Q_OBJECT
public:
    OpsTechnicalDispatchController() : ApplicationController() { }

public slots:
    void technicalDispatch();
};

#endif // OPSTECHNICALDISPATCHCONTROLLER_H
