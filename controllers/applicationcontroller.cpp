#include "applicationcontroller.h"
#include "userapp.h"
#include "tactioncontroller.h"
#include "actionapp.h"

ApplicationController::ApplicationController()
    : TActionController()
{
}

ApplicationController::ApplicationController(const ApplicationController &)
    : TActionController()
{ }

ApplicationController::~ApplicationController()
{ }

void ApplicationController::staticInitialize()
{
    //load am.ini
    Tf::app()->getConfig("am");

    //load zh_CN.ini,en_US.ini
    Tf::app()->getConfig("zh_CN");
    Tf::app()->getConfig("en_US");

    //if want to insert new value, use these below:
    //QVariantMap &zh = const_cast<QVariantMap &>(Tf::app()->getConfig("zh_CN"));
    //QVariantMap &en = const_cast<QVariantMap &>(Tf::app()->getConfig("en_US"));

}

void ApplicationController::staticRelease()
{

}

bool ApplicationController::preFilter()
{
    tSystemTrace("Session Id:%s", Tf::currentContext()->currentController()->session().id().data());
    QString ctl = Tf::currentContext()->currentController()->name();
    QString act = Tf::currentContext()->currentController()->activeAction();

    if (!isUserLoggedIn()) {
        QString XMLHttpRequest = Tf::currentContext()->currentController()->httpRequest().header().rawHeader("X-Requested-With");

        if (XMLHttpRequest == "XMLHttpRequest") {//is ajax request
            setStatusCode(401);
            renderTemplate("Welcome/signIn");
        } else { //Normal request
            redirect(url("Welcome", "signIn"));
        }

        return false;
    } else {
        QString userName = identityKeyOfLoginUser();

        //admin could access all pages.
        if (userName == "admin") {
            return true;
        } else if (!accessAllow(ctl, act)) {
            renderErrorResponse(Tf::Forbidden);
            return false;
        }
    }

    return true;
}

// Don't remove below this line
T_REGISTER_CONTROLLER(applicationcontroller)
