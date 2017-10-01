#ifndef OPSTECHNICALDIFFICULTYCONTROLLER_H
#define OPSTECHNICALDIFFICULTYCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OpsTechnicalDifficultyController : public ApplicationController
{
    Q_OBJECT
public:
    OpsTechnicalDifficultyController() : ApplicationController() { }

public slots:
    void technicalDifficulty();
};

#endif // OPSTECHNICALDIFFICULTYCONTROLLER_H
