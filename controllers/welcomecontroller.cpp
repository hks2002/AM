#include "welcomecontroller.h"
#include "applicationhelper.h"
#include <TreeFrogModel>
#include <TreeFrogController>
#include "userapp.h"
#include "vcontrolleractionuserall.h"
#include "sqlobjects/vcontrolleractionuserallobject.h"
#include "vcontrolleractionroleuser.h"
#include "sqlobjects/vcontrolleractionroleuserobject.h"

void WelcomeController::index()
{
    if (!isUserLoggedIn()) {
        render("index", "layout");
    } else {
        redirect(url("MainPage", "index"));
    }
}

void WelcomeController::signIn()
{
    if (isUserLoggedIn()) {
        userLogout();
    }

    QString XMLHttpRequest = Tf::currentContext()->currentController()->httpRequest().header().rawHeader("X-Requested-With");

    if (XMLHttpRequest == "XMLHttpRequest") {//is ajax request
        render("signIn");
    } else { //Normal request
        render("signIn", "layout");
    }

}

void WelcomeController::logOut()
{
    userLogout();
    redirect(url("Welcome", "index"));
}

void WelcomeController::logIn()
{

    QString userName = httpRequest().formItemValue("username");
    QString password = httpRequest().formItemValue("password");

    UserApp user = UserApp::authenticate(userName, password);

    if (!user.isNull()) {
        userLogin(&user);
        session().insert("currentUserId", user.userId());
        session().insert("currentUserZh", user.fullNameZh());
        session().insert("currentUserEn", user.fullNameEn());

        TSqlORMapper<VControllerActionUserAllObject> mapper;

        if (mapper.find(TCriteria(VControllerActionUserAllObject::UserId, user.userId())) > 0) {
            for (auto &o : mapper) {
                auto model = VControllerActionUserAll(o);
                QString url = model.controller() + "/" + model.action();
                tTrace() << url << " allowed to " << userName;
                session().insert(url, user.userId());
            }
        }

        TSqlORMapper<VControllerActionRoleUserObject> mapper2;

        if (mapper2.find(TCriteria(VControllerActionRoleUserObject::UserId, user.userId())) > 0) {
            for (auto &o : mapper2) {
                auto model = VControllerActionRoleUser(o);
                QString url =  model.controller() + "/" + model.action();
                tTrace() << url << " allowed to " << userName;
                session().insert(url, user.userId());
            }
        }

        renderJson(jsonObj(true));
    } else {
        renderJson(jsonObj(false, UI("invalidPassword")));
    }

}

void WelcomeController::forgetPassword()
{

}

// Don't remove below this line
T_DEFINE_CONTROLLER(WelcomeController)
