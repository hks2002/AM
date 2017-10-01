#ifndef ASSEMBLYZONEPANELCONTROLLER_H
#define ASSEMBLYZONEPANELCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AssemblyZonePanelController : public ApplicationController
{
    Q_OBJECT
public:
    AssemblyZonePanelController() : ApplicationController() { }

public slots:
    void createZone();
    void editZone();
    void deleteZone();
    void createPanel();
    void editPanel();
    void deletePanel();
};

#endif // ASSEMBLYZONEPANELCONTROLLER_H
