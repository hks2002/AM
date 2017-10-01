#ifndef HRLICENSECONTROLLER_H
#define HRLICENSECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HrLicenseController : public ApplicationController
{
    Q_OBJECT
public:
    HrLicenseController() : ApplicationController() { }

public slots:
    void licenseDefinitonSearch();
    void createLicense();
    void editLicense();
    void obsoleteLicense();
    void activeLicense();
    void addPrerequisite();
    void removePrerequisite();
    void reEvaluateUserLicense();
};

#endif // HRLICENSECONTROLLER_H
