#ifndef TASKDEFINITIONREFERENCEDOCUMENTCONTROLLER_H
#define TASKDEFINITIONREFERENCEDOCUMENTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TaskDefinitionReferenceDocumentController : public ApplicationController
{
    Q_OBJECT
public:
    TaskDefinitionReferenceDocumentController() : ApplicationController() { }

public slots:
    void referenceDocumentSearch();
    void createRefDoc();
    void createRefDocRevision();
    void deleteRefDoc();
    void duplicateRefDoc();
    void editRefDoc();
    void activateRefDoc();
    void DispositionRefDoc();
    void initializeRefDoc();
    void moveRefDoc();
    void obsoleteRefDoc();
    void lockRefDoc();
    void UnlockRefDoc();
    void approveRefdoc();
    void rejectApprovalRefdoc();
    void requestApproval();
    void restartApproval();
    void addComplianceToRefDoc();
    void addAttachment();
    void assignRefDocConfigSlot();
    void assignRefDocPart();
    void editAttachment();
    void removeComplianceFromRefDoc();
    void removeAttachment();
    void unassignRefDocConfigSlot();
    void unassignRefDocPart();
};

#endif // TASKDEFINITIONREFERENCEDOCUMENTCONTROLLER_H
