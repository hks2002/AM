#ifndef AJAXSERVICECONTROLLER_H
#define AJAXSERVICECONTROLLER_H
#include <TAbstractModel>
#include <TCriteriaConverter>
#include <TCriteria>
#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT AjaxServiceController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    AjaxServiceController() : ApplicationController() { }

public slots:
    void ActionAppSearch();
    void ActionRoleSearch();
    void ActionUserSearch();
    void AddressSearch();
    void AdvsryAttachmentSearch();
    void AdvsryPartSearch();
    void AdvsrySearch();
    void AdvsryTaskDeptSearch();
    void AdvsryTaskRoleSearch();
    void AdvsryTaskSearch();
    void AdvsryTaskUserSearch();
    void AdvsryVendorSearch();
    void AlertDefDeptSearch();
    void AlertDefRoleSearch();
    void AlertDefSearch();
    void AlertDefUserSearch();
    void AlertSearch();
    void AlertUserLogSearch();
    void AuthoritySearch();
    void ButtonSearch();
    void CarrierSearch();
    void ChargeSearch();
    void CitySearch();
    void ClaimAttachmentSearch();
    void ClaimLabourLineSearch();
    void ClaimPartLineSearch();
    void ClaimSearch();
    void ContactSearch();
    void CountryProvinceSearch();
    void CountrySearch();
    void CurrencySearch();
    void DataTypeSearch();
    void DeptSearch();
    void DeptSubdeptSearch();
    void DeptUserSearch();
    void EqpAssmblBomCapabilitySearch();
    void EqpAssmblBomDataTypeSearch();
    void EqpAssmblBomLogSearch();
    void EqpAssmblBomPartSearch();
    void EqpAssmblBomPosSearch();
    void EqpAssmblBomSearch();
    void EqpAssmblBomThresholdSearch();
    void EqpAssmblBomTreeSearch();
    void EqpAssmblDataTypeSearch();
    void EqpAssmblOilSearch();
    void EqpAssmblSearch();
    void EqpKitPartNoSearch();
    void EqpPanelSearch();
    void EqpPartNoAltUnitSearch();
    void EqpPartNoCapabilitySearch();
    void EqpPartNoCompatDefSearch();
    void EqpPartNoCompatTaskSearch();
    void EqpPartNoControlSearch();
    void EqpPartNoLogSearch();
    void EqpPartNoReliabSearch();
    void EqpPartNoSearch();
    void EqpPartNoShipStoragePackageSearch();
    void EqpPartNoTechDataSearch();
    void EqpPartNoVendorExchgSearch();
    void EqpPartNoVendorPriceSearch();
    void EqpPartNoVendorPurSearch();
    void EqpPartNoVendorRepSearch();
    void EqpStockLevelSearch();
    void EqpStockPartNoSearch();
    void EqpStockSearch();
    void EqpZonePanelSearch();
    void EqpZoneSearch();
    void EvtDeptSearch();
    void EvtEventSearch();
    void EvtHrSearch();
    void EvtInvSearch();
    void EvtInvUsageSearch();
    void EvtLicenseSearch();
    void EvtLocSearch();
    void EvtOilSearch();
    void EvtPartNoSearch();
    void EvtSchedDeadSearch();
    void EvtToolSearch();
    void EvtVendorPoTypeSearch();
    void EvtVendorSearch();
    void FailDeferRefSearch();
    void FcModelSearch();
    void FcRangeSearch();
    void FcRateSearch();
    void FlightLegNoteSearch();
    void FlightLegSearch();
    void FlightLegStatusLogSearch();
    void FncAccountSearch();
    void FncTcodeSearch();
    void FncXactionLogAccountSearch();
    void FncXactionLogSearch();
    void InvAcRegSearch();
    void InvAdjustSearch();
    void InvAttachmentSearch();
    void InvCapabilitySearch();
    void InvCsgnXchgSearch();
    void InvCurrUsageSearch();
    void InvInvSearch();
    void InvKitMapSearch();
    void InvKitSearch();
    void InvXferSearch();
    void LabourSkillSearch();
    void LicensePrerequisiteSearch();
    void LicenseSearch();
    void LocAddressSearch();
    void LocAirportSettingSearch();
    void LocBinLevelSearch();
    void LocContactSearch();
    void LocDockSettingSearch();
    void LocInvRecountSearch();
    void LocLabourCapacitySearch();
    void LocLineSettingSearch();
    void LocPartCountSearch();
    void LocSearch();
    void LocShopRepairSearch();
    void LocSublocSearch();
    void LocWorkTypeCapabilitySearch();
    void MaintPrgmCarrierMapSearch();
    void MaintPrgmCarrierTempTaskSearch();
    void MaintPrgmDefnSearch();
    void MaintPrgmLogSearch();
    void MaintPrgmSearch();
    void MaintPrgmTaskSearch();
    void MaintPrgmTaskTempIssueLogSearch();
    void ManufactAttachmentSearch();
    void ManufactSearch();
    void MenuSearch();
    void MenusGroupMenuSearch();
    void MenusGroupRoleSearch();
    void MenusGroupSearch();
    void MenusGroupUserSearch();
    void MesurTypeUnitSearch();
    void MesurUnitSearch();
    void OperationCapabilitySearch();
    void OrgAddressSearch();
    void OrgCodeSearch();
    void OrgContactSearch();
    void OrgDeptSearch();
    void OrgSearch();
    void OrgSuborgSearch();
    void OrgVendorApprovalSearch();
    void OwnerAppSearch();
    void PoAttachmentSearch();
    void PoAuthSearch();
    void PoHeaderSearch();
    void PoInvoiceAttachmentSearch();
    void PoInvoiceLineChargeSearch();
    void PoInvoiceLineMapSearch();
    void PoInvoiceLineSearch();
    void PoInvoiceLineTaxSearch();
    void PoInvoiceSearch();
    void PoLineChargeSearch();
    void PoLineDocSearch();
    void PoLineKitLineSearch();
    void PoLineReturnMapSearch();
    void PoLineSearch();
    void PoLineTaxSearch();
    void PoLineWarrantySearch();
    void ProvinceCitySearch();
    void ProvinceSearch();
    void QtyUnitSearch();
    void QuarActionAssignmentSearch();
    void QuarActionSearch();
    void QuarQuarSearch();
    void RefAccountTypeSearch();
    void RefAdvsryTypeSearch();
    void RefAlertStatusSearch();
    void RefAssmblClassSearch();
    void RefBomClassSearch();
    void RefBorrowRateSearch();
    void RefCancelWhenSearch();
    void RefClaimToSearch();
    void RefCostLineItemTypeSearch();
    void RefCreateWhenSearch();
    void RefDocDispositionSearch();
    void RefDocIssueBySearch();
    void RefEngUnitSearch();
    void RefEventReasonSearch();
    void RefEventStatusSearch();
    void RefEventTypeSearch();
    void RefFailDeferSearch();
    void RefFailSevDeferSearch();
    void RefFailSevSearch();
    void RefFileSaveSearch();
    void RefFirstSchedFromSearch();
    void RefFlightLegStatusSearch();
    void RefHazmatDefSearch();
    void RefInvClassSearch();
    void RefInvCondSearch();
    void RefLabourRoleStatusSearch();
    void RefLabourRoleTypeSearch();
    void RefLabourStageSearch();
    void RefLicenseStatusSearch();
    void RefLocTypeSearch();
    void RefLogActionSearch();
    void RefMaintPrgmStatusSearch();
    void RefMesurTypeSearch();
    void RefOwnBySearch();
    void RefOwnerTypeSearch();
    void RefPackingDefSearch();
    void RefPartProviderTypeSearch();
    void RefPartStatusSearch();
    void RefPartTypeSearch();
    void RefPartUseSearch();
    void RefPaymentTermsSearch();
    void RefPoLineTypeSearch();
    void RefPoTypeSearch();
    void RefPriceTypeSearch();
    void RefReceiveCondSearch();
    void RefReceivePrioritySearch();
    void RefRemoveReasonSearch();
    void RefReqActionSearch();
    void RefReqPrioritySearch();
    void RefReqTypeSearch();
    void RefReschedFromSearch();
    void RefSchedPartStatusSearch();
    void RefSegmentStatusSearch();
    void RefShipmentTypeSearch();
    void RefStockLowActnSearch();
    void RefTaskClassSearch();
    void RefTaskDefStatusSearch();
    void RefTaskDepActionSearch();
    void RefThresholdModeSearch();
    void RefTradeTermsSearch();
    void RefVendorStatusSearch();
    void RefVendorTypeSearch();
    void RefWarrantyEvalStatusSearch();
    void RefWarrantyPrioritySearch();
    void RefWarrantyStatusSearch();
    void RefWarrantySubtypeSearch();
    void RefWarrantyTypeSearch();
    void RefWarrantyTypeSubtypeSearch();
    void RefWorkpackageTypeSearch();
    void RefXactionTypeSearch();
    void RefXferTypeSearch();
    void RegBodyDocSearch();
    void RegBodySearch();
    void ReqPartSearch();
    void RfqAttachmentSearch();
    void RfqHeaderSearch();
    void RfqLineSearch();
    void RfqLineVendorChargeSearch();
    void RfqLineVendorSearch();
    void RfqLineVendorTaxSearch();
    void RfqVendorSearch();
    void RoleAppSearch();
    void RoleUserSearch();
    void SchedAttachmentSearch();
    void SchedFigureSearch();
    void SchedImpactSearch();
    void SchedInstPartSearch();
    void SchedLabourActualSearch();
    void SchedLabourSchedSearch();
    void SchedLabourSearch();
    void SchedPanelSearch();
    void SchedPartSearch();
    void SchedRmvdPartSearch();
    void SchedStaskFlagsSearch();
    void SchedStaskSearch();
    void SchedStepLabourSearch();
    void SchedStepSearch();
    void SchedTaskDeadlineExtSearch();
    void SchedToolSearch();
    void SchedWpCostLineItemSearch();
    void SchedWpLineSearch();
    void SchedWpMpcSearch();
    void SchedWpSearch();
    void SchedWpSignSearch();
    void SchedWpWorkTypeSearch();
    void SchedZoneSearch();
    void ShipSegmentSearch();
    void ShipShipmentLineDocSearch();
    void ShipShipmentLineSearch();
    void ShipShipmentSearch();
    void TabSearch();
    void TagTagSearch();
    void TagTaskDefnSearch();
    void TaskAssemblBomSearch();
    void TaskAttachmentSearch();
    void TaskBlockReqMapSearch();
    void TaskComplianceSearch();
    void TaskDefnSearch();
    void TaskFigureSearch();
    void TaskFlagsSearch();
    void TaskImpactSearch();
    void TaskJicReqMapSearch();
    void TaskLabourReqSearch();
    void TaskLabourSummarySearch();
    void TaskMesurSearch();
    void TaskNrEstSearch();
    void TaskOriginatorSearch();
    void TaskPanelSearch();
    void TaskPartNoSearch();
    void TaskPartReqSearch();
    void TaskPartTransformSearch();
    void TaskRefDocSearch();
    void TaskSchedRuleAcSearch();
    void TaskSchedRuleDefSearch();
    void TaskSchedRuleMesurSearch();
    void TaskSchedRulePartSearch();
    void TaskStepSearch();
    void TaskSubclassSearch();
    void TaskTaskDepSearch();
    void TaskTaskLogSearch();
    void TaskTaskSearch();
    void TaskToolReqSearch();
    void TaskZoneSearch();
    void TaxSearch();
    void TodoListButtonSearch();
    void TodoListRoleSearch();
    void TodoListSearch();
    void TodoListTabSearch();
    void TodoListUserSearch();
    void TransportorSearch();
    void UserAppSearch();
    void UserAttachmentSearch();
    void UserAuthoritySearch();
    void UserElecCertSearch();
    void UserLicenseSearch();
    void UserLoginHisSearch();
    void UserPoAuthLvlSearch();
    void UserPswdHisSearch();
    void UserSkillSearch();
    void VendorAccountSearch();
    void VendorAttachmentSearch();
    void VendorSearch();
    void WarrantyDefnAssmblSearch();
    void WarrantyDefnAttachmentSearch();
    void WarrantyDefnPartSearch();
    void WarrantyDefnSearch();
    void WarrantyDefnSubtypeSearch();
    void WarrantyDefnTaskSearch();
    void WarrantyDefnTypeSearch();
    void WarrantyEvalLabourSearch();
    void WarrantyEvalPartSearch();
    void WarrantyEvalSearch();
    void WarrantyEvalTaskSearch();
    void WarrantyInitInvSearch();
    void WarrantyInitSearch();
    void WarrantyInitTaskSearch();
    void WorkpackageBuilderSearch();
    void WorkTypeSearch();



    void AjaxPageRender(const QString &tablename,
                        const QString &selectField = "*",
                        const QString &sortColumnsOrders = "",
                        const QString &where = "",
                        const int pageIndex = 0,
                        const int pageSize = -1);
    void AjaxRender(const QString &tablename,
                    const QString &selectField = "*",
                    const QString &sortColumnsOrders = "",
                    const QString &where = "");
