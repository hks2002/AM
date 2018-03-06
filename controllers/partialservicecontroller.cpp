#include "partialservicecontroller.h"

void PartialServiceController::formMenusGroup()
{
    renderTemplate("SystemUIsetting/formMenusGroup");
}

void PartialServiceController::formMenu()
{
    renderTemplate("SystemUIsetting/formMenu");
}

void PartialServiceController::formButton()
{
    renderTemplate("SystemUIsetting/formButton");
}

void PartialServiceController::formTab()
{
    renderTemplate("SystemUIsetting/formTab");
}

void PartialServiceController::formTodoList()
{
    renderTemplate("SystemUIsetting/formTodoList");
}

void PartialServiceController::formDept()
{
    renderTemplate("HrDepartment/formDept");
}

void PartialServiceController::relationMenuByMenusGroup()
{
    renderTemplate("SystemUIsetting/relationMenuByMenusGroup");
}

void PartialServiceController::relationMenusGroupByMenu()
{
    renderTemplate("SystemUIsetting/relationMenusGroupByMenu");
}

void PartialServiceController::relationTabByTodoList()
{
    renderTemplate("SystemUIsetting/relationTabByTodoList");
}

void PartialServiceController::relationButtonByTodoList()
{
    renderTemplate("SystemUIsetting/relationButtonByTodoList");
}

void PartialServiceController::relationTodoListByButton()
{
    renderTemplate("SystemUIsetting/relationTodoListByButton");
}

void PartialServiceController::relationTodoListByTab()
{
    renderTemplate("SystemUIsetting/relationTodoListByTab");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(PartialServiceController)
