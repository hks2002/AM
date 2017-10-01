#ifndef ASSEMBLYCONFIGSLOTCONTROLLER_H
#define ASSEMBLYCONFIGSLOTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AssemblyConfigSlotController : public ApplicationController
{
    Q_OBJECT
public:
    AssemblyConfigSlotController() : ApplicationController() { }

public slots:
    void configSlotSearch();
    void createConfigSlot();
    void addPosition();
    void assignUsageParm();
    void cascadeUasgeParm();
    void deleteConfigSlot();
    void editConfigSlot();
    void editPosition();
    void removePostion();
    void unassignUsageParm();
    void unCascadeUasgeParm();
    void moveConfigSolt();
    void approvePartForConfigSlot();
    void unapprovePartForConfigSlot();
    void editApplicability();
    void editAssignedPart();
    void assignCapability();
    void unassignCapability();
};

#endif // ASSEMBLYCONFIGSLOTCONTROLLER_H