private:
    QString fields;
    QString sortFields;
    QString sortField;
    QString sortOrder;
    QString key;
    int pageIndex = 0;
    int pageSize = 100;
    QString mode;

    QStringList fieldList;
    QStringList varFieldList;
    QStringList tableFieldList;
    QString selectField;
    QString sortColumnsOrders;
    QString where;
    QString tablename;

    void getHttpRequestPara();
    void selectFields()
    {
        int len = tableFieldList.length();

        for (int i = 0; i < len; ++i) {
            selectField += tableFieldList.at(i) + " as \"" + varFieldList.at(i) + + "\",";
        }

        selectField.chop(1);
        tDebug(QString(selectField).prepend("selectField:").toLatin1().data());
    }

    template<class T>
    void tableName()
    {
        T obj;
        tDebug(obj.tableName().prepend("get tableName:").toLatin1().data());
        tablename = obj.tableName();
    }

    template<class T>
    QString vTof(const QString &variableName)
    {
        T model;

        tDebug(QString(variableName).append("->").append(
                   model.variableNameToFieldName(variableName)).toLatin1().data());
        return model.variableNameToFieldName(variableName);//if not found, return QString()
    }

    template<class T>
    void setSelectFields()
    {
        T obj;

        for (QString &prop : obj.propertyNames()) {
            tDebug(QString(prop).prepend("get tablefields:").toLatin1().data());

            if (prop.toLower() != "created_at" &&
                    prop.toLower() != "created_by" &&
                    prop.toLower() != "updated_at" &&
                    prop.toLower() != "updated_by" &&
                    prop.toLower() != "modified_at" &&
                    prop.toLower() != "modified_by" &&
                    prop.toLower() != "lock_revision"
               ) {

                varFieldList << TAbstractModel::fieldNameToVariableName(prop);
                tableFieldList << prop;

            }
        }

        selectFields();

    }

    template<class T>
    void setSelectFields(const QStringList &fieldList)
    {
        for (QString prop : fieldList) {
            tDebug(QString(prop).prepend("get tablefields from para:").toLatin1().data());
            QString p = vTof<T>(prop);

            if (!p.isEmpty()) {
                varFieldList << prop;
                tableFieldList << p ;
            }
        }

        selectFields();
    }

    template<class T>
    void setSingleSort()
    {
        QString field = vTof<T>(sortField);

        if (!field.isEmpty()) {
            sortColumnsOrders = QString(" order by ") + field + ' ' + sortOrder;
            tDebug(QString(sortColumnsOrders).prepend("setSingleSort:").toLatin1().data());

        }
    }

    template<class T>
    void setMultiSort()
    {
        if (sortFields.isEmpty()) {
            tDebug(QString("sortFields is empty!").toLatin1().data());
            return;
        }

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(sortFields.toLatin1(), &jsonError);

        if (jsonError.error == QJsonParseError::NoError) {
            if (document.isArray()) {
                QJsonArray array = document.array();
                int size = array.size();

                if (size > 0) {
                    sortColumnsOrders = QString(" order by ");

                    for (int i = 0; i < size; i++) {
                        QJsonValue value = array.at(i);
                        QJsonObject obj = value.toObject();

                        QString field = obj.take("field").toString();
                        QString dir = obj.take("dir").toString().toLower();

                        if (dir.isEmpty()) {
                            dir = "asc";
                        }

                        QString sortfield = vTof<T>(field);

                        if (!sortfield.isEmpty()) {
                            sortColumnsOrders +=  sortfield + ' ' + dir + ',';
                        }

                    }

                    sortColumnsOrders.chop(1);
                    tDebug(QString(sortColumnsOrders).prepend("setMultiSort:").toLatin1().data());
                }

            } else {
                tDebug(QString("sortFields should be an array!").toLatin1().data());
            }
        } else {
            tDebug(QString("sortFields parse error:").append(jsonError.errorString()).toLatin1().data());
        }
    }

    template<class T, class S>
    void setWhere()
    {
        if (key.isEmpty()) {
            tDebug(QString("key is empty!").toLatin1().data());
            return;
        }

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(key.toLatin1(), &jsonError);

        if (jsonError.error == QJsonParseError::NoError) {
            if (document.isArray()) {
                QJsonArray array = document.array();
                int size = array.size();

                TCriteria cri;

                if (size > 0) {

                    for (int i = 0; i < size; i++) {
                        QJsonValue value = array.at(i);
                        QJsonObject obj = value.toObject();

                        QString field = obj.take("field").toString();
                        QString vals = obj.take("vals").toString();
                        int op = obj.take("op").toInt();


                        QString wherefield = vTof<T>(field);

                        if (!wherefield.isEmpty()) {
                            S sqlobj;
                            int propIndex = sqlobj.metaObject()->indexOfProperty(wherefield.toLatin1().data()) -
                                            sqlobj.metaObject()->propertyOffset();

                            switch (op) {
                                case TSql::In:
                                case TSql::NotIn:
                                case TSql::LikeEscape:
                                case TSql::NotLikeEscape:
                                case TSql::ILikeEscape:
                                case TSql::NotILikeEscape:
                                case TSql::Between:
                                case TSql::NotBetween: {
                                        QStringList vallist;

                                        if (vals.contains(",")) {
                                            vallist = vals.split(",");
                                        } else if (vals.contains(";")) {
                                            vallist = vals.split(";");
                                        }

                                        cri.add(propIndex, (TSql::ComparisonOperator)op, vallist);
                                    }

                                default:
                                    cri.add(propIndex, (TSql::ComparisonOperator)op, vals);
                            }
                        }

                    }

                    TCriteriaConverter<S> conv(cri, Tf::currentSqlDatabase(S().databaseId()));
                    where = conv.toString();

                    if (!where.isEmpty()) {
                        where.prepend("where ");
                    }

                    tDebug(QString(where).prepend("where:").toLatin1().data());
                }

            } else {
                tDebug(QString("key should be an array!").toLatin1().data());
            }
        } else {
            tDebug(QString("key parse error:").append(jsonError.errorString()).toLatin1().data());
        }
    }

    template<class T, class S>
    void Render()
    {
        getHttpRequestPara();
        tableName<S>();
        fieldList.isEmpty() ? setSelectFields<S>() : setSelectFields<T>(fieldList);
        setWhere<T, S>();
        sortFields.isEmpty() ? setSingleSort<T>() : setMultiSort<T>();

        if (mode.toLower() == "page") {
            AjaxPageRender(tablename, selectField, sortColumnsOrders, where, pageIndex,
                           pageSize);
        } else {
            AjaxRender(tablename, selectField, sortColumnsOrders, where);
        }
    }
};

#endif // AJAXSERVICECONTROLLER_H
