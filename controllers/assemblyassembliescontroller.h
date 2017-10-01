#ifndef ASSEMBLYASSEMBLIESCONTROLLER_H
#define ASSEMBLYASSEMBLIESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AssemblyAssembliesController : public ApplicationController
{
    Q_OBJECT
public:
    AssemblyAssembliesController() : ApplicationController() { }

public slots:
    void createAssembly();
    void deleteAssembly();
    void editAssembly();
};

#endif // ASSEMBLYASSEMBLIESCONTROLLER_H
