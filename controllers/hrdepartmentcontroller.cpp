#include "hrdepartmentcontroller.h"
#include "dataservicecontroller.h"

#include "dept.h"
#include "deptvalidator.h"

#include "deptsubdept.h"
#include "deptuser.h"
#include "orgdept.h"

#include "sqlobjects/deptobject.h"
#include "sqlobjects/deptsubdeptobject.h"
#include "sqlobjects/deptuserobject.h"
#include "sqlobjects/orgdeptobject.h"
#include "sqlobjects/alertdefdeptobject.h"
#include "sqlobjects/advsrytaskdeptobject.h"
#include "sqlobjects/evtdeptobject.h"

void HrDepartmentController::searchDepartment()
{
    render("searchDept");
}

void HrDepartmentController::createDepartment()
{
    if (boolean(CFG("DEPARTMENT_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<DeptObject> mapper;
        TCriteria crt(DeptObject::DeptCd, varMaps.value("deptCd"));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::createRecord<Dept, DeptValidator>(dynamic_cast<ApplicationController *>(this));
}

void HrDepartmentController::deleteDepartment()
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
            TSqlORMapper<DeptSubdeptObject> mapper;
            TCriteria crt(DeptSubdeptObject::DeptId, hmacVal(obj.value("deptId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Having sub Department.")));
                return;
            }
        }
        {
            TSqlORMapper<DeptSubdeptObject> mapper;
            TCriteria crt(DeptSubdeptObject::SubDeptId, hmacVal(obj.value("deptId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Already be assigned to Department.")));
                return;
            }
        }
        {
            TSqlORMapper<DeptUserObject> mapper;
            TCriteria crt(DeptUserObject::DeptId, hmacVal(obj.value("deptId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Having assigned User.")));
                return;
            }
        }
        {
            TSqlORMapper<OrgDeptObject> mapper;
            TCriteria crt(OrgDeptObject::DeptId, hmacVal(obj.value("deptId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Already be assigned to Orgnization.")));
                return;
            }
        }
        {
            TSqlORMapper<AlertDefDeptObject> mapper;
            TCriteria crt(AlertDefDeptObject::DeptId, hmacVal(obj.value("deptId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Having alert definition.")));
                return;
            }
        }
        {
            TSqlORMapper<AdvsryTaskDeptObject> mapper;
            TCriteria crt(AdvsryTaskDeptObject::DeptId, hmacVal(obj.value("deptId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Having task advisory definition.")));
                return;
            }
        }
        {
            TSqlORMapper<EvtDeptObject> mapper;
            TCriteria crt(EvtDeptObject::DeptId, hmacVal(obj.value("deptId")));
            auto sqlobj = mapper.findFirst(crt);

            if (!sqlobj.isNull()) {
                renderJson(jsonObj(false, UI("Having historic event.")));
                return;
            }
        }
    }

    DataServiceController::deleteRecord<DeptObject>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "deptId");
}

void HrDepartmentController::editDepartment()
{
    if (boolean(CFG("DEPARTMENT_DUPLICATE"))) {
        auto varMaps = httpRequest().formItems();
        TSqlORMapper<DeptObject> mapper;
        TCriteria crt(DeptObject::DeptCd, varMaps.value("deptCd"));
        crt.add(DeptObject::DeptId, TSql::NotEqual, hmacVal(varMaps.value("deptId")));
        auto sqlobj = mapper.findFirst(crt);

        if (!sqlobj.isNull()) {
            renderJson(jsonObj(false, UI("Already exists.")));
            return;
        }
    }

    DataServiceController::updateRecord<Dept, DeptObject, DeptValidator>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "deptId", QStringList());
}

void HrDepartmentController::assignSubDepartment()
{
    DataServiceController::assignRecord<DeptSubdept>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "deptId" << "subDeptId");
}

void HrDepartmentController::unassignSubDepartment()
{
    DataServiceController::unassignRecord<DeptSubdept>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "deptId" << "subDeptId");
}

void HrDepartmentController::assignOrg()
{
    DataServiceController::assignRecord<OrgDept>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "deptId" << "orgId");
}

void HrDepartmentController::unassignOrg()
{
    DataServiceController::unassignRecord<OrgDept>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "deptId" << "orgId");
}

void HrDepartmentController::assignUser()
{
    DataServiceController::assignRecord<DeptUser>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "deptId" << "userId");
}

void HrDepartmentController::unassignUser()
{
    DataServiceController::unassignRecord<DeptUser>(dynamic_cast<ApplicationController *>(this),
            QStringList() << "deptId" << "userId");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(HrDepartmentController)
