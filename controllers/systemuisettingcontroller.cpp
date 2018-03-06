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
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<ButtonObject> mapper;
        TCriteria crt(ButtonObject::ButtonCd, varMaps.value("buttunCd"));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::createRecord<Button, ButtonValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::createMenu()
{
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<MenuObject> mapper;
        TCriteria crt(MenuObject::MenuCd, varMaps.value("menuCd"));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::createRecord<Menu, MenuValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::createMenusGroup()
{
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<MenusGroupObject> mapper;
        TCriteria crt(MenusGroupObject::MenusGroupCd, varMaps.value("menusGroupCd"));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::createRecord<MenusGroup, MenusGroupValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::createTab()
{
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<TabObject> mapper;
        TCriteria crt(TabObject::TabCd, varMaps.value("tabCd"));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::createRecord<Tab, TabValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::createTodoList()
{
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<TodoListObject> mapper;
        TCriteria crt(TodoListObject::TodoListCd, varMaps.value("todoListCd"));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::createRecord<TodoList, TodoListValidator>(dynamic_cast<ApplicationController *>(this));
}

void SystemUIsettingController::deleteButton()
{
    QString key  = httpRequest().formItemValue("key");
    QJsonArray array = jsonArray(key);

    if (array.isEmpty()) {
        renderJson(jsonObj(false, UI("Error Occurred.")));
        return;
    }

    for (QJsonValue jsonValue : array) {
        QJsonObject obj = jsonValue.toObject();
        {
            TSqlORMapper<TodoListButtonObject> mapper;
            TCriteria crt(TodoListButtonObject::ButtonId, hmacVal(obj.value("buttonId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Already be assigned to TodoList.")));
                return;
            }
        }
    }

    DataServiceController::deleteRecord<ButtonObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "buttonId");
}

void SystemUIsettingController::deleteMenu()
{
    QString key  = httpRequest().formItemValue("key");
    QJsonArray array = jsonArray(key);

    if (array.isEmpty()) {
        renderJson(jsonObj(false, UI("Error Occurred.")));
        return;
    }

    for (QJsonValue jsonValue : array) {
        QJsonObject obj = jsonValue.toObject();
        {
            TSqlORMapper<MenusGroupMenuObject> mapper;
            TCriteria crt(MenusGroupMenuObject::MenuId, hmacVal(obj.value("menuId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Already be assigned to MenusGroup.")));
                return;
            }
        }
    }

    DataServiceController::deleteRecord<MenuObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menuId");
}

void SystemUIsettingController::deleteMenusGroup()
{
    QString key  = httpRequest().formItemValue("key");
    QJsonArray array = jsonArray(key);

    if (array.isEmpty()) {
        renderJson(jsonObj(false, UI("Error Occurred.")));
        return;
    }

    for (QJsonValue jsonValue : array) {
        QJsonObject obj = jsonValue.toObject();
        {
            TSqlORMapper<MenusGroupMenuObject> mapper;
            TCriteria crt(MenusGroupMenuObject::MenusGroupId, hmacVal(obj.value("menusGroupId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Already be assigned to Menu.")));
                return;
            }
        }
    }

    DataServiceController::deleteRecord<MenusGroupObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menusGroupId");
}

void SystemUIsettingController::deleteTab()
{
    QString key  = httpRequest().formItemValue("key");
    QJsonArray array = jsonArray(key);

    if (array.isEmpty()) {
        renderJson(jsonObj(false, UI("Error Occurred.")));
        return;
    }

    for (QJsonValue jsonValue : array) {
        QJsonObject obj = jsonValue.toObject();
        {
            TSqlORMapper<TodoListTabObject> mapper;
            TCriteria crt(TodoListTabObject::TabId, hmacVal(obj.value("tabId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Already be assigned to TodoList.")));
                return;
            }
        }
    }

    DataServiceController::deleteRecord<TabObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "tabId");
}

void SystemUIsettingController::deleteTodoList()
{
    QString key  = httpRequest().formItemValue("key");
    QJsonArray array = jsonArray(key);

    if (array.isEmpty()) {
        renderJson(jsonObj(false, UI("Error Occurred.")));
        return;
    }

    for (QJsonValue jsonValue : array) {
        QJsonObject obj = jsonValue.toObject();
        {
            TSqlORMapper<TodoListTabObject> mapper;
            TCriteria crt(TodoListTabObject::TodoListId, hmacVal(obj.value("todoListId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Already be assigned to Tab.")));
                return;
            }
        }
        {
            TSqlORMapper<TodoListButtonObject> mapper;
            TCriteria crt(TodoListButtonObject::TodoListId, hmacVal(obj.value("todoListId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Already be assigned to Button.")));
                return;
            }
        }
    }

    DataServiceController::deleteRecord<TodoListObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId");
}

void SystemUIsettingController::editButton()
{
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<ButtonObject> mapper;
        TCriteria crt(ButtonObject::ButtonCd, varMaps.value("buttunCd"));
        crt.add(ButtonObject::ButtonId, TSql::NotEqual, hmacVal(varMaps.value("buttunId")));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::updateRecord<Button, ButtonObject, ButtonValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "buttonId", QStringList());
}

void SystemUIsettingController::editMenu()
{
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<MenuObject> mapper;
        TCriteria crt(MenuObject::MenuCd, varMaps.value("menuCd"));
        crt.add(MenuObject::MenuId, TSql::NotEqual, hmacVal(varMaps.value("menuId")));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::updateRecord<Menu, MenuObject, MenuValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menuId", QStringList());
}

void SystemUIsettingController::editMenusGroup()
{
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<MenusGroupObject> mapper;
        TCriteria crt(MenusGroupObject::MenusGroupCd, varMaps.value("menusGroupCd"));
        crt.add(MenusGroupObject::MenusGroupId, TSql::NotEqual, hmacVal(varMaps.value("menusGroupId")));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::updateRecord<MenusGroup, MenusGroupObject, MenusGroupValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menusGroupId", QStringList());
}

void SystemUIsettingController::editTab()
{
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<TabObject> mapper;
        TCriteria crt(TabObject::TabCd, varMaps.value("tabCd"));
        crt.add(TabObject::TabId, TSql::NotEqual, hmacVal(varMaps.value("tabId")));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::updateRecord<Tab, TabObject, TabValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "tabId", QStringList());
}

void SystemUIsettingController::editTodoList()
{
    if (boolean(CFG("UICODE_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<TodoListObject> mapper;
        TCriteria crt(TodoListObject::TodoListCd, varMaps.value("todoListCd"));
        crt.add(TodoListObject::TodoListId, TSql::NotEqual, hmacVal(varMaps.value("todoListId")));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

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
    DataServiceController::unassignRecord<TodoListButtonObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId" << "buttonId");
}

void SystemUIsettingController::unassignTabFromTodoList()
{
    DataServiceController::unassignRecord<TodoListTabObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "todoListId" << "tabId");
}

void SystemUIsettingController::unassignMenuFromMenusGroup()
{
    DataServiceController::unassignRecord<MenusGroupMenuObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "menusGroupId" << "menuId");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(SystemUIsettingController)
