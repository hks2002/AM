#ifndef RELIABILITYNOTECONTROLLER_H
#define RELIABILITYNOTECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ReliabilityNoteController : public ApplicationController
{
    Q_OBJECT
public:
    ReliabilityNoteController() : ApplicationController() { }

public slots:
    void reliabilityNoteSearch();
    void addReliabilityNote();
    void editReliabilityNote();
    void resolveReliabilityNote();
    void viewReliabilityNotes();
};

#endif // RELIABILITYNOTECONTROLLER_H
