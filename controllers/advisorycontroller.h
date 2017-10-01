#ifndef ADVISORYCONTROLLER_H
#define ADVISORYCONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT AdvisoryController : public ApplicationController
{
    Q_OBJECT
public:
    AdvisoryController() : ApplicationController() { }

public slots:
    void advisorySearch();
    void addAdvisoryAttachment();
    void removeAdvisoryAttachment();
    void editAdvisoryAttachment();
    void createAdvisory();
    void editAdvisory();
    void clearAdvisory();
    void taskAdvisoryAssignRole();
    void taskAdvisoryUnassignRole();
    void taskAdvisoryAssignUser();
    void taskAdvisoryUnassignUser();
};

#endif // ADVISORYCONTROLLER_H
