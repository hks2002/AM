#include <TSqlQuery>
#include "ajaxservicecontroller.h"

#include "actionapp.h"
#include "sqlobjects/actionappobject.h"
#include "actionrole.h"
#include "sqlobjects/actionroleobject.h"
#include "actionuser.h"
#include "sqlobjects/actionuserobject.h"
#include "address.h"
#include "sqlobjects/addressobject.h"
#include "advsryattachment.h"
#include "sqlobjects/advsryattachmentobject.h"
#include "advsrypart.h"
#include "sqlobjects/advsrypartobject.h"
#include "advsry.h"
#include "sqlobjects/advsryobject.h"
#include "advsrytaskdept.h"
#include "sqlobjects/advsrytaskdeptobject.h"
#include "advsrytaskrole.h"
#include "sqlobjects/advsrytaskroleobject.h"
#include "advsrytask.h"
#include "sqlobjects/advsrytaskobject.h"
#include "advsrytaskuser.h"
#include "sqlobjects/advsrytaskuserobject.h"
#include "advsryvendor.h"
#include "sqlobjects/advsryvendorobject.h"
#include "alertdefdept.h"
#include "sqlobjects/alertdefdeptobject.h"
#include "alertdefrole.h"
#include "sqlobjects/alertdefroleobject.h"
#include "alertdef.h"
#include "sqlobjects/alertdefobject.h"
#include "alertdefuser.h"
#include "sqlobjects/alertdefuserobject.h"
#include "alert.h"
#include "sqlobjects/alertobject.h"
#include "alertuserlog.h"
#include "sqlobjects/alertuserlogobject.h"
#include "authority.h"
#include "sqlobjects/authorityobject.h"
#include "button.h"
#include "sqlobjects/buttonobject.h"
#include "carrier.h"
#include "sqlobjects/carrierobject.h"
#include "charge.h"
#include "sqlobjects/chargeobject.h"
#include "city.h"
#include "sqlobjects/cityobject.h"
#include "claimattachment.h"
#include "sqlobjects/claimattachmentobject.h"
#include "claimlabourline.h"
#include "sqlobjects/claimlabourlineobject.h"
#include "claimpartline.h"
#include "sqlobjects/claimpartlineobject.h"
#include "claim.h"
#include "sqlobjects/claimobject.h"
#include "contact.h"
#include "sqlobjects/contactobject.h"
#include "countryprovince.h"
#include "sqlobjects/countryprovinceobject.h"
#include "country.h"
#include "sqlobjects/countryobject.h"
#include "currency.h"
#include "sqlobjects/currencyobject.h"
#include "datatype.h"
#include "sqlobjects/datatypeobject.h"
#include "dept.h"
#include "sqlobjects/deptobject.h"
#include "deptsubdept.h"
#include "sqlobjects/deptsubdeptobject.h"
#include "deptuser.h"
#include "sqlobjects/deptuserobject.h"
#include "eqpassmblbomcapability.h"
#include "sqlobjects/eqpassmblbomcapabilityobject.h"
#include "eqpassmblbomdatatype.h"
#include "sqlobjects/eqpassmblbomdatatypeobject.h"
#include "eqpassmblbomlog.h"
#include "sqlobjects/eqpassmblbomlogobject.h"
#include "eqpassmblbompart.h"
#include "sqlobjects/eqpassmblbompartobject.h"
#include "eqpassmblbompos.h"
#include "sqlobjects/eqpassmblbomposobject.h"
#include "eqpassmblbom.h"
#include "sqlobjects/eqpassmblbomobject.h"
#include "eqpassmblbomthreshold.h"
#include "sqlobjects/eqpassmblbomthresholdobject.h"
#include "eqpassmblbomtree.h"
#include "sqlobjects/eqpassmblbomtreeobject.h"
#include "eqpassmbldatatype.h"
#include "sqlobjects/eqpassmbldatatypeobject.h"
#include "eqpassmbloil.h"
#include "sqlobjects/eqpassmbloilobject.h"
#include "eqpassmbl.h"
#include "sqlobjects/eqpassmblobject.h"
#include "eqpkitpartno.h"
#include "sqlobjects/eqpkitpartnoobject.h"
#include "eqppanel.h"
#include "sqlobjects/eqppanelobject.h"
#include "eqppartnoaltunit.h"
#include "sqlobjects/eqppartnoaltunitobject.h"
#include "eqppartnocapability.h"
#include "sqlobjects/eqppartnocapabilityobject.h"
#include "eqppartnocompatdef.h"
#include "sqlobjects/eqppartnocompatdefobject.h"
#include "eqppartnocompattask.h"
#include "sqlobjects/eqppartnocompattaskobject.h"
#include "eqppartnocontrol.h"
#include "sqlobjects/eqppartnocontrolobject.h"
#include "eqppartnolog.h"
#include "sqlobjects/eqppartnologobject.h"
#include "eqppartnoreliab.h"
#include "sqlobjects/eqppartnoreliabobject.h"
#include "eqppartno.h"
#include "sqlobjects/eqppartnoobject.h"
#include "eqppartnoshipstoragepackage.h"
#include "sqlobjects/eqppartnoshipstoragepackageobject.h"
#include "eqppartnotechdata.h"
#include "sqlobjects/eqppartnotechdataobject.h"
#include "eqppartnovendorexchg.h"
#include "sqlobjects/eqppartnovendorexchgobject.h"
#include "eqppartnovendorprice.h"
#include "sqlobjects/eqppartnovendorpriceobject.h"
#include "eqppartnovendorpur.h"
#include "sqlobjects/eqppartnovendorpurobject.h"
#include "eqppartnovendorrep.h"
#include "sqlobjects/eqppartnovendorrepobject.h"
#include "eqpstocklevel.h"
#include "sqlobjects/eqpstocklevelobject.h"
#include "eqpstockpartno.h"
#include "sqlobjects/eqpstockpartnoobject.h"
#include "eqpstock.h"
#include "sqlobjects/eqpstockobject.h"
#include "eqpzonepanel.h"
#include "sqlobjects/eqpzonepanelobject.h"
#include "eqpzone.h"
#include "sqlobjects/eqpzoneobject.h"
#include "evtdept.h"
#include "sqlobjects/evtdeptobject.h"
#include "evtevent.h"
#include "sqlobjects/evteventobject.h"
#include "evthr.h"
#include "sqlobjects/evthrobject.h"
#include "evtinv.h"
#include "sqlobjects/evtinvobject.h"
#include "evtinvusage.h"
#include "sqlobjects/evtinvusageobject.h"
#include "evtlicense.h"
#include "sqlobjects/evtlicenseobject.h"
#include "evtloc.h"
#include "sqlobjects/evtlocobject.h"
#include "evtoil.h"
#include "sqlobjects/evtoilobject.h"
#include "evtpartno.h"
#include "sqlobjects/evtpartnoobject.h"
#include "evtscheddead.h"
#include "sqlobjects/evtscheddeadobject.h"
#include "evttool.h"
#include "sqlobjects/evttoolobject.h"
#include "evtvendorpotype.h"
#include "sqlobjects/evtvendorpotypeobject.h"
#include "evtvendor.h"
#include "sqlobjects/evtvendorobject.h"
#include "faildeferref.h"
#include "sqlobjects/faildeferrefobject.h"
#include "fcmodel.h"
#include "sqlobjects/fcmodelobject.h"
#include "fcrange.h"
#include "sqlobjects/fcrangeobject.h"
#include "fcrate.h"
#include "sqlobjects/fcrateobject.h"
#include "flightlegnote.h"
#include "sqlobjects/flightlegnoteobject.h"
#include "flightleg.h"
#include "sqlobjects/flightlegobject.h"
#include "flightlegstatuslog.h"
#include "sqlobjects/flightlegstatuslogobject.h"
#include "fncaccount.h"
#include "sqlobjects/fncaccountobject.h"
#include "fnctcode.h"
#include "sqlobjects/fnctcodeobject.h"
#include "fncxactionlogaccount.h"
#include "sqlobjects/fncxactionlogaccountobject.h"
#include "fncxactionlog.h"
#include "sqlobjects/fncxactionlogobject.h"
#include "invacreg.h"
#include "sqlobjects/invacregobject.h"
#include "invadjust.h"
#include "sqlobjects/invadjustobject.h"
#include "invattachment.h"
#include "sqlobjects/invattachmentobject.h"
#include "invcapability.h"
#include "sqlobjects/invcapabilityobject.h"
#include "invcsgnxchg.h"
#include "sqlobjects/invcsgnxchgobject.h"
#include "invcurrusage.h"
#include "sqlobjects/invcurrusageobject.h"
#include "invinv.h"
#include "sqlobjects/invinvobject.h"
#include "invkitmap.h"
#include "sqlobjects/invkitmapobject.h"
#include "invkit.h"
#include "sqlobjects/invkitobject.h"
#include "invxfer.h"
#include "sqlobjects/invxferobject.h"
#include "labourskill.h"
#include "sqlobjects/labourskillobject.h"
#include "licenseprerequisite.h"
#include "sqlobjects/licenseprerequisiteobject.h"
#include "license.h"
#include "sqlobjects/licenseobject.h"
#include "locaddress.h"
#include "sqlobjects/locaddressobject.h"
#include "locairportsetting.h"
#include "sqlobjects/locairportsettingobject.h"
#include "locbinlevel.h"
#include "sqlobjects/locbinlevelobject.h"
#include "loccontact.h"
#include "sqlobjects/loccontactobject.h"
#include "locdocksetting.h"
#include "sqlobjects/locdocksettingobject.h"
#include "locinvrecount.h"
#include "sqlobjects/locinvrecountobject.h"
#include "loclabourcapacity.h"
#include "sqlobjects/loclabourcapacityobject.h"
#include "loclinesetting.h"
#include "sqlobjects/loclinesettingobject.h"
#include "locpartcount.h"
#include "sqlobjects/locpartcountobject.h"
#include "loc.h"
#include "sqlobjects/locobject.h"
#include "locshoprepair.h"
#include "sqlobjects/locshoprepairobject.h"
#include "locsubloc.h"
#include "sqlobjects/locsublocobject.h"
#include "locworktypecapability.h"
#include "sqlobjects/locworktypecapabilityobject.h"
#include "maintprgmcarriermap.h"
#include "sqlobjects/maintprgmcarriermapobject.h"
#include "maintprgmcarriertemptask.h"
#include "sqlobjects/maintprgmcarriertemptaskobject.h"
#include "maintprgmdefn.h"
#include "sqlobjects/maintprgmdefnobject.h"
#include "maintprgmlog.h"
#include "sqlobjects/maintprgmlogobject.h"
#include "maintprgm.h"
#include "sqlobjects/maintprgmobject.h"
#include "maintprgmtask.h"
#include "sqlobjects/maintprgmtaskobject.h"
#include "maintprgmtasktempissuelog.h"
#include "sqlobjects/maintprgmtasktempissuelogobject.h"
#include "manufactattachment.h"
#include "sqlobjects/manufactattachmentobject.h"
#include "manufact.h"
#include "sqlobjects/manufactobject.h"
#include "menu.h"
#include "sqlobjects/menuobject.h"
#include "menusgroupmenu.h"
#include "sqlobjects/menusgroupmenuobject.h"
#include "menusgrouprole.h"
#include "sqlobjects/menusgrouproleobject.h"
#include "menusgroup.h"
#include "sqlobjects/menusgroupobject.h"
#include "menusgroupuser.h"
#include "sqlobjects/menusgroupuserobject.h"
#include "mesurtypeunit.h"
#include "sqlobjects/mesurtypeunitobject.h"
#include "mesurunit.h"
#include "sqlobjects/mesurunitobject.h"
#include "operationcapability.h"
#include "sqlobjects/operationcapabilityobject.h"
#include "orgaddress.h"
#include "sqlobjects/orgaddressobject.h"
#include "orgcode.h"
#include "sqlobjects/orgcodeobject.h"
#include "orgcontact.h"
#include "sqlobjects/orgcontactobject.h"
#include "orgdept.h"
#include "sqlobjects/orgdeptobject.h"
#include "org.h"
#include "sqlobjects/orgobject.h"
#include "orgsuborg.h"
#include "sqlobjects/orgsuborgobject.h"
#include "orgvendorapproval.h"
#include "sqlobjects/orgvendorapprovalobject.h"
#include "ownerapp.h"
#include "sqlobjects/ownerappobject.h"
#include "poattachment.h"
#include "sqlobjects/poattachmentobject.h"
#include "poauth.h"
#include "sqlobjects/poauthobject.h"
#include "poheader.h"
#include "sqlobjects/poheaderobject.h"
#include "poinvoiceattachment.h"
#include "sqlobjects/poinvoiceattachmentobject.h"
#include "poinvoicelinecharge.h"
#include "sqlobjects/poinvoicelinechargeobject.h"
#include "poinvoicelinemap.h"
#include "sqlobjects/poinvoicelinemapobject.h"
#include "poinvoiceline.h"
#include "sqlobjects/poinvoicelineobject.h"
#include "poinvoicelinetax.h"
#include "sqlobjects/poinvoicelinetaxobject.h"
#include "poinvoice.h"
#include "sqlobjects/poinvoiceobject.h"
#include "polinecharge.h"
#include "sqlobjects/polinechargeobject.h"
#include "polinedoc.h"
#include "sqlobjects/polinedocobject.h"
#include "polinekitline.h"
#include "sqlobjects/polinekitlineobject.h"
#include "polinereturnmap.h"
#include "sqlobjects/polinereturnmapobject.h"
#include "poline.h"
#include "sqlobjects/polineobject.h"
#include "polinetax.h"
#include "sqlobjects/polinetaxobject.h"
#include "polinewarranty.h"
#include "sqlobjects/polinewarrantyobject.h"
#include "provincecity.h"
#include "sqlobjects/provincecityobject.h"
#include "province.h"
#include "sqlobjects/provinceobject.h"
#include "qtyunit.h"
#include "sqlobjects/qtyunitobject.h"
#include "quaractionassignment.h"
#include "sqlobjects/quaractionassignmentobject.h"
#include "quaraction.h"
#include "sqlobjects/quaractionobject.h"
#include "quarquar.h"
#include "sqlobjects/quarquarobject.h"
#include "refaccounttype.h"
#include "sqlobjects/refaccounttypeobject.h"
#include "refadvsrytype.h"
#include "sqlobjects/refadvsrytypeobject.h"
#include "refalertstatus.h"
#include "sqlobjects/refalertstatusobject.h"
#include "refassmblclass.h"
#include "sqlobjects/refassmblclassobject.h"
#include "refbomclass.h"
#include "sqlobjects/refbomclassobject.h"
#include "refborrowrate.h"
#include "sqlobjects/refborrowrateobject.h"
#include "refcancelwhen.h"
#include "sqlobjects/refcancelwhenobject.h"
#include "refclaimto.h"
#include "sqlobjects/refclaimtoobject.h"
#include "refcostlineitemtype.h"
#include "sqlobjects/refcostlineitemtypeobject.h"
#include "refcreatewhen.h"
#include "sqlobjects/refcreatewhenobject.h"
#include "refdocdisposition.h"
#include "sqlobjects/refdocdispositionobject.h"
#include "refdocissueby.h"
#include "sqlobjects/refdocissuebyobject.h"
#include "refengunit.h"
#include "sqlobjects/refengunitobject.h"
#include "refeventreason.h"
#include "sqlobjects/refeventreasonobject.h"
#include "refeventstatus.h"
#include "sqlobjects/refeventstatusobject.h"
#include "refeventtype.h"
#include "sqlobjects/refeventtypeobject.h"
#include "reffaildefer.h"
#include "sqlobjects/reffaildeferobject.h"
#include "reffailsevdefer.h"
#include "sqlobjects/reffailsevdeferobject.h"
#include "reffailsev.h"
#include "sqlobjects/reffailsevobject.h"
#include "reffilesave.h"
#include "sqlobjects/reffilesaveobject.h"
#include "reffirstschedfrom.h"
#include "sqlobjects/reffirstschedfromobject.h"
#include "refflightlegstatus.h"
#include "sqlobjects/refflightlegstatusobject.h"
#include "refhazmatdef.h"
#include "sqlobjects/refhazmatdefobject.h"
#include "refinvclass.h"
#include "sqlobjects/refinvclassobject.h"
#include "refinvcond.h"
#include "sqlobjects/refinvcondobject.h"
#include "reflabourrolestatus.h"
#include "sqlobjects/reflabourrolestatusobject.h"
#include "reflabourroletype.h"
#include "sqlobjects/reflabourroletypeobject.h"
#include "reflabourstage.h"
#include "sqlobjects/reflabourstageobject.h"
#include "reflicensestatus.h"
#include "sqlobjects/reflicensestatusobject.h"
#include "refloctype.h"
#include "sqlobjects/refloctypeobject.h"
#include "reflogaction.h"
#include "sqlobjects/reflogactionobject.h"
#include "refmaintprgmstatus.h"
#include "sqlobjects/refmaintprgmstatusobject.h"
#include "refmesurtype.h"
#include "sqlobjects/refmesurtypeobject.h"
#include "refownby.h"
#include "sqlobjects/refownbyobject.h"
#include "refownertype.h"
#include "sqlobjects/refownertypeobject.h"
#include "refpackingdef.h"
#include "sqlobjects/refpackingdefobject.h"
#include "refpartprovidertype.h"
#include "sqlobjects/refpartprovidertypeobject.h"
#include "refpartstatus.h"
#include "sqlobjects/refpartstatusobject.h"
#include "refparttype.h"
#include "sqlobjects/refparttypeobject.h"
#include "refpartuse.h"
#include "sqlobjects/refpartuseobject.h"
#include "refpaymentterms.h"
#include "sqlobjects/refpaymenttermsobject.h"
#include "refpolinetype.h"
#include "sqlobjects/refpolinetypeobject.h"
#include "refpotype.h"
#include "sqlobjects/refpotypeobject.h"
#include "refpricetype.h"
#include "sqlobjects/refpricetypeobject.h"
#include "refreceivecond.h"
#include "sqlobjects/refreceivecondobject.h"
#include "refreceivepriority.h"
#include "sqlobjects/refreceivepriorityobject.h"
#include "refremovereason.h"
#include "sqlobjects/refremovereasonobject.h"
#include "refreqaction.h"
#include "sqlobjects/refreqactionobject.h"
#include "refreqpriority.h"
#include "sqlobjects/refreqpriorityobject.h"
#include "refreqtype.h"
#include "sqlobjects/refreqtypeobject.h"
#include "refreschedfrom.h"
#include "sqlobjects/refreschedfromobject.h"
#include "refschedpartstatus.h"
#include "sqlobjects/refschedpartstatusobject.h"
#include "refsegmentstatus.h"
#include "sqlobjects/refsegmentstatusobject.h"
#include "refshipmenttype.h"
#include "sqlobjects/refshipmenttypeobject.h"
#include "refstocklowactn.h"
#include "sqlobjects/refstocklowactnobject.h"
#include "reftaskclass.h"
#include "sqlobjects/reftaskclassobject.h"
#include "reftaskdefstatus.h"
#include "sqlobjects/reftaskdefstatusobject.h"
#include "reftaskdepaction.h"
#include "sqlobjects/reftaskdepactionobject.h"
#include "refthresholdmode.h"
#include "sqlobjects/refthresholdmodeobject.h"
#include "reftradeterms.h"
#include "sqlobjects/reftradetermsobject.h"
#include "refvendorstatus.h"
#include "sqlobjects/refvendorstatusobject.h"
#include "refvendortype.h"
#include "sqlobjects/refvendortypeobject.h"
#include "refwarrantyevalstatus.h"
#include "sqlobjects/refwarrantyevalstatusobject.h"
#include "refwarrantypriority.h"
#include "sqlobjects/refwarrantypriorityobject.h"
#include "refwarrantystatus.h"
#include "sqlobjects/refwarrantystatusobject.h"
#include "refwarrantysubtype.h"
#include "sqlobjects/refwarrantysubtypeobject.h"
#include "refwarrantytype.h"
#include "sqlobjects/refwarrantytypeobject.h"
#include "refwarrantytypesubtype.h"
#include "sqlobjects/refwarrantytypesubtypeobject.h"
#include "refworkpackagetype.h"
#include "sqlobjects/refworkpackagetypeobject.h"
#include "refxactiontype.h"
#include "sqlobjects/refxactiontypeobject.h"
#include "refxfertype.h"
#include "sqlobjects/refxfertypeobject.h"
#include "regbodydoc.h"
#include "sqlobjects/regbodydocobject.h"
#include "regbody.h"
#include "sqlobjects/regbodyobject.h"
#include "reqpart.h"
#include "sqlobjects/reqpartobject.h"
#include "rfqattachment.h"
#include "sqlobjects/rfqattachmentobject.h"
#include "rfqheader.h"
#include "sqlobjects/rfqheaderobject.h"
#include "rfqline.h"
#include "sqlobjects/rfqlineobject.h"
#include "rfqlinevendorcharge.h"
#include "sqlobjects/rfqlinevendorchargeobject.h"
#include "rfqlinevendor.h"
#include "sqlobjects/rfqlinevendorobject.h"
#include "rfqlinevendortax.h"
#include "sqlobjects/rfqlinevendortaxobject.h"
#include "rfqvendor.h"
#include "sqlobjects/rfqvendorobject.h"
#include "roleapp.h"
#include "sqlobjects/roleappobject.h"
#include "roleuser.h"
#include "sqlobjects/roleuserobject.h"
#include "schedattachment.h"
#include "sqlobjects/schedattachmentobject.h"
#include "schedfigure.h"
#include "sqlobjects/schedfigureobject.h"
#include "schedimpact.h"
#include "sqlobjects/schedimpactobject.h"
#include "schedinstpart.h"
#include "sqlobjects/schedinstpartobject.h"
#include "schedlabouractual.h"
#include "sqlobjects/schedlabouractualobject.h"
#include "schedlaboursched.h"
#include "sqlobjects/schedlabourschedobject.h"
#include "schedlabour.h"
#include "sqlobjects/schedlabourobject.h"
#include "schedpanel.h"
#include "sqlobjects/schedpanelobject.h"
#include "schedpart.h"
#include "sqlobjects/schedpartobject.h"
#include "schedrmvdpart.h"
#include "sqlobjects/schedrmvdpartobject.h"
#include "schedstaskflags.h"
#include "sqlobjects/schedstaskflagsobject.h"
#include "schedstask.h"
#include "sqlobjects/schedstaskobject.h"
#include "schedsteplabour.h"
#include "sqlobjects/schedsteplabourobject.h"
#include "schedstep.h"
#include "sqlobjects/schedstepobject.h"
#include "schedtaskdeadlineext.h"
#include "sqlobjects/schedtaskdeadlineextobject.h"
#include "schedtool.h"
#include "sqlobjects/schedtoolobject.h"
#include "schedwpcostlineitem.h"
#include "sqlobjects/schedwpcostlineitemobject.h"
#include "schedwpline.h"
#include "sqlobjects/schedwplineobject.h"
#include "schedwpmpc.h"
#include "sqlobjects/schedwpmpcobject.h"
#include "schedwp.h"
#include "sqlobjects/schedwpobject.h"
#include "schedwpsign.h"
#include "sqlobjects/schedwpsignobject.h"
#include "schedwpworktype.h"
#include "sqlobjects/schedwpworktypeobject.h"
#include "schedzone.h"
#include "sqlobjects/schedzoneobject.h"
#include "shipsegment.h"
#include "sqlobjects/shipsegmentobject.h"
#include "shipshipmentlinedoc.h"
#include "sqlobjects/shipshipmentlinedocobject.h"
#include "shipshipmentline.h"
#include "sqlobjects/shipshipmentlineobject.h"
#include "shipshipment.h"
#include "sqlobjects/shipshipmentobject.h"
#include "tab.h"
#include "sqlobjects/tabobject.h"
#include "tagtag.h"
#include "sqlobjects/tagtagobject.h"
#include "tagtaskdefn.h"
#include "sqlobjects/tagtaskdefnobject.h"
#include "taskassemblbom.h"
#include "sqlobjects/taskassemblbomobject.h"
#include "taskattachment.h"
#include "sqlobjects/taskattachmentobject.h"
#include "taskblockreqmap.h"
#include "sqlobjects/taskblockreqmapobject.h"
#include "taskcompliance.h"
#include "sqlobjects/taskcomplianceobject.h"
#include "taskdefn.h"
#include "sqlobjects/taskdefnobject.h"
#include "taskfigure.h"
#include "sqlobjects/taskfigureobject.h"
#include "taskflags.h"
#include "sqlobjects/taskflagsobject.h"
#include "taskimpact.h"
#include "sqlobjects/taskimpactobject.h"
#include "taskjicreqmap.h"
#include "sqlobjects/taskjicreqmapobject.h"
#include "tasklabourreq.h"
#include "sqlobjects/tasklabourreqobject.h"
#include "tasklaboursummary.h"
#include "sqlobjects/tasklaboursummaryobject.h"
#include "taskmesur.h"
#include "sqlobjects/taskmesurobject.h"
#include "tasknrest.h"
#include "sqlobjects/tasknrestobject.h"
#include "taskoriginator.h"
#include "sqlobjects/taskoriginatorobject.h"
#include "taskpanel.h"
#include "sqlobjects/taskpanelobject.h"
#include "taskpartno.h"
#include "sqlobjects/taskpartnoobject.h"
#include "taskpartreq.h"
#include "sqlobjects/taskpartreqobject.h"
#include "taskparttransform.h"
#include "sqlobjects/taskparttransformobject.h"
#include "taskrefdoc.h"
#include "sqlobjects/taskrefdocobject.h"
#include "taskschedruleac.h"
#include "sqlobjects/taskschedruleacobject.h"
#include "taskschedruledef.h"
#include "sqlobjects/taskschedruledefobject.h"
#include "taskschedrulemesur.h"
#include "sqlobjects/taskschedrulemesurobject.h"
#include "taskschedrulepart.h"
#include "sqlobjects/taskschedrulepartobject.h"
#include "taskstep.h"
#include "sqlobjects/taskstepobject.h"
#include "tasksubclass.h"
#include "sqlobjects/tasksubclassobject.h"
#include "tasktaskdep.h"
#include "sqlobjects/tasktaskdepobject.h"
#include "tasktasklog.h"
#include "sqlobjects/tasktasklogobject.h"
#include "tasktask.h"
#include "sqlobjects/tasktaskobject.h"
#include "tasktoolreq.h"
#include "sqlobjects/tasktoolreqobject.h"
#include "taskzone.h"
#include "sqlobjects/taskzoneobject.h"
#include "tax.h"
#include "sqlobjects/taxobject.h"
#include "todolistbutton.h"
#include "sqlobjects/todolistbuttonobject.h"
#include "todolistrole.h"
#include "sqlobjects/todolistroleobject.h"
#include "todolist.h"
#include "sqlobjects/todolistobject.h"
#include "todolisttab.h"
#include "sqlobjects/todolisttabobject.h"
#include "todolistuser.h"
#include "sqlobjects/todolistuserobject.h"
#include "transportor.h"
#include "sqlobjects/transportorobject.h"
#include "userapp.h"
#include "sqlobjects/userappobject.h"
#include "userattachment.h"
#include "sqlobjects/userattachmentobject.h"
#include "userauthority.h"
#include "sqlobjects/userauthorityobject.h"
#include "usereleccert.h"
#include "sqlobjects/usereleccertobject.h"
#include "userlicense.h"
#include "sqlobjects/userlicenseobject.h"
#include "userloginhis.h"
#include "sqlobjects/userloginhisobject.h"
#include "userpoauthlvl.h"
#include "sqlobjects/userpoauthlvlobject.h"
#include "userpswdhis.h"
#include "sqlobjects/userpswdhisobject.h"
#include "userskill.h"
#include "sqlobjects/userskillobject.h"
#include "vendoraccount.h"
#include "sqlobjects/vendoraccountobject.h"
#include "vendorattachment.h"
#include "sqlobjects/vendorattachmentobject.h"
#include "vendor.h"
#include "sqlobjects/vendorobject.h"
#include "warrantydefnassmbl.h"
#include "sqlobjects/warrantydefnassmblobject.h"
#include "warrantydefnattachment.h"
#include "sqlobjects/warrantydefnattachmentobject.h"
#include "warrantydefnpart.h"
#include "sqlobjects/warrantydefnpartobject.h"
#include "warrantydefn.h"
#include "sqlobjects/warrantydefnobject.h"
#include "warrantydefnsubtype.h"
#include "sqlobjects/warrantydefnsubtypeobject.h"
#include "warrantydefntask.h"
#include "sqlobjects/warrantydefntaskobject.h"
#include "warrantydefntype.h"
#include "sqlobjects/warrantydefntypeobject.h"
#include "warrantyevallabour.h"
#include "sqlobjects/warrantyevallabourobject.h"
#include "warrantyevalpart.h"
#include "sqlobjects/warrantyevalpartobject.h"
#include "warrantyeval.h"
#include "sqlobjects/warrantyevalobject.h"
#include "warrantyevaltask.h"
#include "sqlobjects/warrantyevaltaskobject.h"
#include "warrantyinitinv.h"
#include "sqlobjects/warrantyinitinvobject.h"
#include "warrantyinit.h"
#include "sqlobjects/warrantyinitobject.h"
#include "warrantyinittask.h"
#include "sqlobjects/warrantyinittaskobject.h"
#include "workpackagebuilder.h"
#include "sqlobjects/workpackagebuilderobject.h"
#include "worktype.h"
#include "sqlobjects/worktypeobject.h"



