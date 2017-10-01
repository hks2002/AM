#ifndef LOCATIONCONTROLLER_H
#define LOCATIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT LocationController : public ApplicationController
{
    Q_OBJECT
public:
    LocationController() : ApplicationController() { }

public slots:
    void locationSearch();
    void createLocation();
    void markDefaultContact();
    void assignLocation();
    void assignRepairablePart();
    void unassignRepairablePart();
    void assignAddress();
    void unassignAddress();
    void assignContactor();
    void unassignContactor();
    void createBinLevel();
    void createBinLocation();
    void createContact();
    void deleteBinLevel();
    void deleteContact();
    void deleteLocation();
    void editBinLevel();
    void editContact();
    void editLocation();
    void markAsSupply();
    void setAsDefaultDock();
    void unmarkAsSupply();
};

#endif // LOCATIONCONTROLLER_H
