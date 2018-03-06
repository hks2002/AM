#include "welcomecontroller.h"
#include "applicationhelper.h"
#include <TreeFrogModel>
#include <TreeFrogController>
#include "userapp.h"
#include "sqlobjects/actionappobject.h"
#include "userloginhis.h"
#include <QHostInfo>

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

        QString clientAddress = httpRequest().clientAddress().toString();
        QString clientHostName = QHostInfo::fromName(clientAddress).hostName();
        UserLoginHis::create(user.userId(), QDateTime::currentDateTime(), clientAddress, "00-00-00-00-00-00", clientHostName);

        TSqlQuery query;
        query.prepare("SELECT aa.controller,aa.action "\
                      "FROM action_user au "\
                      "JOIN action_app aa ON aa.action_id= au.action_id "\
                      "WHERE au.user_id=:user_id "
                      "AND aa.active_bool=true "
                      "UNION "
                      "SELECT DISTINCT aa.controller,aa.action "\
                      "FROM action_role ar "\
                      "JOIN action_app aa ON aa.action_id= ar.action_id "\
                      "WHERE ar.role_id IN (SELECT role_id FROM role_user ru WHERE ru.user_id=:user_id) "\
                      "AND aa.active_bool=true");
        query.bind(":user_id", user.userId());
        query.exec();

        if (!query.isActive()) {
            tDebug("query error:%s", query.lastQuery().toLatin1().data());
        }

        while (query.next()) {
            QSqlRecord record = query.record();
            QString url;

            url = record.value(0).toString().toLower() + "/" + record.value(1).toString().toLower();
            tTrace("access allowed :%s allowed to %s", url.toLatin1().data(), userName.toLatin1().data());
            session().insert(url, user.userId());

            //if allow search, allow it use dataservice.
            if (record.value(1).toString().toLower().startsWith("search") || record.value(1).toString().toLower().endsWith("search")) {
                url = "dataservice/" + record.value(1).toString().toLower().replace("search", "");
                tTrace("access allowed :%s allowed to %s", url.toLatin1().data(), userName.toLatin1().data());
                session().insert(url, user.userId());
            }
        }

        query.finish();
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
