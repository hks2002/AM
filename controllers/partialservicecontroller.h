#ifndef PARTIALSERVICECONTROLLER_H
#define PARTIALSERVICECONTROLLER_H
#include <TActionController>
#include "applicationcontroller.h"

/* This controller is made for ajax request templates, templates are located in controller's view folder,
 * but its controller doesn't have correspond action.
 * And this controller ignore access permission check.
 */
class T_CONTROLLER_EXPORT PartialServiceController : public TActionController
{
    Q_OBJECT
public:
    PartialServiceController(): TActionController() { }

public slots:
    void relationMenuByMenusGroup();
    void relationMenusGroupByMenu();
    void relationTabByTodoList();
    void relationButtonByTodoList();
    void relationTodoListByButton();
    void relationTodoListByTab();
    void formMenusGroup();
    void formMenu();
    void formButton();
    void formTab();
    void formTodoList();
};

#endif // PARTIALSERVICE_H