//NOTE OTHER FUNCTION LINE
void AjaxServiceController::getHttpRequestPara()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        renderErrorResponse(Tf::Forbidden);
        break;

    case Tf::Post:
        fields = httpRequest().formItemValue("fields");

        if (fields.contains(",")) {
            fieldList = fields.split(",");
        }
        else if (fields.contains(";")) {
            fieldList = fields.split(";");
        }

        key        = httpRequest().formItemValue("key");

        pageIndex  = httpRequest().formItemValue("pageIndex", "0").toInt();
        pageSize   = httpRequest().formItemValue("pageSize", "0").toInt();

        sortFields = httpRequest().formItemValue("sortFields");
        sortField  = httpRequest().formItemValue("sortField");
        sortOrder  = httpRequest().formItemValue("sortOrder");
        mode       = httpRequest().queryItemValue("mode");
        break;

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}



void AjaxServiceController::AjaxPageRender(const QString &tablename,
        const QString &selectField,
        const QString &sortColumnsOrders,
        const QString &where,
        const int pageIndex,
        const int pageSize)
{

    QString sql = QString("\
    select row_to_json(t) from\
    (select count(1) as total, %7 %8\
            (select array_to_json(array_agg(row_to_json(t1)))\
             from (select %2 from %1 %3 %4 %5 %6) as t1 ) as data \
      from %1 \
    ) as t");

    int offset = pageIndex * pageSize;
    sql = sql.arg(tablename,
                  selectField.isEmpty() ? "*" : selectField,
                  sortColumnsOrders.isEmpty() ? "" : sortColumnsOrders,
                  where.isEmpty() ? "" : where,
                  offset < 0 ? "" : QString(" offset ") + QString::number(offset),
                  pageSize <= 0 ? "" : QString(" limit ") + QString::number(pageSize),
                  pageIndex < 0 ? "" : QString::number(pageIndex) + " as \"pageIndex\",",
                  pageSize <= 0 ? "" : QString::number(pageSize) + " as \"pageSize\",");

    TSqlQuery query;
    query.prepare(sql);

    query.exec();

    while (query.next()) {
        renderText(query.value(0).toString());
    }

}

