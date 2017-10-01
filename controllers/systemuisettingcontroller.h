#ifndef SYSTEMUISETTINGCONTROLLER_H
#define SYSTEMUISETTINGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SystemUIsettingController : public ApplicationController
{
    Q_OBJECT
public:
    SystemUIsettingController() : ApplicationController() { }

public slots:
    void index();
    void searchButton();
    void searchMenu();
    void searchMenusGroup();
    void searchTab();
    void searchTodoList();
    void createButton();
    void createMenu();
    void createMenusGroup();
    void createTab();
    void createTodoList();
    void deleteButton();
    void deleteMenu();
    void deleteMenusGroup();
    void deleteTab();
    void deleteTodoList();
    void editButton();
    void editMenu();
    void editMenusGroup();
    void editTab();
    void editTodoList();
    void orderMenusGroupMenu();
    void orderTodoListButton();
    void orderTodoListTab();
    void editMenuBreak();
    void assignButtonToTodoList();
    void assignMenuToMenusGroup();
    void assignTabToTodoList();
    void unassignButtonFromTodoList();
    void unassignTabFromTodoList();
    void unassignMenuFromMenusGroup();
};

#endif // SYSTEMUISETTINGCONTROLLER_H
