#ifndef TASKDEFINITIONTAGGROUPINGCONTROLLER_H
#define TASKDEFINITIONTAGGROUPINGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TaskDefinitionTagGroupingController : public ApplicationController
{
    Q_OBJECT
public:
    TaskDefinitionTagGroupingController() : ApplicationController() { }

public slots:
    void tagSearch();
    void createTag();
    void deleteTag();
    void editTag();
};

#endif // TASKDEFINITIONTAGGROUPINGCONTROLLER_H