void AjaxServiceController::AjaxRender(const QString &tablename,
                                       const QString &selectField,
                                       const QString &sortColumnsOrders,
                                       const QString &where)
{

    QString sql = QString("\
     select array_to_json(array_agg(row_to_json(t1)))\
             from (select %2 from %1 %3 %4 ) as t1 ");

    sql = sql.arg(tablename,
                  selectField.isEmpty() ? "*" : selectField,
                  sortColumnsOrders.isEmpty() ? "" : sortColumnsOrders,
                  where.isEmpty() ? "" : where);

    TSqlQuery query;
    query.prepare(sql);

    query.exec();

    while (query.next()) {
        renderText(query.value(0).toString());
    }

}

void AjaxServiceController::ActionAppSearch()
{
    Render<ActionApp, ActionAppObject>();
}

void AjaxServiceController::ActionRoleSearch()
{
    Render<ActionRole, ActionRoleObject>();
}

void AjaxServiceController::ActionUserSearch()
{
    Render<ActionUser, ActionUserObject>();
}

void AjaxServiceController::AddressSearch()
{
    Render<Address, AddressObject>();
}

void AjaxServiceController::AdvsryAttachmentSearch()
{
    Render<AdvsryAttachment, AdvsryAttachmentObject>();
}

void AjaxServiceController::AdvsryPartSearch()
{
    Render<AdvsryPart, AdvsryPartObject>();
}

