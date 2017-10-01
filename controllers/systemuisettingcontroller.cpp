#include "systemuisettingcontroller.h"
#include "dataservicecontroller.h"

#include "button.h"
#include "menu.h"
#include "menusgroup.h"
#include "menusgroupmenu.h"
#include "tab.h"
#include "todolist.h"
#include "todolisttab.h"
#include "todolistbutton.h"

#include "buttonvalidator.h"
#include "menuvalidator.h"
#include "menusgroupvalidator.h"
#include "menusgroupmenuvalidator.h"
#include "tabvalidator.h"
#include "todolistvalidator.h"
#include "todolisttabvalidator.h"
#include "todolistbuttonvalidator.h"

#include "sqlobjects/buttonobject.h"
#include "sqlobjects/menuobject.h"
#include "sqlobjects/menusgroupobject.h"
#include "sqlobjects/menusgroupmenuobject.h"
#include "sqlobjects/tabobject.h"
#include "sqlobjects/todolistobject.h"
#include "sqlobjects/todolisttabobject.h"
#include "sqlobjects/todolistbuttonobject.h"


void SystemUIsettingController::index()
{
    int tabsActiveIndex = httpRequest().cookie("subTabsActiveIndex").toInt();
    texport(tabsActiveIndex);
    render();
}

void SystemUIsettingController::searchButton()
{
    render();
}

void SystemUIsettingController::searchMenu()
{
    render();
}

void SystemUIsettingController::searchMenusGroup()
{
    render();
}

void SystemUIsettingController::searchTab()
{
    render();
}

void SystemUIsettingController::searchTodoList()
{
    render();
}

void SystemUIsettingController::createButton()
{
    DataServiceController::createRecord<Button, ButtonValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::createMenu()
{
    DataServiceController::createRecord<Menu, MenuValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::createMenusGroup()
{
    DataServiceController::createRecord<MenusGroup, MenusGroupValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::createTab()
{
    DataServiceController::createRecord<Tab, TabValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::createTodoList()
{
    DataServiceController::createRecord<TodoList, TodoListValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::deleteButton()
{
    DataServiceController::deleteRecord<Button, ButtonObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "buttonId");
}

void SystemUIsettingController::deleteMenu()
{
    DataServiceController::deleteRecord<Menu, MenuObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menuId");
}

void SystemUIsettingController::deleteMenusGroup()
{
    DataServiceController::deleteRecord<MenusGroup, MenusGroupObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menusGroupId");
}

void SystemUIsettingController::deleteTab()
{
    DataServiceController::deleteRecord<Tab, TabObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "tabId");
}

void SystemUIsettingController::deleteTodoList()
{
    DataServiceController::deleteRecord<TodoList, TodoListObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId");
}

void SystemUIsettingController::editButton()
{
    DataServiceController::updateRecord<Button, ButtonObject, ButtonValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "buttonId", QStringList());
}

void SystemUIsettingController::editMenu()
{
    DataServiceController::updateRecord<Menu, MenuObject, MenuValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menuId", QStringList());
}

void SystemUIsettingController::editMenusGroup()
{
    DataServiceController::updateRecord<MenusGroup, MenusGroupObject, MenusGroupValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menusGroupId", QStringList());
}

void SystemUIsettingController::editTab()
{
    DataServiceController::updateRecord<Tab, TabObject, TabValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "tabId", QStringList());
}

void SystemUIsettingController::editTodoList()
{
    DataServiceController::updateRecord<TodoList, TodoListObject, TodoListValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId", QStringList());
}

void SystemUIsettingController::orderMenusGroupMenu()
{
    DataServiceController::updateRecord<MenusGroupMenu, MenusGroupMenuObject, MenusGroupMenuValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menusGroupId" << "menuId", QStringList() << "menuOrder");
}

void SystemUIsettingController::orderTodoListButton()
{
    DataServiceController::updateRecord<TodoListButton, TodoListButtonObject, TodoListButtonValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId" << "buttonId", QStringList() << "buttonOrder");
}

void SystemUIsettingController::orderTodoListTab()
{
    DataServiceController::updateRecord<TodoListTab, TodoListTabObject, TodoListTabValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId" << "tabId", QStringList() << "tabOrder");
}

void SystemUIsettingController::editMenuBreak()
{
    DataServiceController::updateRecord<MenusGroupMenu, MenusGroupMenuObject, MenusGroupMenuValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menusGroupId" << "menuId", QStringList() << "breakBool");
}

void SystemUIsettingController::assignButtonToTodoList()
{
    DataServiceController::assignRecord<TodoListButton>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId" << "buttonId");
}

void SystemUIsettingController::assignTabToTodoList()
{
    DataServiceController::assignRecord<TodoListTab>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId" << "tabId");
}

void SystemUIsettingController::assignMenuToMenusGroup()
{
    DataServiceController::assignRecord<MenusGroupMenu>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menusGroupId" << "menuId");
}

void SystemUIsettingController::unassignButtonFromTodoList()
{
    DataServiceController::unassignRecord<TodoListButton, TodoListButtonObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId" << "buttonId");
}

void SystemUIsettingController::unassignTabFromTodoList()
{
    DataServiceController::unassignRecord<TodoListTab, TodoListTabObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId" << "tabId");
}

void SystemUIsettingController::unassignMenuFromMenusGroup()
{
    DataServiceController::unassignRecord<MenusGroupMenu, MenusGroupMenuObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menusGroupId" << "menuId");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(SystemUIsettingController)
