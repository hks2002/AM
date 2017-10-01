#ifndef WARRANTYCLAIMCONTROLLER_H
#define WARRANTYCLAIMCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT WarrantyClaimController : public ApplicationController
{
    Q_OBJECT
public:
    WarrantyClaimController() : ApplicationController() { }

public slots:
    void claimSearch();
    void createClaim();
    void cancelClaim();
    void closeClaim();
    void editClaim();
    void submitClaim();
    void editClaimLaborLines();
    void editClaimPartLines();
    void markAsNoReturnRequired();
    void rejectWarranty();
    void addClaimAttachment();
    void removeClaimAttachment();
    void editClaimAttachment();
};

#endif // WARRANTYCLAIMCONTROLLER_H