void AjaxServiceController::AdvsrySearch()
{
    Render<Advsry, AdvsryObject>();
}

void AjaxServiceController::AdvsryTaskDeptSearch()
{
    Render<AdvsryTaskDept, AdvsryTaskDeptObject>();
}

void AjaxServiceController::AdvsryTaskRoleSearch()
{
    Render<AdvsryTaskRole, AdvsryTaskRoleObject>();
}

void AjaxServiceController::AdvsryTaskSearch()
{
    Render<AdvsryTask, AdvsryTaskObject>();
}

void AjaxServiceController::AdvsryTaskUserSearch()
{
    Render<AdvsryTaskUser, AdvsryTaskUserObject>();
}

void AjaxServiceController::AdvsryVendorSearch()
{
    Render<AdvsryVendor, AdvsryVendorObject>();
}

void AjaxServiceController::AlertDefDeptSearch()
{
    Render<AlertDefDept, AlertDefDeptObject>();
}

void AjaxServiceController::AlertDefRoleSearch()
{
    Render<AlertDefRole, AlertDefRoleObject>();
}

void AjaxServiceController::AlertDefSearch()
{
    Render<AlertDef, AlertDefObject>();
}

void AjaxServiceController::AlertDefUserSearch()
{
    Render<AlertDefUser, AlertDefUserObject>();
}

void AjaxServiceController::AlertSearch()
{
    Render<Alert, AlertObject>();
}

void AjaxServiceController::AlertUserLogSearch()
{
    Render<AlertUserLog, AlertUserLogObject>();
}

void AjaxServiceController::AuthoritySearch()
{
    Render<Authority, AuthorityObject>();
}

void AjaxServiceController::ButtonSearch()
{
    Render<Button, ButtonObject>();
}

void AjaxServiceController::CarrierSearch()
{
    Render<Carrier, CarrierObject>();
}

void AjaxServiceController::ChargeSearch()
{
    Render<Charge, ChargeObject>();
}

void AjaxServiceController::CitySearch()
{
    Render<City, CityObject>();
}

void AjaxServiceController::ClaimAttachmentSearch()
{
    Render<ClaimAttachment, ClaimAttachmentObject>();
}

void AjaxServiceController::ClaimLabourLineSearch()
{
    Render<ClaimLabourLine, ClaimLabourLineObject>();
}

void AjaxServiceController::ClaimPartLineSearch()
{
    Render<ClaimPartLine, ClaimPartLineObject>();
}

void AjaxServiceController::ClaimSearch()
{
    Render<Claim, ClaimObject>();
}

void AjaxServiceController::ContactSearch()
{
    Render<Contact, ContactObject>();
}

void AjaxServiceController::CountryProvinceSearch()
{
    Render<CountryProvince, CountryProvinceObject>();
}

void AjaxServiceController::CountrySearch()
{
    Render<Country, CountryObject>();
}

void AjaxServiceController::CurrencySearch()
{
    Render<Currency, CurrencyObject>();
}

void AjaxServiceController::DataTypeSearch()
{
    Render<DataType, DataTypeObject>();
}

void AjaxServiceController::DeptSearch()
{
    Render<Dept, DeptObject>();
}

void AjaxServiceController::DeptSubdeptSearch()
{
    Render<DeptSubdept, DeptSubdeptObject>();
}

void AjaxServiceController::DeptUserSearch()
{
    Render<DeptUser, DeptUserObject>();
}

void AjaxServiceController::EqpAssmblBomCapabilitySearch()
{
    Render<EqpAssmblBomCapability, EqpAssmblBomCapabilityObject>();
}

void AjaxServiceController::EqpAssmblBomDataTypeSearch()
{
    Render<EqpAssmblBomDataType, EqpAssmblBomDataTypeObject>();
}

void AjaxServiceController::EqpAssmblBomLogSearch()
{
    Render<EqpAssmblBomLog, EqpAssmblBomLogObject>();
}

void AjaxServiceController::EqpAssmblBomPartSearch()
{
    Render<EqpAssmblBomPart, EqpAssmblBomPartObject>();
}

void AjaxServiceController::EqpAssmblBomPosSearch()
{
    Render<EqpAssmblBomPos, EqpAssmblBomPosObject>();
}

void AjaxServiceController::EqpAssmblBomSearch()
{
    Render<EqpAssmblBom, EqpAssmblBomObject>();
}

void AjaxServiceController::EqpAssmblBomThresholdSearch()
{
    Render<EqpAssmblBomThreshold, EqpAssmblBomThresholdObject>();
}

void AjaxServiceController::EqpAssmblBomTreeSearch()
{
    Render<EqpAssmblBomTree, EqpAssmblBomTreeObject>();
}

void AjaxServiceController::EqpAssmblDataTypeSearch()
{
    Render<EqpAssmblDataType, EqpAssmblDataTypeObject>();
}

void AjaxServiceController::EqpAssmblOilSearch()
{
    Render<EqpAssmblOil, EqpAssmblOilObject>();
}

