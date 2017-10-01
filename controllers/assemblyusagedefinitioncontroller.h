#ifndef ASSEMBLYUSAGEDEFINITIONCONTROLLER_H
#define ASSEMBLYUSAGEDEFINITIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AssemblyUsageDefinitionController : public ApplicationController
{
    Q_OBJECT
public:
    AssemblyUsageDefinitionController() : ApplicationController() { }

public slots:
    void assignAssembly();
    void assignUsageParm();
    void unassignAssembly();
    void unassignUsageParm();
    void createUsage();
    void createUsageParm();
    void deleteUsage();
    void editUsageParm();
    void reorderUsageParms();
    void synchUsageParms();
};

#endif // ASSEMBLYUSAGEDEFINITIONCONTROLLER_H
