#ifndef PARTIALSERVICECONTROLLER_H
#define PARTIALSERVICECONTROLLER_H
#include <TActionController>
#include "applicationcontroller.h"

/*This controller is made for ajax request templates, templates are located in controller's view folder,
 * but its controller doesn't have correspond action.
 */
class T_CONTROLLER_EXPORT PartialServiceController : public ApplicationController
{
    Q_OBJECT
public:
    PartialServiceController(): ApplicationController() { }

public slots:
    void relationMenu();
    void relationButton();
    void relationTab();
    void relationMenusGroup();
    void relationTodoListByButton();
    void relationTodoListByTab();
    void formMenusGroup();
    void formMenu();
    void formButton();
    void formTab();
    void formTodoList();
};

#endif // PARTIALSERVICE_H