void AjaxServiceController::EqpAssmblSearch()
{
    Render<EqpAssmbl, EqpAssmblObject>();
}

void AjaxServiceController::EqpKitPartNoSearch()
{
    Render<EqpKitPartNo, EqpKitPartNoObject>();
}

void AjaxServiceController::EqpPanelSearch()
{
    Render<EqpPanel, EqpPanelObject>();
}

void AjaxServiceController::EqpPartNoAltUnitSearch()
{
    Render<EqpPartNoAltUnit, EqpPartNoAltUnitObject>();
}

void AjaxServiceController::EqpPartNoCapabilitySearch()
{
    Render<EqpPartNoCapability, EqpPartNoCapabilityObject>();
}

void AjaxServiceController::EqpPartNoCompatDefSearch()
{
    Render<EqpPartNoCompatDef, EqpPartNoCompatDefObject>();
}

void AjaxServiceController::EqpPartNoCompatTaskSearch()
{
    Render<EqpPartNoCompatTask, EqpPartNoCompatTaskObject>();
}

void AjaxServiceController::EqpPartNoControlSearch()
{
    Render<EqpPartNoControl, EqpPartNoControlObject>();
}

void AjaxServiceController::EqpPartNoLogSearch()
{
    Render<EqpPartNoLog, EqpPartNoLogObject>();
}

void AjaxServiceController::EqpPartNoReliabSearch()
{
    Render<EqpPartNoReliab, EqpPartNoReliabObject>();
}

void AjaxServiceController::EqpPartNoSearch()
{
    Render<EqpPartNo, EqpPartNoObject>();
}

void AjaxServiceController::EqpPartNoShipStoragePackageSearch()
{
    Render<EqpPartNoShipStoragePackage, EqpPartNoShipStoragePackageObject>();
}

void AjaxServiceController::EqpPartNoTechDataSearch()
{
    Render<EqpPartNoTechData, EqpPartNoTechDataObject>();
}

void AjaxServiceController::EqpPartNoVendorExchgSearch()
{
    Render<EqpPartNoVendorExchg, EqpPartNoVendorExchgObject>();
}

void AjaxServiceController::EqpPartNoVendorPriceSearch()
{
    Render<EqpPartNoVendorPrice, EqpPartNoVendorPriceObject>();
}

void AjaxServiceController::EqpPartNoVendorPurSearch()
{
    Render<EqpPartNoVendorPur, EqpPartNoVendorPurObject>();
}

void AjaxServiceController::EqpPartNoVendorRepSearch()
{
    Render<EqpPartNoVendorRep, EqpPartNoVendorRepObject>();
}

void AjaxServiceController::EqpStockLevelSearch()
{
    Render<EqpStockLevel, EqpStockLevelObject>();
}

void AjaxServiceController::EqpStockPartNoSearch()
{
    Render<EqpStockPartNo, EqpStockPartNoObject>();
}

void AjaxServiceController::EqpStockSearch()
{
    Render<EqpStock, EqpStockObject>();
}

void AjaxServiceController::EqpZonePanelSearch()
{
    Render<EqpZonePanel, EqpZonePanelObject>();
}

void AjaxServiceController::EqpZoneSearch()
{
    Render<EqpZone, EqpZoneObject>();
}

void AjaxServiceController::EvtDeptSearch()
{
    Render<EvtDept, EvtDeptObject>();
}

void AjaxServiceController::EvtEventSearch()
{
    Render<EvtEvent, EvtEventObject>();
}

void AjaxServiceController::EvtHrSearch()
{
    Render<EvtHr, EvtHrObject>();
}

void AjaxServiceController::EvtInvSearch()
{
    Render<EvtInv, EvtInvObject>();
}

void AjaxServiceController::EvtInvUsageSearch()
{
    Render<EvtInvUsage, EvtInvUsageObject>();
}

void AjaxServiceController::EvtLicenseSearch()
{
    Render<EvtLicense, EvtLicenseObject>();
}

void AjaxServiceController::EvtLocSearch()
{
    Render<EvtLoc, EvtLocObject>();
}

void AjaxServiceController::EvtOilSearch()
{
    Render<EvtOil, EvtOilObject>();
}

void AjaxServiceController::EvtPartNoSearch()
{
    Render<EvtPartNo, EvtPartNoObject>();
}

void AjaxServiceController::EvtSchedDeadSearch()
{
    Render<EvtSchedDead, EvtSchedDeadObject>();
}

void AjaxServiceController::EvtToolSearch()
{
    Render<EvtTool, EvtToolObject>();
}

void AjaxServiceController::EvtVendorPoTypeSearch()
{
    Render<EvtVendorPoType, EvtVendorPoTypeObject>();
}

void AjaxServiceController::EvtVendorSearch()
{
    Render<EvtVendor, EvtVendorObject>();
}

void AjaxServiceController::FailDeferRefSearch()
{
    Render<FailDeferRef, FailDeferRefObject>();
}

void AjaxServiceController::FcModelSearch()
{
    Render<FcModel, FcModelObject>();
}

void AjaxServiceController::FcRangeSearch()
{
    Render<FcRange, FcRangeObject>();
}

void AjaxServiceController::FcRateSearch()
{
    Render<FcRate, FcRateObject>();
}

void AjaxServiceController::FlightLegNoteSearch()
{
    Render<FlightLegNote, FlightLegNoteObject>();
}

void AjaxServiceController::FlightLegSearch()
{
    Render<FlightLeg, FlightLegObject>();
}

void AjaxServiceController::FlightLegStatusLogSearch()
{
    Render<FlightLegStatusLog, FlightLegStatusLogObject>();
}

void AjaxServiceController::FncAccountSearch()
{
    Render<FncAccount, FncAccountObject>();
}

void AjaxServiceController::FncTcodeSearch()
{
    Render<FncTcode, FncTcodeObject>();
}

void AjaxServiceController::FncXactionLogAccountSearch()
{
    Render<FncXactionLogAccount, FncXactionLogAccountObject>();
}

void AjaxServiceController::FncXactionLogSearch()
{
    Render<FncXactionLog, FncXactionLogObject>();
}

void AjaxServiceController::InvAcRegSearch()
{
    Render<InvAcReg, InvAcRegObject>();
}

void AjaxServiceController::InvAdjustSearch()
{
    Render<InvAdjust, InvAdjustObject>();
}

void AjaxServiceController::InvAttachmentSearch()
{
    Render<InvAttachment, InvAttachmentObject>();
}

void AjaxServiceController::InvCapabilitySearch()
{
    Render<InvCapability, InvCapabilityObject>();
}

void AjaxServiceController::InvCsgnXchgSearch()
{
    Render<InvCsgnXchg, InvCsgnXchgObject>();
}

void AjaxServiceController::InvCurrUsageSearch()
{
    Render<InvCurrUsage, InvCurrUsageObject>();
}

void AjaxServiceController::InvInvSearch()
{
    Render<InvInv, InvInvObject>();
}

void AjaxServiceController::InvKitMapSearch()
{
    Render<InvKitMap, InvKitMapObject>();
}

void AjaxServiceController::InvKitSearch()
{
    Render<InvKit, InvKitObject>();
}

void AjaxServiceController::InvXferSearch()
{
    Render<InvXfer, InvXferObject>();
}

void AjaxServiceController::LabourSkillSearch()
{
    Render<LabourSkill, LabourSkillObject>();
}

void AjaxServiceController::LicensePrerequisiteSearch()
{
    Render<LicensePrerequisite, LicensePrerequisiteObject>();
}

void AjaxServiceController::LicenseSearch()
{
    Render<License, LicenseObject>();
}

void AjaxServiceController::LocAddressSearch()
{
    Render<LocAddress, LocAddressObject>();
}

void AjaxServiceController::LocAirportSettingSearch()
{
    Render<LocAirportSetting, LocAirportSettingObject>();
}

void AjaxServiceController::LocBinLevelSearch()
{
    Render<LocBinLevel, LocBinLevelObject>();
}

void AjaxServiceController::LocContactSearch()
{
    Render<LocContact, LocContactObject>();
}

void AjaxServiceController::LocDockSettingSearch()
{
    Render<LocDockSetting, LocDockSettingObject>();
}

void AjaxServiceController::LocInvRecountSearch()
{
    Render<LocInvRecount, LocInvRecountObject>();
}

void AjaxServiceController::LocLabourCapacitySearch()
{
    Render<LocLabourCapacity, LocLabourCapacityObject>();
}

void AjaxServiceController::LocLineSettingSearch()
{
    Render<LocLineSetting, LocLineSettingObject>();
}

void AjaxServiceController::LocPartCountSearch()
{
    Render<LocPartCount, LocPartCountObject>();
}

void AjaxServiceController::LocSearch()
{
    Render<Loc, LocObject>();
}

void AjaxServiceController::LocShopRepairSearch()
{
    Render<LocShopRepair, LocShopRepairObject>();
}

void AjaxServiceController::LocSublocSearch()
{
    Render<LocSubloc, LocSublocObject>();
}

void AjaxServiceController::LocWorkTypeCapabilitySearch()
{
    Render<LocWorkTypeCapability, LocWorkTypeCapabilityObject>();
}

void AjaxServiceController::MaintPrgmCarrierMapSearch()
{
    Render<MaintPrgmCarrierMap, MaintPrgmCarrierMapObject>();
}

void AjaxServiceController::MaintPrgmCarrierTempTaskSearch()
{
    Render<MaintPrgmCarrierTempTask, MaintPrgmCarrierTempTaskObject>();
}

