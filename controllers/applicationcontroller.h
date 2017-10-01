#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include "applicationhelper.h"

//friend method need forward declear
class DataServiceController;

class T_CONTROLLER_EXPORT ApplicationController : public TActionController
{
    Q_OBJECT
public:
    ApplicationController();
    ApplicationController(const ApplicationController &other);
    virtual ~ApplicationController();

    //Due to these methods are protected, so define a new method, start with 'X'
    //Friend class could use these X method.
    void XrenderText(const QString &text)      { renderText(text); }
    void XrenderErrorResponse(int statusCode)  { renderErrorResponse(statusCode); }
    void XrenderJson(const QJsonObject &obj)   { renderJson(obj); }
    void XrenderJson(const QJsonArray &array)  { renderJson(array); }
    void XrenderJson(const QJsonDocument &doc) { renderJson(doc); }
    void XrollbackTransaction()                { rollbackTransaction(); }

    friend class DataServiceController;
    //template<class M, class V>          friend  void DataServiceController::createRecord(ApplicationController *ctl);
    //template<class M, class O>          friend  void DataServiceController::deleteRecord(ApplicationController *ctl, const QStringList &pklist);
    //template<class M>                   friend  void DataServiceController::assignRecord(ApplicationController *ctl, const QStringList &pklist);
    //template<class M, class O>          friend  void DataServiceController::unassignRecord(ApplicationController *ctl, const QStringList &pklist);
    //template<class M, class O, class V> friend  void DataServiceController::updateRecord(ApplicationController *ctl, const QString &pklist, const QString &fieldlist);

public slots:
    void staticInitialize();
    void staticRelease();

protected:
    virtual bool preFilter();
};


T_DECLARE_CONTROLLER(ApplicationController, applicationcontroller)

#endif // APPLICATIONCONTROLLER_H
