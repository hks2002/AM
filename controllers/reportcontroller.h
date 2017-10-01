#ifndef REPORTCONTROLLER_H
#define REPORTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ReportController : public ApplicationController
{
    Q_OBJECT
public:
    ReportController() : ApplicationController() { }

public slots:
    void reportConfigurationSearch();
    void fleetStatistics();
    void oilConsumptionStatus();
    void componentReliability();
    void PIREPMAREP();
    void referenceDocumentDispositionStatus();
    void fleetSLStatus();
    void fleetSBStatus();
    void fleetADStatus();
    void fleetLLPStatus();
    void fleetTCPStatus();
    void aircraftSLStatus();
    void aircraftSBStatus();
    void aircraftADStatus();
    void aircraftLLPStatus();
    void aircraftTCPStatus();
    void assemblySLStatus();
    void assemblySBStatus();
    void assemblyADStatus();
    void assemblyLLPStatus();
    void assemblyTCPStatus();
    void aircraftMaintenanceProgram();
    void aircraftConfiguration();
    void aircraftInventory();
    void maintenanceStatus();
    void RVSMMaintenance();
    void forecastOfAircraftMaintenance();
    void fleetDeferredDefects();
    void fleetOpenDefects();
    void fleetStatus();
    void aircraftDeferredDefects();
    void aircraftOpenDefects();
    void aircraftStatus();
    void certificateofReleasetoService();
    void detailedInventoryFinancialLog();
    void summaryInventoryFinancialLog();
};

#endif // REPORTCONTROLLER_H