void AjaxServiceController::MaintPrgmDefnSearch()
{
    Render<MaintPrgmDefn, MaintPrgmDefnObject>();
}

void AjaxServiceController::MaintPrgmLogSearch()
{
    Render<MaintPrgmLog, MaintPrgmLogObject>();
}

void AjaxServiceController::MaintPrgmSearch()
{
    Render<MaintPrgm, MaintPrgmObject>();
}

void AjaxServiceController::MaintPrgmTaskSearch()
{
    Render<MaintPrgmTask, MaintPrgmTaskObject>();
}

void AjaxServiceController::MaintPrgmTaskTempIssueLogSearch()
{
    Render<MaintPrgmTaskTempIssueLog, MaintPrgmTaskTempIssueLogObject>();
}

void AjaxServiceController::ManufactAttachmentSearch()
{
    Render<ManufactAttachment, ManufactAttachmentObject>();
}

void AjaxServiceController::ManufactSearch()
{
    Render<Manufact, ManufactObject>();
}

void AjaxServiceController::MenuSearch()
{
    Render<Menu, MenuObject>();
}

void AjaxServiceController::MenusGroupMenuSearch()
{
    Render<MenusGroupMenu, MenusGroupMenuObject>();
}

void AjaxServiceController::MenusGroupRoleSearch()
{
    Render<MenusGroupRole, MenusGroupRoleObject>();
}

void AjaxServiceController::MenusGroupSearch()
{
    Render<MenusGroup, MenusGroupObject>();
}

void AjaxServiceController::MenusGroupUserSearch()
{
    Render<MenusGroupUser, MenusGroupUserObject>();
}

void AjaxServiceController::MesurTypeUnitSearch()
{
    Render<MesurTypeUnit, MesurTypeUnitObject>();
}

void AjaxServiceController::MesurUnitSearch()
{
    Render<MesurUnit, MesurUnitObject>();
}

void AjaxServiceController::OperationCapabilitySearch()
{
    Render<OperationCapability, OperationCapabilityObject>();
}

void AjaxServiceController::OrgAddressSearch()
{
    Render<OrgAddress, OrgAddressObject>();
}

void AjaxServiceController::OrgCodeSearch()
{
    Render<OrgCode, OrgCodeObject>();
}

void AjaxServiceController::OrgContactSearch()
{
    Render<OrgContact, OrgContactObject>();
}

void AjaxServiceController::OrgDeptSearch()
{
    Render<OrgDept, OrgDeptObject>();
}

void AjaxServiceController::OrgSearch()
{
    Render<Org, OrgObject>();
}

void AjaxServiceController::OrgSuborgSearch()
{
    Render<OrgSuborg, OrgSuborgObject>();
}

void AjaxServiceController::OrgVendorApprovalSearch()
{
    Render<OrgVendorApproval, OrgVendorApprovalObject>();
}

void AjaxServiceController::OwnerAppSearch()
{
    Render<OwnerApp, OwnerAppObject>();
}

void AjaxServiceController::PoAttachmentSearch()
{
    Render<PoAttachment, PoAttachmentObject>();
}

void AjaxServiceController::PoAuthSearch()
{
    Render<PoAuth, PoAuthObject>();
}

void AjaxServiceController::PoHeaderSearch()
{
    Render<PoHeader, PoHeaderObject>();
}

void AjaxServiceController::PoInvoiceAttachmentSearch()
{
    Render<PoInvoiceAttachment, PoInvoiceAttachmentObject>();
}

void AjaxServiceController::PoInvoiceLineChargeSearch()
{
    Render<PoInvoiceLineCharge, PoInvoiceLineChargeObject>();
}

void AjaxServiceController::PoInvoiceLineMapSearch()
{
    Render<PoInvoiceLineMap, PoInvoiceLineMapObject>();
}

void AjaxServiceController::PoInvoiceLineSearch()
{
    Render<PoInvoiceLine, PoInvoiceLineObject>();
}

void AjaxServiceController::PoInvoiceLineTaxSearch()
{
    Render<PoInvoiceLineTax, PoInvoiceLineTaxObject>();
}

void AjaxServiceController::PoInvoiceSearch()
{
    Render<PoInvoice, PoInvoiceObject>();
}

void AjaxServiceController::PoLineChargeSearch()
{
    Render<PoLineCharge, PoLineChargeObject>();
}

void AjaxServiceController::PoLineDocSearch()
{
    Render<PoLineDoc, PoLineDocObject>();
}

void AjaxServiceController::PoLineKitLineSearch()
{
    Render<PoLineKitLine, PoLineKitLineObject>();
}

void AjaxServiceController::PoLineReturnMapSearch()
{
    Render<PoLineReturnMap, PoLineReturnMapObject>();
}

void AjaxServiceController::PoLineSearch()
{
    Render<PoLine, PoLineObject>();
}

void AjaxServiceController::PoLineTaxSearch()
{
    Render<PoLineTax, PoLineTaxObject>();
}

void AjaxServiceController::PoLineWarrantySearch()
{
    Render<PoLineWarranty, PoLineWarrantyObject>();
}

void AjaxServiceController::ProvinceCitySearch()
{
    Render<ProvinceCity, ProvinceCityObject>();
}

void AjaxServiceController::ProvinceSearch()
{
    Render<Province, ProvinceObject>();
}

void AjaxServiceController::QtyUnitSearch()
{
    Render<QtyUnit, QtyUnitObject>();
}

void AjaxServiceController::QuarActionAssignmentSearch()
{
    Render<QuarActionAssignment, QuarActionAssignmentObject>();
}

void AjaxServiceController::QuarActionSearch()
{
    Render<QuarAction, QuarActionObject>();
}

void AjaxServiceController::QuarQuarSearch()
{
    Render<QuarQuar, QuarQuarObject>();
}

void AjaxServiceController::RefAccountTypeSearch()
{
    Render<RefAccountType, RefAccountTypeObject>();
}

void AjaxServiceController::RefAdvsryTypeSearch()
{
    Render<RefAdvsryType, RefAdvsryTypeObject>();
}

void AjaxServiceController::RefAlertStatusSearch()
{
    Render<RefAlertStatus, RefAlertStatusObject>();
}

void AjaxServiceController::RefAssmblClassSearch()
{
    Render<RefAssmblClass, RefAssmblClassObject>();
}

void AjaxServiceController::RefBomClassSearch()
{
    Render<RefBomClass, RefBomClassObject>();
}

void AjaxServiceController::RefBorrowRateSearch()
{
    Render<RefBorrowRate, RefBorrowRateObject>();
}

void AjaxServiceController::RefCancelWhenSearch()
{
    Render<RefCancelWhen, RefCancelWhenObject>();
}

void AjaxServiceController::RefClaimToSearch()
{
    Render<RefClaimTo, RefClaimToObject>();
}

void AjaxServiceController::RefCostLineItemTypeSearch()
{
    Render<RefCostLineItemType, RefCostLineItemTypeObject>();
}

void AjaxServiceController::RefCreateWhenSearch()
{
    Render<RefCreateWhen, RefCreateWhenObject>();
}

void AjaxServiceController::RefDocDispositionSearch()
{
    Render<RefDocDisposition, RefDocDispositionObject>();
}

void AjaxServiceController::RefDocIssueBySearch()
{
    Render<RefDocIssueBy, RefDocIssueByObject>();
}

void AjaxServiceController::RefEngUnitSearch()
{
    Render<RefEngUnit, RefEngUnitObject>();
}

void AjaxServiceController::RefEventReasonSearch()
{
    Render<RefEventReason, RefEventReasonObject>();
}

void AjaxServiceController::RefEventStatusSearch()
{
    Render<RefEventStatus, RefEventStatusObject>();
}

void AjaxServiceController::RefEventTypeSearch()
{
    Render<RefEventType, RefEventTypeObject>();
}

void AjaxServiceController::RefFailDeferSearch()
{
    Render<RefFailDefer, RefFailDeferObject>();
}

void AjaxServiceController::RefFailSevDeferSearch()
{
    Render<RefFailSevDefer, RefFailSevDeferObject>();
}

void AjaxServiceController::RefFailSevSearch()
{
    Render<RefFailSev, RefFailSevObject>();
}

void AjaxServiceController::RefFileSaveSearch()
{
    Render<RefFileSave, RefFileSaveObject>();
}

void AjaxServiceController::RefFirstSchedFromSearch()
{
    Render<RefFirstSchedFrom, RefFirstSchedFromObject>();
}

void AjaxServiceController::RefFlightLegStatusSearch()
{
    Render<RefFlightLegStatus, RefFlightLegStatusObject>();
}

void AjaxServiceController::RefHazmatDefSearch()
{
    Render<RefHazmatDef, RefHazmatDefObject>();
}

void AjaxServiceController::RefInvClassSearch()
{
    Render<RefInvClass, RefInvClassObject>();
}

void AjaxServiceController::RefInvCondSearch()
{
    Render<RefInvCond, RefInvCondObject>();
}

void AjaxServiceController::RefLabourRoleStatusSearch()
{
    Render<RefLabourRoleStatus, RefLabourRoleStatusObject>();
}

void AjaxServiceController::RefLabourRoleTypeSearch()
{
    Render<RefLabourRoleType, RefLabourRoleTypeObject>();
}

void AjaxServiceController::RefLabourStageSearch()
{
    Render<RefLabourStage, RefLabourStageObject>();
}

void AjaxServiceController::RefLicenseStatusSearch()
{
    Render<RefLicenseStatus, RefLicenseStatusObject>();
}

void AjaxServiceController::RefLocTypeSearch()
{
    Render<RefLocType, RefLocTypeObject>();
}

