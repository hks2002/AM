#ifndef OPSFORECASTMODELCONTROLLER_H
#define OPSFORECASTMODELCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT OpsForecastModelController : public ApplicationController
{
    Q_OBJECT
public:
    OpsForecastModelController() : ApplicationController() { }

public slots:
    void forecastModelsSearch();
    void addBlackout();
    void assignForecastModel();
    void copyForecastModel();
    void createForecastModel();
    void editForecastModel();
    void markAsDefaultForecastModel();
    void removeBlackout();
    void removeForecastModel();
};

#endif // OPSFORECASTMODELCONTROLLER_H
