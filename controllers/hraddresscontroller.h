#ifndef HRADDRESSCONTROLLER_H
#define HRADDRESSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HrAddressController : public ApplicationController
{
    Q_OBJECT
public:
    HrAddressController() : ApplicationController() { }

public slots:
    void countrySearch();
    void provinceSearch();
    void citySearch();
    void createProvince();
    void editProvince();
    void deleleProvince();
    void createCity();
    void editCity();
    void deleleCity();
    void assignCity();
    void unassignCity();
    void createCountry();
    void editCountry();
    void deleleCountry();
    void assignProvince();
    void unassignProvince();
    void createAddress();
    void editAddress();
    void deleleAddress();
};

#endif // HRADDRESSCONTROLLER_H