void AjaxServiceController::RefLogActionSearch()
{
    Render<RefLogAction, RefLogActionObject>();
}

void AjaxServiceController::RefMaintPrgmStatusSearch()
{
    Render<RefMaintPrgmStatus, RefMaintPrgmStatusObject>();
}

void AjaxServiceController::RefMesurTypeSearch()
{
    Render<RefMesurType, RefMesurTypeObject>();
}

void AjaxServiceController::RefOwnBySearch()
{
    Render<RefOwnBy, RefOwnByObject>();
}

void AjaxServiceController::RefOwnerTypeSearch()
{
    Render<RefOwnerType, RefOwnerTypeObject>();
}

void AjaxServiceController::RefPackingDefSearch()
{
    Render<RefPackingDef, RefPackingDefObject>();
}

void AjaxServiceController::RefPartProviderTypeSearch()
{
    Render<RefPartProviderType, RefPartProviderTypeObject>();
}

void AjaxServiceController::RefPartStatusSearch()
{
    Render<RefPartStatus, RefPartStatusObject>();
}

void AjaxServiceController::RefPartTypeSearch()
{
    Render<RefPartType, RefPartTypeObject>();
}

void AjaxServiceController::RefPartUseSearch()
{
    Render<RefPartUse, RefPartUseObject>();
}

void AjaxServiceController::RefPaymentTermsSearch()
{
    Render<RefPaymentTerms, RefPaymentTermsObject>();
}

void AjaxServiceController::RefPoLineTypeSearch()
{
    Render<RefPoLineType, RefPoLineTypeObject>();
}

void AjaxServiceController::RefPoTypeSearch()
{
    Render<RefPoType, RefPoTypeObject>();
}

void AjaxServiceController::RefPriceTypeSearch()
{
    Render<RefPriceType, RefPriceTypeObject>();
}

void AjaxServiceController::RefReceiveCondSearch()
{
    Render<RefReceiveCond, RefReceiveCondObject>();
}

void AjaxServiceController::RefReceivePrioritySearch()
{
    Render<RefReceivePriority, RefReceivePriorityObject>();
}

void AjaxServiceController::RefRemoveReasonSearch()
{
    Render<RefRemoveReason, RefRemoveReasonObject>();
}

void AjaxServiceController::RefReqActionSearch()
{
    Render<RefReqAction, RefReqActionObject>();
}

void AjaxServiceController::RefReqPrioritySearch()
{
    Render<RefReqPriority, RefReqPriorityObject>();
}

void AjaxServiceController::RefReqTypeSearch()
{
    Render<RefReqType, RefReqTypeObject>();
}

void AjaxServiceController::RefReschedFromSearch()
{
    Render<RefReschedFrom, RefReschedFromObject>();
}

void AjaxServiceController::RefSchedPartStatusSearch()
{
    Render<RefSchedPartStatus, RefSchedPartStatusObject>();
}

void AjaxServiceController::RefSegmentStatusSearch()
{
    Render<RefSegmentStatus, RefSegmentStatusObject>();
}

void AjaxServiceController::RefShipmentTypeSearch()
{
    Render<RefShipmentType, RefShipmentTypeObject>();
}

void AjaxServiceController::RefStockLowActnSearch()
{
    Render<RefStockLowActn, RefStockLowActnObject>();
}

void AjaxServiceController::RefTaskClassSearch()
{
    Render<RefTaskClass, RefTaskClassObject>();
}

void AjaxServiceController::RefTaskDefStatusSearch()
{
    Render<RefTaskDefStatus, RefTaskDefStatusObject>();
}

void AjaxServiceController::RefTaskDepActionSearch()
{
    Render<RefTaskDepAction, RefTaskDepActionObject>();
}

void AjaxServiceController::RefThresholdModeSearch()
{
    Render<RefThresholdMode, RefThresholdModeObject>();
}

void AjaxServiceController::RefTradeTermsSearch()
{
    Render<RefTradeTerms, RefTradeTermsObject>();
}

void AjaxServiceController::RefVendorStatusSearch()
{
    Render<RefVendorStatus, RefVendorStatusObject>();
}

void AjaxServiceController::RefVendorTypeSearch()
{
    Render<RefVendorType, RefVendorTypeObject>();
}

void AjaxServiceController::RefWarrantyEvalStatusSearch()
{
    Render<RefWarrantyEvalStatus, RefWarrantyEvalStatusObject>();
}

void AjaxServiceController::RefWarrantyPrioritySearch()
{
    Render<RefWarrantyPriority, RefWarrantyPriorityObject>();
}

void AjaxServiceController::RefWarrantyStatusSearch()
{
    Render<RefWarrantyStatus, RefWarrantyStatusObject>();
}

void AjaxServiceController::RefWarrantySubtypeSearch()
{
    Render<RefWarrantySubtype, RefWarrantySubtypeObject>();
}

void AjaxServiceController::RefWarrantyTypeSearch()
{
    Render<RefWarrantyType, RefWarrantyTypeObject>();
}

void AjaxServiceController::RefWarrantyTypeSubtypeSearch()
{
    Render<RefWarrantyTypeSubtype, RefWarrantyTypeSubtypeObject>();
}

void AjaxServiceController::RefWorkpackageTypeSearch()
{
    Render<RefWorkpackageType, RefWorkpackageTypeObject>();
}

void AjaxServiceController::RefXactionTypeSearch()
{
    Render<RefXactionType, RefXactionTypeObject>();
}

void AjaxServiceController::RefXferTypeSearch()
{
    Render<RefXferType, RefXferTypeObject>();
}

void AjaxServiceController::RegBodyDocSearch()
{
    Render<RegBodyDoc, RegBodyDocObject>();
}

void AjaxServiceController::RegBodySearch()
{
    Render<RegBody, RegBodyObject>();
}

void AjaxServiceController::ReqPartSearch()
{
    Render<ReqPart, ReqPartObject>();
}

void AjaxServiceController::RfqAttachmentSearch()
{
    Render<RfqAttachment, RfqAttachmentObject>();
}

void AjaxServiceController::RfqHeaderSearch()
{
    Render<RfqHeader, RfqHeaderObject>();
}

void AjaxServiceController::RfqLineSearch()
{
    Render<RfqLine, RfqLineObject>();
}

void AjaxServiceController::RfqLineVendorChargeSearch()
{
    Render<RfqLineVendorCharge, RfqLineVendorChargeObject>();
}

void AjaxServiceController::RfqLineVendorSearch()
{
    Render<RfqLineVendor, RfqLineVendorObject>();
}

void AjaxServiceController::RfqLineVendorTaxSearch()
{
    Render<RfqLineVendorTax, RfqLineVendorTaxObject>();
}

void AjaxServiceController::RfqVendorSearch()
{
    Render<RfqVendor, RfqVendorObject>();
}

void AjaxServiceController::RoleAppSearch()
{
    Render<RoleApp, RoleAppObject>();
}

void AjaxServiceController::RoleUserSearch()
{
    Render<RoleUser, RoleUserObject>();
}

void AjaxServiceController::SchedAttachmentSearch()
{
    Render<SchedAttachment, SchedAttachmentObject>();
}

void AjaxServiceController::SchedFigureSearch()
{
    Render<SchedFigure, SchedFigureObject>();
}

void AjaxServiceController::SchedImpactSearch()
{
    Render<SchedImpact, SchedImpactObject>();
}

void AjaxServiceController::SchedInstPartSearch()
{
    Render<SchedInstPart, SchedInstPartObject>();
}

void AjaxServiceController::SchedLabourActualSearch()
{
    Render<SchedLabourActual, SchedLabourActualObject>();
}

void AjaxServiceController::SchedLabourSchedSearch()
{
    Render<SchedLabourSched, SchedLabourSchedObject>();
}

void AjaxServiceController::SchedLabourSearch()
{
    Render<SchedLabour, SchedLabourObject>();
}

void AjaxServiceController::SchedPanelSearch()
{
    Render<SchedPanel, SchedPanelObject>();
}

void AjaxServiceController::SchedPartSearch()
{
    Render<SchedPart, SchedPartObject>();
}

void AjaxServiceController::SchedRmvdPartSearch()
{
    Render<SchedRmvdPart, SchedRmvdPartObject>();
}

void AjaxServiceController::SchedStaskFlagsSearch()
{
    Render<SchedStaskFlags, SchedStaskFlagsObject>();
}

void AjaxServiceController::SchedStaskSearch()
{
    Render<SchedStask, SchedStaskObject>();
}

void AjaxServiceController::SchedStepLabourSearch()
{
    Render<SchedStepLabour, SchedStepLabourObject>();
}

void AjaxServiceController::SchedStepSearch()
{
    Render<SchedStep, SchedStepObject>();
}

void AjaxServiceController::SchedTaskDeadlineExtSearch()
{
    Render<SchedTaskDeadlineExt, SchedTaskDeadlineExtObject>();
}

void AjaxServiceController::SchedToolSearch()
{
    Render<SchedTool, SchedToolObject>();
}

void AjaxServiceController::SchedWpCostLineItemSearch()
{
    Render<SchedWpCostLineItem, SchedWpCostLineItemObject>();
}

void AjaxServiceController::SchedWpLineSearch()
{
    Render<SchedWpLine, SchedWpLineObject>();
}

void AjaxServiceController::SchedWpMpcSearch()
{
    Render<SchedWpMpc, SchedWpMpcObject>();
}

void AjaxServiceController::SchedWpSearch()
{
    Render<SchedWp, SchedWpObject>();
}

void AjaxServiceController::SchedWpSignSearch()
{
    Render<SchedWpSign, SchedWpSignObject>();
}

