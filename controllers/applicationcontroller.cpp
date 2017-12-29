#include "applicationcontroller.h"
#include "userapp.h"
#include "vcontrolleractionuserall.h"
#include "vcontrolleractionroleuser.h"
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
    QVariantMap &zh = const_cast<QVariantMap &>(Tf::app()->getConfig("zh_CN"));
    QVariantMap &en = const_cast<QVariantMap &>(Tf::app()->getConfig("en_US"));

    ActionApp act;
    auto list = act.getAll();

    for (ActionApp &a : list) {
        zh.insert(QString("ACT_").append(a.actionCd()), QString::fromUtf8(a.actionNameZh().toLatin1().data()));
        en.insert(QString("ACT_").append(a.actionCd()), QString::fromUtf8(a.actionNameEn().toLatin1().data()));
        zh.insert(QString("TP_").append(a.actionCd()), QString::fromUtf8(a.actionTooltip().toLatin1().data()));
        en.insert(QString("TP_").append(a.actionCd()), QString::fromUtf8(a.actionTooltip().toLatin1().data()));
    }
}

void ApplicationController::staticRelease()
{

}

bool ApplicationController::preFilter()
{
    tDebug() << "Session Id:" << Tf::currentContext()->currentController()->session().id();
    QString ctl = Tf::currentContext()->currentController()->name();
    QString act = Tf::currentContext()->currentController()->activeAction();
    tDebug() << "Access :" << ctl << "/" << act;

    if (!isUserLoggedIn()) {
        QString XMLHttpRequest = Tf::currentContext()->currentController()->httpRequest().header().rawHeader("X-Requested-With");

        if (XMLHttpRequest == "XMLHttpRequest") {//is ajax request
            renderTemplate("Welcome/signIn");
        } else { //Normal request
            redirect(url("Welcome", "signIn"));
        }

        return false;
    } else {
        QString userName = identityKeyOfLoginUser();

        //admin could access all pages.
        if (userName == "admin" || ctl.toLower() == "partialservice" || ctl.toLower() == "dataservice") {
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
