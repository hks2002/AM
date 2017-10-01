#ifndef MAINTPROGRAMMAINTPROGRAMCONTROLLER_H
#define MAINTPROGRAMMAINTPROGRAMCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MaintProgramMaintProgramController : public ApplicationController
{
    Q_OBJECT
public:
    MaintProgramMaintProgramController() : ApplicationController() { }

public slots:
    void createMaintProgram();
    void activateMaintProgram();
    void deleteMaintProgram();
    void editIssueNumbers();
    void issueTempReq();
    void editMaintProgram();
    void editRevReasonNotes();
    void lockMaintProgram();
    void unlockMaintProgram();
    void revertMaintProgram();
    void editAssignedReq();
    void assignReqToMaintProgram();
    void unassignReqFromMaintProgram();
    void assignMaintProgramToCarrier();
    void unassignMaintProgramToCarrier();
    void printMaintProgram();
    void printMaintProgramDiff();
    void printMaintProgramImpactReport();
};

#endif // MAINTPROGRAMMAINTPROGRAMCONTROLLER_H
