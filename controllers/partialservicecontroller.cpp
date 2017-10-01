#include "partialservicecontroller.h"

void PartialServiceController::relationMenu()
{
    renderTemplate("SystemUIsetting/relationMenu");
}

void PartialServiceController::relationButton()
{
    renderTemplate("SystemUIsetting/relationButton");
}

void PartialServiceController::relationTab()
{
    renderTemplate("SystemUIsetting/relationTab");
}

void PartialServiceController::relationMenusGroup()
{
    renderTemplate("SystemUIsetting/relationMenusGroup");
}

void PartialServiceController::relationTodoListByButton()
{
    renderTemplate("SystemUIsetting/relationTodoListByButton");
}

void PartialServiceController::relationTodoListByTab()
{
    renderTemplate("SystemUIsetting/relationTodoListByTab");
}

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
// Don't remove below this line
T_DEFINE_CONTROLLER(PartialServiceController)