void AjaxServiceController::SchedWpWorkTypeSearch()
{
    Render<SchedWpWorkType, SchedWpWorkTypeObject>();
}

void AjaxServiceController::SchedZoneSearch()
{
    Render<SchedZone, SchedZoneObject>();
}

void AjaxServiceController::ShipSegmentSearch()
{
    Render<ShipSegment, ShipSegmentObject>();
}

void AjaxServiceController::ShipShipmentLineDocSearch()
{
    Render<ShipShipmentLineDoc, ShipShipmentLineDocObject>();
}

void AjaxServiceController::ShipShipmentLineSearch()
{
    Render<ShipShipmentLine, ShipShipmentLineObject>();
}

void AjaxServiceController::ShipShipmentSearch()
{
    Render<ShipShipment, ShipShipmentObject>();
}

void AjaxServiceController::TabSearch()
{
    Render<Tab, TabObject>();
}

void AjaxServiceController::TagTagSearch()
{
    Render<TagTag, TagTagObject>();
}

void AjaxServiceController::TagTaskDefnSearch()
{
    Render<TagTaskDefn, TagTaskDefnObject>();
}

void AjaxServiceController::TaskAssemblBomSearch()
{
    Render<TaskAssemblBom, TaskAssemblBomObject>();
}

void AjaxServiceController::TaskAttachmentSearch()
{
    Render<TaskAttachment, TaskAttachmentObject>();
}

void AjaxServiceController::TaskBlockReqMapSearch()
{
    Render<TaskBlockReqMap, TaskBlockReqMapObject>();
}

void AjaxServiceController::TaskComplianceSearch()
{
    Render<TaskCompliance, TaskComplianceObject>();
}

void AjaxServiceController::TaskDefnSearch()
{
    Render<TaskDefn, TaskDefnObject>();
}

void AjaxServiceController::TaskFigureSearch()
{
    Render<TaskFigure, TaskFigureObject>();
}

void AjaxServiceController::TaskFlagsSearch()
{
    Render<TaskFlags, TaskFlagsObject>();
}

void AjaxServiceController::TaskImpactSearch()
{
    Render<TaskImpact, TaskImpactObject>();
}

void AjaxServiceController::TaskJicReqMapSearch()
{
    Render<TaskJicReqMap, TaskJicReqMapObject>();
}

void AjaxServiceController::TaskLabourReqSearch()
{
    Render<TaskLabourReq, TaskLabourReqObject>();
}

void AjaxServiceController::TaskLabourSummarySearch()
{
    Render<TaskLabourSummary, TaskLabourSummaryObject>();
}

void AjaxServiceController::TaskMesurSearch()
{
    Render<TaskMesur, TaskMesurObject>();
}

void AjaxServiceController::TaskNrEstSearch()
{
    Render<TaskNrEst, TaskNrEstObject>();
}

void AjaxServiceController::TaskOriginatorSearch()
{
    Render<TaskOriginator, TaskOriginatorObject>();
}

void AjaxServiceController::TaskPanelSearch()
{
    Render<TaskPanel, TaskPanelObject>();
}

void AjaxServiceController::TaskPartNoSearch()
{
    Render<TaskPartNo, TaskPartNoObject>();
}

void AjaxServiceController::TaskPartReqSearch()
{
    Render<TaskPartReq, TaskPartReqObject>();
}

void AjaxServiceController::TaskPartTransformSearch()
{
    Render<TaskPartTransform, TaskPartTransformObject>();
}

void AjaxServiceController::TaskRefDocSearch()
{
    Render<TaskRefDoc, TaskRefDocObject>();
}

void AjaxServiceController::TaskSchedRuleAcSearch()
{
    Render<TaskSchedRuleAc, TaskSchedRuleAcObject>();
}

void AjaxServiceController::TaskSchedRuleDefSearch()
{
    Render<TaskSchedRuleDef, TaskSchedRuleDefObject>();
}

void AjaxServiceController::TaskSchedRuleMesurSearch()
{
    Render<TaskSchedRuleMesur, TaskSchedRuleMesurObject>();
}

void AjaxServiceController::TaskSchedRulePartSearch()
{
    Render<TaskSchedRulePart, TaskSchedRulePartObject>();
}

void AjaxServiceController::TaskStepSearch()
{
    Render<TaskStep, TaskStepObject>();
}

void AjaxServiceController::TaskSubclassSearch()
{
    Render<TaskSubclass, TaskSubclassObject>();
}

void AjaxServiceController::TaskTaskDepSearch()
{
    Render<TaskTaskDep, TaskTaskDepObject>();
}

void AjaxServiceController::TaskTaskLogSearch()
{
    Render<TaskTaskLog, TaskTaskLogObject>();
}

void AjaxServiceController::TaskTaskSearch()
{
    Render<TaskTask, TaskTaskObject>();
}

void AjaxServiceController::TaskToolReqSearch()
{
    Render<TaskToolReq, TaskToolReqObject>();
}

void AjaxServiceController::TaskZoneSearch()
{
    Render<TaskZone, TaskZoneObject>();
}

void AjaxServiceController::TaxSearch()
{
    Render<Tax, TaxObject>();
}

void AjaxServiceController::TodoListButtonSearch()
{
    Render<TodoListButton, TodoListButtonObject>();
}

void AjaxServiceController::TodoListRoleSearch()
{
    Render<TodoListRole, TodoListRoleObject>();
}

void AjaxServiceController::TodoListSearch()
{
    Render<TodoList, TodoListObject>();
}

void AjaxServiceController::TodoListTabSearch()
{
    Render<TodoListTab, TodoListTabObject>();
}

void AjaxServiceController::TodoListUserSearch()
{
    Render<TodoListUser, TodoListUserObject>();
}

void AjaxServiceController::TransportorSearch()
{
    Render<Transportor, TransportorObject>();
}

void AjaxServiceController::UserAppSearch()
{
    Render<UserApp, UserAppObject>();
}

void AjaxServiceController::UserAttachmentSearch()
{
    Render<UserAttachment, UserAttachmentObject>();
}

void AjaxServiceController::UserAuthoritySearch()
{
    Render<UserAuthority, UserAuthorityObject>();
}

void AjaxServiceController::UserElecCertSearch()
{
    Render<UserElecCert, UserElecCertObject>();
}

void AjaxServiceController::UserLicenseSearch()
{
    Render<UserLicense, UserLicenseObject>();
}

void AjaxServiceController::UserLoginHisSearch()
{
    Render<UserLoginHis, UserLoginHisObject>();
}

void AjaxServiceController::UserPoAuthLvlSearch()
{
    Render<UserPoAuthLvl, UserPoAuthLvlObject>();
}

void AjaxServiceController::UserPswdHisSearch()
{
    Render<UserPswdHis, UserPswdHisObject>();
}

void AjaxServiceController::UserSkillSearch()
{
    Render<UserSkill, UserSkillObject>();
}

void AjaxServiceController::VendorAccountSearch()
{
    Render<VendorAccount, VendorAccountObject>();
}

void AjaxServiceController::VendorAttachmentSearch()
{
    Render<VendorAttachment, VendorAttachmentObject>();
}

void AjaxServiceController::VendorSearch()
{
    Render<Vendor, VendorObject>();
}

void AjaxServiceController::WarrantyDefnAssmblSearch()
{
    Render<WarrantyDefnAssmbl, WarrantyDefnAssmblObject>();
}

void AjaxServiceController::WarrantyDefnAttachmentSearch()
{
    Render<WarrantyDefnAttachment, WarrantyDefnAttachmentObject>();
}

void AjaxServiceController::WarrantyDefnPartSearch()
{
    Render<WarrantyDefnPart, WarrantyDefnPartObject>();
}

void AjaxServiceController::WarrantyDefnSearch()
{
    Render<WarrantyDefn, WarrantyDefnObject>();
}

void AjaxServiceController::WarrantyDefnSubtypeSearch()
{
    Render<WarrantyDefnSubtype, WarrantyDefnSubtypeObject>();
}

void AjaxServiceController::WarrantyDefnTaskSearch()
{
    Render<WarrantyDefnTask, WarrantyDefnTaskObject>();
}

void AjaxServiceController::WarrantyDefnTypeSearch()
{
    Render<WarrantyDefnType, WarrantyDefnTypeObject>();
}

void AjaxServiceController::WarrantyEvalLabourSearch()
{
    Render<WarrantyEvalLabour, WarrantyEvalLabourObject>();
}

void AjaxServiceController::WarrantyEvalPartSearch()
{
    Render<WarrantyEvalPart, WarrantyEvalPartObject>();
}

void AjaxServiceController::WarrantyEvalSearch()
{
    Render<WarrantyEval, WarrantyEvalObject>();
}

void AjaxServiceController::WarrantyEvalTaskSearch()
{
    Render<WarrantyEvalTask, WarrantyEvalTaskObject>();
}

void AjaxServiceController::WarrantyInitInvSearch()
{
    Render<WarrantyInitInv, WarrantyInitInvObject>();
}

void AjaxServiceController::WarrantyInitSearch()
{
    Render<WarrantyInit, WarrantyInitObject>();
}

void AjaxServiceController::WarrantyInitTaskSearch()
{
    Render<WarrantyInitTask, WarrantyInitTaskObject>();
}

void AjaxServiceController::WorkpackageBuilderSearch()
{
    Render<WorkpackageBuilder, WorkpackageBuilderObject>();
}

void AjaxServiceController::WorkTypeSearch()
{
    Render<WorkType, WorkTypeObject>();
}


// Don't remove below this line
T_DEFINE_CONTROLLER(AjaxServiceController)
