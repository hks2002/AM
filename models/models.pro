TARGET = model
TEMPLATE = lib
CONFIG += shared c++11
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers sqlobjects mongoobjects
DEPENDPATH  += ../helpers sqlobjects mongoobjects
LIBS += -L../lib -lhelper

include(../appbase.pri)

HEADERS += actionapp.h
HEADERS += actionrole.h
HEADERS += actionuser.h
HEADERS += address.h
HEADERS += advsry.h
HEADERS += advsryattachment.h
HEADERS += advsrypart.h
HEADERS += advsrytask.h
HEADERS += advsrytaskdept.h
HEADERS += advsrytaskrole.h
HEADERS += advsrytaskuser.h
HEADERS += advsryvendor.h
HEADERS += alert.h
HEADERS += alertdef.h
HEADERS += alertdefdept.h
HEADERS += alertdefrole.h
HEADERS += alertdefuser.h
HEADERS += alertuserlog.h
HEADERS += authority.h
HEADERS += button.h
HEADERS += carrier.h
HEADERS += charge.h
HEADERS += city.h
HEADERS += claim.h
HEADERS += claimattachment.h
HEADERS += claimlabourline.h
HEADERS += claimpartline.h
HEADERS += contact.h
HEADERS += country.h
HEADERS += countryprovince.h
HEADERS += currency.h
HEADERS += datatype.h
HEADERS += dept.h
HEADERS += deptsubdept.h
HEADERS += deptuser.h
HEADERS += eqpassmbl.h
HEADERS += eqpassmblbom.h
HEADERS += eqpassmblbomcapability.h
HEADERS += eqpassmblbomdatatype.h
HEADERS += eqpassmblbomlog.h
HEADERS += eqpassmblbompart.h
HEADERS += eqpassmblbompos.h
HEADERS += eqpassmblbomthreshold.h
HEADERS += eqpassmblbomtree.h
HEADERS += eqpassmbldatatype.h
HEADERS += eqpassmbloil.h
HEADERS += eqpkitpartno.h
HEADERS += eqppanel.h
HEADERS += eqppartno.h
HEADERS += eqppartnoaltunit.h
HEADERS += eqppartnocapability.h
HEADERS += eqppartnocompatdef.h
HEADERS += eqppartnocompattask.h
HEADERS += eqppartnocontrol.h
HEADERS += eqppartnolog.h
HEADERS += eqppartnoreliab.h
HEADERS += eqppartnoshipstoragepackage.h
HEADERS += eqppartnotechdata.h
HEADERS += eqppartnovendorexchg.h
HEADERS += eqppartnovendorprice.h
HEADERS += eqppartnovendorpur.h
HEADERS += eqppartnovendorrep.h
HEADERS += eqpstock.h
HEADERS += eqpstocklevel.h
HEADERS += eqpstockpartno.h
HEADERS += eqpzone.h
HEADERS += eqpzonepanel.h
HEADERS += evtdept.h
HEADERS += evtevent.h
HEADERS += evthr.h
HEADERS += evtinv.h
HEADERS += evtinvusage.h
HEADERS += evtlicense.h
HEADERS += evtloc.h
HEADERS += evtoil.h
HEADERS += evtpartno.h
HEADERS += evtscheddead.h
HEADERS += evttool.h
HEADERS += evtvendor.h
HEADERS += evtvendorpotype.h
HEADERS += faildeferref.h
HEADERS += fcmodel.h
HEADERS += fcrange.h
HEADERS += fcrate.h
HEADERS += flightleg.h
HEADERS += flightlegnote.h
HEADERS += flightlegstatuslog.h
HEADERS += fncaccount.h
HEADERS += fnctcode.h
HEADERS += fncxactionlog.h
HEADERS += fncxactionlogaccount.h
HEADERS += invacreg.h
HEADERS += invadjust.h
HEADERS += invattachment.h
HEADERS += invcapability.h
HEADERS += invcsgnxchg.h
HEADERS += invcurrusage.h
HEADERS += invinv.h
HEADERS += invkit.h
HEADERS += invkitmap.h
HEADERS += invxfer.h
HEADERS += labourskill.h
HEADERS += license.h
HEADERS += licenseprerequisite.h
HEADERS += loc.h
HEADERS += locaddress.h
HEADERS += locairportsetting.h
HEADERS += locbinlevel.h
HEADERS += loccontact.h
HEADERS += locdocksetting.h
HEADERS += locinvrecount.h
HEADERS += loclabourcapacity.h
HEADERS += loclinesetting.h
HEADERS += locpartcount.h
HEADERS += locshoprepair.h
HEADERS += locsubloc.h
HEADERS += locworktypecapability.h
HEADERS += maintprgm.h
HEADERS += maintprgmcarriermap.h
HEADERS += maintprgmcarriertemptask.h
HEADERS += maintprgmdefn.h
HEADERS += maintprgmlog.h
HEADERS += maintprgmtask.h
HEADERS += maintprgmtasktempissuelog.h
HEADERS += manufact.h
HEADERS += manufactattachment.h
HEADERS += menu.h
HEADERS += menusgroup.h
HEADERS += menusgroupmenu.h
HEADERS += menusgrouprole.h
HEADERS += menusgroupuser.h
HEADERS += mesurtypeunit.h
HEADERS += mesurunit.h
HEADERS += operationcapability.h
HEADERS += org.h
HEADERS += orgaddress.h
HEADERS += orgcode.h
HEADERS += orgcontact.h
HEADERS += orgdept.h
HEADERS += orgsuborg.h
HEADERS += orgvendorapproval.h
HEADERS += ownerapp.h
HEADERS += poattachment.h
HEADERS += poauth.h
HEADERS += poheader.h
HEADERS += poinvoice.h
HEADERS += poinvoiceattachment.h
HEADERS += poinvoiceline.h
HEADERS += poinvoicelinecharge.h
HEADERS += poinvoicelinemap.h
HEADERS += poinvoicelinetax.h
HEADERS += poline.h
HEADERS += polinecharge.h
HEADERS += polinedoc.h
HEADERS += polinekitline.h
HEADERS += polinereturnmap.h
HEADERS += polinetax.h
HEADERS += polinewarranty.h
HEADERS += province.h
HEADERS += provincecity.h
HEADERS += qtyunit.h
HEADERS += quaraction.h
HEADERS += quaractionassignment.h
HEADERS += quarquar.h
HEADERS += refaccounttype.h
HEADERS += refadvsrytype.h
HEADERS += refalertstatus.h
HEADERS += refassmblclass.h
HEADERS += refbomclass.h
HEADERS += refborrowrate.h
HEADERS += refcancelwhen.h
HEADERS += refclaimto.h
HEADERS += refcostlineitemtype.h
HEADERS += refcreatewhen.h
HEADERS += refdocdisposition.h
HEADERS += refdocissueby.h
HEADERS += refengunit.h
HEADERS += refeventreason.h
HEADERS += refeventstatus.h
HEADERS += refeventtype.h
HEADERS += reffaildefer.h
HEADERS += reffailsev.h
HEADERS += reffailsevdefer.h
HEADERS += reffilesave.h
HEADERS += reffirstschedfrom.h
HEADERS += refflightlegstatus.h
HEADERS += refhazmatdef.h
HEADERS += refinvclass.h
HEADERS += refinvcond.h
HEADERS += reflabourrolestatus.h
HEADERS += reflabourroletype.h
HEADERS += reflabourstage.h
HEADERS += reflicensestatus.h
HEADERS += refloctype.h
HEADERS += reflogaction.h
HEADERS += refmaintprgmstatus.h
HEADERS += refmesurtype.h
HEADERS += refownby.h
HEADERS += refownertype.h
HEADERS += refpackingdef.h
HEADERS += refpartprovidertype.h
HEADERS += refpartstatus.h
HEADERS += refparttype.h
HEADERS += refpartuse.h
HEADERS += refpaymentterms.h
HEADERS += refpolinetype.h
HEADERS += refpotype.h
HEADERS += refpricetype.h
HEADERS += refreceivecond.h
HEADERS += refreceivepriority.h
HEADERS += refremovereason.h
HEADERS += refreqaction.h
HEADERS += refreqpriority.h
HEADERS += refreqtype.h
HEADERS += refreschedfrom.h
HEADERS += refschedpartstatus.h
HEADERS += refsegmentstatus.h
HEADERS += refshipmenttype.h
HEADERS += refstocklowactn.h
HEADERS += reftaskclass.h
HEADERS += reftaskdefstatus.h
HEADERS += reftaskdepaction.h
HEADERS += refthresholdmode.h
HEADERS += reftradeterms.h
HEADERS += refvendorstatus.h
HEADERS += refvendortype.h
HEADERS += refwarrantyevalstatus.h
HEADERS += refwarrantypriority.h
HEADERS += refwarrantystatus.h
HEADERS += refwarrantysubtype.h
HEADERS += refwarrantytype.h
HEADERS += refwarrantytypesubtype.h
HEADERS += refworkpackagetype.h
HEADERS += refxactiontype.h
HEADERS += refxfertype.h
HEADERS += regbody.h
HEADERS += regbodydoc.h
HEADERS += reqpart.h
HEADERS += rfqattachment.h
HEADERS += rfqheader.h
HEADERS += rfqline.h
HEADERS += rfqlinevendor.h
HEADERS += rfqlinevendorcharge.h
HEADERS += rfqlinevendortax.h
HEADERS += rfqvendor.h
HEADERS += roleapp.h
HEADERS += roleuser.h
HEADERS += schedattachment.h
HEADERS += schedfigure.h
HEADERS += schedimpact.h
HEADERS += schedinstpart.h
HEADERS += schedlabour.h
HEADERS += schedlabouractual.h
HEADERS += schedlaboursched.h
HEADERS += schedpanel.h
HEADERS += schedpart.h
HEADERS += schedrmvdpart.h
HEADERS += schedstask.h
HEADERS += schedstaskflags.h
HEADERS += schedstep.h
HEADERS += schedsteplabour.h
HEADERS += schedtaskdeadlineext.h
HEADERS += schedtool.h
HEADERS += schedwp.h
HEADERS += schedwpcostlineitem.h
HEADERS += schedwpline.h
HEADERS += schedwpmpc.h
HEADERS += schedwpsign.h
HEADERS += schedwpworktype.h
HEADERS += schedzone.h
HEADERS += shipsegment.h
HEADERS += shipshipment.h
HEADERS += shipshipmentline.h
HEADERS += shipshipmentlinedoc.h
HEADERS += sqlobjects/actionappobject.h
HEADERS += sqlobjects/actionroleobject.h
HEADERS += sqlobjects/actionuserobject.h
HEADERS += sqlobjects/addressobject.h
HEADERS += sqlobjects/advsryattachmentobject.h
HEADERS += sqlobjects/advsryobject.h
HEADERS += sqlobjects/advsrypartobject.h
HEADERS += sqlobjects/advsrytaskdeptobject.h
HEADERS += sqlobjects/advsrytaskobject.h
HEADERS += sqlobjects/advsrytaskroleobject.h
HEADERS += sqlobjects/advsrytaskuserobject.h
HEADERS += sqlobjects/advsryvendorobject.h
HEADERS += sqlobjects/alertdefdeptobject.h
HEADERS += sqlobjects/alertdefobject.h
HEADERS += sqlobjects/alertdefroleobject.h
HEADERS += sqlobjects/alertdefuserobject.h
HEADERS += sqlobjects/alertobject.h
HEADERS += sqlobjects/alertuserlogobject.h
HEADERS += sqlobjects/authorityobject.h
HEADERS += sqlobjects/buttonobject.h
HEADERS += sqlobjects/carrierobject.h
HEADERS += sqlobjects/chargeobject.h
HEADERS += sqlobjects/cityobject.h
HEADERS += sqlobjects/claimattachmentobject.h
HEADERS += sqlobjects/claimlabourlineobject.h
HEADERS += sqlobjects/claimobject.h
HEADERS += sqlobjects/claimpartlineobject.h
HEADERS += sqlobjects/contactobject.h
HEADERS += sqlobjects/countryobject.h
HEADERS += sqlobjects/countryprovinceobject.h
HEADERS += sqlobjects/currencyobject.h
HEADERS += sqlobjects/datatypeobject.h
HEADERS += sqlobjects/deptobject.h
HEADERS += sqlobjects/deptsubdeptobject.h
HEADERS += sqlobjects/deptuserobject.h
HEADERS += sqlobjects/eqpassmblbomcapabilityobject.h
HEADERS += sqlobjects/eqpassmblbomdatatypeobject.h
HEADERS += sqlobjects/eqpassmblbomlogobject.h
HEADERS += sqlobjects/eqpassmblbomobject.h
HEADERS += sqlobjects/eqpassmblbompartobject.h
HEADERS += sqlobjects/eqpassmblbomposobject.h
HEADERS += sqlobjects/eqpassmblbomthresholdobject.h
HEADERS += sqlobjects/eqpassmblbomtreeobject.h
HEADERS += sqlobjects/eqpassmbldatatypeobject.h
HEADERS += sqlobjects/eqpassmblobject.h
HEADERS += sqlobjects/eqpassmbloilobject.h
HEADERS += sqlobjects/eqpkitpartnoobject.h
HEADERS += sqlobjects/eqppanelobject.h
HEADERS += sqlobjects/eqppartnoaltunitobject.h
HEADERS += sqlobjects/eqppartnocapabilityobject.h
HEADERS += sqlobjects/eqppartnocompatdefobject.h
HEADERS += sqlobjects/eqppartnocompattaskobject.h
HEADERS += sqlobjects/eqppartnocontrolobject.h
HEADERS += sqlobjects/eqppartnologobject.h
HEADERS += sqlobjects/eqppartnoobject.h
HEADERS += sqlobjects/eqppartnoreliabobject.h
HEADERS += sqlobjects/eqppartnoshipstoragepackageobject.h
HEADERS += sqlobjects/eqppartnotechdataobject.h
HEADERS += sqlobjects/eqppartnovendorexchgobject.h
HEADERS += sqlobjects/eqppartnovendorpriceobject.h
HEADERS += sqlobjects/eqppartnovendorpurobject.h
HEADERS += sqlobjects/eqppartnovendorrepobject.h
HEADERS += sqlobjects/eqpstocklevelobject.h
HEADERS += sqlobjects/eqpstockobject.h
HEADERS += sqlobjects/eqpstockpartnoobject.h
HEADERS += sqlobjects/eqpzoneobject.h
HEADERS += sqlobjects/eqpzonepanelobject.h
HEADERS += sqlobjects/evtdeptobject.h
HEADERS += sqlobjects/evteventobject.h
HEADERS += sqlobjects/evthrobject.h
HEADERS += sqlobjects/evtinvobject.h
HEADERS += sqlobjects/evtinvusageobject.h
HEADERS += sqlobjects/evtlicenseobject.h
HEADERS += sqlobjects/evtlocobject.h
HEADERS += sqlobjects/evtoilobject.h
HEADERS += sqlobjects/evtpartnoobject.h
HEADERS += sqlobjects/evtscheddeadobject.h
HEADERS += sqlobjects/evttoolobject.h
HEADERS += sqlobjects/evtvendorobject.h
HEADERS += sqlobjects/evtvendorpotypeobject.h
HEADERS += sqlobjects/faildeferrefobject.h
HEADERS += sqlobjects/fcmodelobject.h
HEADERS += sqlobjects/fcrangeobject.h
HEADERS += sqlobjects/fcrateobject.h
HEADERS += sqlobjects/flightlegnoteobject.h
HEADERS += sqlobjects/flightlegobject.h
HEADERS += sqlobjects/flightlegstatuslogobject.h
HEADERS += sqlobjects/fncaccountobject.h
HEADERS += sqlobjects/fnctcodeobject.h
HEADERS += sqlobjects/fncxactionlogaccountobject.h
HEADERS += sqlobjects/fncxactionlogobject.h
HEADERS += sqlobjects/invacregobject.h
HEADERS += sqlobjects/invadjustobject.h
HEADERS += sqlobjects/invattachmentobject.h
HEADERS += sqlobjects/invcapabilityobject.h
HEADERS += sqlobjects/invcsgnxchgobject.h
HEADERS += sqlobjects/invcurrusageobject.h
HEADERS += sqlobjects/invinvobject.h
HEADERS += sqlobjects/invkitmapobject.h
HEADERS += sqlobjects/invkitobject.h
HEADERS += sqlobjects/invxferobject.h
HEADERS += sqlobjects/labourskillobject.h
HEADERS += sqlobjects/licenseobject.h
HEADERS += sqlobjects/licenseprerequisiteobject.h
HEADERS += sqlobjects/locaddressobject.h
HEADERS += sqlobjects/locairportsettingobject.h
HEADERS += sqlobjects/locbinlevelobject.h
HEADERS += sqlobjects/loccontactobject.h
HEADERS += sqlobjects/locdocksettingobject.h
HEADERS += sqlobjects/locinvrecountobject.h
HEADERS += sqlobjects/loclabourcapacityobject.h
HEADERS += sqlobjects/loclinesettingobject.h
HEADERS += sqlobjects/locobject.h
HEADERS += sqlobjects/locpartcountobject.h
HEADERS += sqlobjects/locshoprepairobject.h
HEADERS += sqlobjects/locsublocobject.h
HEADERS += sqlobjects/locworktypecapabilityobject.h
HEADERS += sqlobjects/maintprgmcarriermapobject.h
HEADERS += sqlobjects/maintprgmcarriertemptaskobject.h
HEADERS += sqlobjects/maintprgmdefnobject.h
HEADERS += sqlobjects/maintprgmlogobject.h
HEADERS += sqlobjects/maintprgmobject.h
HEADERS += sqlobjects/maintprgmtaskobject.h
HEADERS += sqlobjects/maintprgmtasktempissuelogobject.h
HEADERS += sqlobjects/manufactattachmentobject.h
HEADERS += sqlobjects/manufactobject.h
HEADERS += sqlobjects/menuobject.h
HEADERS += sqlobjects/menusgroupmenuobject.h
HEADERS += sqlobjects/menusgroupobject.h
HEADERS += sqlobjects/menusgrouproleobject.h
HEADERS += sqlobjects/menusgroupuserobject.h
HEADERS += sqlobjects/mesurtypeunitobject.h
HEADERS += sqlobjects/mesurunitobject.h
HEADERS += sqlobjects/operationcapabilityobject.h
HEADERS += sqlobjects/orgaddressobject.h
HEADERS += sqlobjects/orgcodeobject.h
HEADERS += sqlobjects/orgcontactobject.h
HEADERS += sqlobjects/orgdeptobject.h
HEADERS += sqlobjects/orgobject.h
HEADERS += sqlobjects/orgsuborgobject.h
HEADERS += sqlobjects/orgvendorapprovalobject.h
HEADERS += sqlobjects/ownerappobject.h
HEADERS += sqlobjects/poattachmentobject.h
HEADERS += sqlobjects/poauthobject.h
HEADERS += sqlobjects/poheaderobject.h
HEADERS += sqlobjects/poinvoiceattachmentobject.h
HEADERS += sqlobjects/poinvoicelinechargeobject.h
HEADERS += sqlobjects/poinvoicelinemapobject.h
HEADERS += sqlobjects/poinvoicelineobject.h
HEADERS += sqlobjects/poinvoicelinetaxobject.h
HEADERS += sqlobjects/poinvoiceobject.h
HEADERS += sqlobjects/polinechargeobject.h
HEADERS += sqlobjects/polinedocobject.h
HEADERS += sqlobjects/polinekitlineobject.h
HEADERS += sqlobjects/polineobject.h
HEADERS += sqlobjects/polinereturnmapobject.h
HEADERS += sqlobjects/polinetaxobject.h
HEADERS += sqlobjects/polinewarrantyobject.h
HEADERS += sqlobjects/provincecityobject.h
HEADERS += sqlobjects/provinceobject.h
HEADERS += sqlobjects/qtyunitobject.h
HEADERS += sqlobjects/quaractionassignmentobject.h
HEADERS += sqlobjects/quaractionobject.h
HEADERS += sqlobjects/quarquarobject.h
HEADERS += sqlobjects/refaccounttypeobject.h
HEADERS += sqlobjects/refadvsrytypeobject.h
HEADERS += sqlobjects/refalertstatusobject.h
HEADERS += sqlobjects/refassmblclassobject.h
HEADERS += sqlobjects/refbomclassobject.h
HEADERS += sqlobjects/refborrowrateobject.h
HEADERS += sqlobjects/refcancelwhenobject.h
HEADERS += sqlobjects/refclaimtoobject.h
HEADERS += sqlobjects/refcostlineitemtypeobject.h
HEADERS += sqlobjects/refcreatewhenobject.h
HEADERS += sqlobjects/refdocdispositionobject.h
HEADERS += sqlobjects/refdocissuebyobject.h
HEADERS += sqlobjects/refengunitobject.h
HEADERS += sqlobjects/refeventreasonobject.h
HEADERS += sqlobjects/refeventstatusobject.h
HEADERS += sqlobjects/refeventtypeobject.h
HEADERS += sqlobjects/reffaildeferobject.h
HEADERS += sqlobjects/reffailsevdeferobject.h
HEADERS += sqlobjects/reffailsevobject.h
HEADERS += sqlobjects/reffilesaveobject.h
HEADERS += sqlobjects/reffirstschedfromobject.h
HEADERS += sqlobjects/refflightlegstatusobject.h
HEADERS += sqlobjects/refhazmatdefobject.h
HEADERS += sqlobjects/refinvclassobject.h
HEADERS += sqlobjects/refinvcondobject.h
HEADERS += sqlobjects/reflabourrolestatusobject.h
HEADERS += sqlobjects/reflabourroletypeobject.h
HEADERS += sqlobjects/reflabourstageobject.h
HEADERS += sqlobjects/reflicensestatusobject.h
HEADERS += sqlobjects/refloctypeobject.h
HEADERS += sqlobjects/reflogactionobject.h
HEADERS += sqlobjects/refmaintprgmstatusobject.h
HEADERS += sqlobjects/refmesurtypeobject.h
HEADERS += sqlobjects/refownbyobject.h
HEADERS += sqlobjects/refownertypeobject.h
HEADERS += sqlobjects/refpackingdefobject.h
HEADERS += sqlobjects/refpartprovidertypeobject.h
HEADERS += sqlobjects/refpartstatusobject.h
HEADERS += sqlobjects/refparttypeobject.h
HEADERS += sqlobjects/refpartuseobject.h
HEADERS += sqlobjects/refpaymenttermsobject.h
HEADERS += sqlobjects/refpolinetypeobject.h
HEADERS += sqlobjects/refpotypeobject.h
HEADERS += sqlobjects/refpricetypeobject.h
HEADERS += sqlobjects/refreceivecondobject.h
HEADERS += sqlobjects/refreceivepriorityobject.h
HEADERS += sqlobjects/refremovereasonobject.h
HEADERS += sqlobjects/refreqactionobject.h
HEADERS += sqlobjects/refreqpriorityobject.h
HEADERS += sqlobjects/refreqtypeobject.h
HEADERS += sqlobjects/refreschedfromobject.h
HEADERS += sqlobjects/refschedpartstatusobject.h
HEADERS += sqlobjects/refsegmentstatusobject.h
HEADERS += sqlobjects/refshipmenttypeobject.h
HEADERS += sqlobjects/refstocklowactnobject.h
HEADERS += sqlobjects/reftaskclassobject.h
HEADERS += sqlobjects/reftaskdefstatusobject.h
HEADERS += sqlobjects/reftaskdepactionobject.h
HEADERS += sqlobjects/refthresholdmodeobject.h
HEADERS += sqlobjects/reftradetermsobject.h
HEADERS += sqlobjects/refvendorstatusobject.h
HEADERS += sqlobjects/refvendortypeobject.h
HEADERS += sqlobjects/refwarrantyevalstatusobject.h
HEADERS += sqlobjects/refwarrantypriorityobject.h
HEADERS += sqlobjects/refwarrantystatusobject.h
HEADERS += sqlobjects/refwarrantysubtypeobject.h
HEADERS += sqlobjects/refwarrantytypeobject.h
HEADERS += sqlobjects/refwarrantytypesubtypeobject.h
HEADERS += sqlobjects/refworkpackagetypeobject.h
HEADERS += sqlobjects/refxactiontypeobject.h
HEADERS += sqlobjects/refxfertypeobject.h
HEADERS += sqlobjects/regbodydocobject.h
HEADERS += sqlobjects/regbodyobject.h
HEADERS += sqlobjects/reqpartobject.h
HEADERS += sqlobjects/rfqattachmentobject.h
HEADERS += sqlobjects/rfqheaderobject.h
HEADERS += sqlobjects/rfqlineobject.h
HEADERS += sqlobjects/rfqlinevendorchargeobject.h
HEADERS += sqlobjects/rfqlinevendorobject.h
HEADERS += sqlobjects/rfqlinevendortaxobject.h
HEADERS += sqlobjects/rfqvendorobject.h
HEADERS += sqlobjects/roleappobject.h
HEADERS += sqlobjects/roleuserobject.h
HEADERS += sqlobjects/schedattachmentobject.h
HEADERS += sqlobjects/schedfigureobject.h
HEADERS += sqlobjects/schedimpactobject.h
HEADERS += sqlobjects/schedinstpartobject.h
HEADERS += sqlobjects/schedlabouractualobject.h
HEADERS += sqlobjects/schedlabourobject.h
HEADERS += sqlobjects/schedlabourschedobject.h
HEADERS += sqlobjects/schedpanelobject.h
HEADERS += sqlobjects/schedpartobject.h
HEADERS += sqlobjects/schedrmvdpartobject.h
HEADERS += sqlobjects/schedstaskflagsobject.h
HEADERS += sqlobjects/schedstaskobject.h
HEADERS += sqlobjects/schedsteplabourobject.h
HEADERS += sqlobjects/schedstepobject.h
HEADERS += sqlobjects/schedtaskdeadlineextobject.h
HEADERS += sqlobjects/schedtoolobject.h
HEADERS += sqlobjects/schedwpcostlineitemobject.h
HEADERS += sqlobjects/schedwplineobject.h
HEADERS += sqlobjects/schedwpmpcobject.h
HEADERS += sqlobjects/schedwpobject.h
HEADERS += sqlobjects/schedwpsignobject.h
HEADERS += sqlobjects/schedwpworktypeobject.h
HEADERS += sqlobjects/schedzoneobject.h
HEADERS += sqlobjects/shipsegmentobject.h
HEADERS += sqlobjects/shipshipmentlinedocobject.h
HEADERS += sqlobjects/shipshipmentlineobject.h
HEADERS += sqlobjects/shipshipmentobject.h
HEADERS += sqlobjects/tabobject.h
HEADERS += sqlobjects/tagtagobject.h
HEADERS += sqlobjects/tagtaskdefnobject.h
HEADERS += sqlobjects/taskassemblbomobject.h
HEADERS += sqlobjects/taskattachmentobject.h
HEADERS += sqlobjects/taskblockreqmapobject.h
HEADERS += sqlobjects/taskcomplianceobject.h
HEADERS += sqlobjects/taskdefnobject.h
HEADERS += sqlobjects/taskfigureobject.h
HEADERS += sqlobjects/taskflagsobject.h
HEADERS += sqlobjects/taskimpactobject.h
HEADERS += sqlobjects/taskjicreqmapobject.h
HEADERS += sqlobjects/tasklabourreqobject.h
HEADERS += sqlobjects/tasklaboursummaryobject.h
HEADERS += sqlobjects/taskmesurobject.h
HEADERS += sqlobjects/tasknrestobject.h
HEADERS += sqlobjects/taskoriginatorobject.h
HEADERS += sqlobjects/taskpanelobject.h
HEADERS += sqlobjects/taskpartnoobject.h
HEADERS += sqlobjects/taskpartreqobject.h
HEADERS += sqlobjects/taskparttransformobject.h
HEADERS += sqlobjects/taskrefdocobject.h
HEADERS += sqlobjects/taskschedruleacobject.h
HEADERS += sqlobjects/taskschedruledefobject.h
HEADERS += sqlobjects/taskschedrulemesurobject.h
HEADERS += sqlobjects/taskschedrulepartobject.h
HEADERS += sqlobjects/taskstepobject.h
HEADERS += sqlobjects/tasksubclassobject.h
HEADERS += sqlobjects/tasktaskdepobject.h
HEADERS += sqlobjects/tasktasklogobject.h
HEADERS += sqlobjects/tasktaskobject.h
HEADERS += sqlobjects/tasktoolreqobject.h
HEADERS += sqlobjects/taskzoneobject.h
HEADERS += sqlobjects/taxobject.h
HEADERS += sqlobjects/todolistbuttonobject.h
HEADERS += sqlobjects/todolistobject.h
HEADERS += sqlobjects/todolistroleobject.h
HEADERS += sqlobjects/todolisttabobject.h
HEADERS += sqlobjects/todolistuserobject.h
HEADERS += sqlobjects/transportorobject.h
HEADERS += sqlobjects/userappobject.h
HEADERS += sqlobjects/userattachmentobject.h
HEADERS += sqlobjects/userauthorityobject.h
HEADERS += sqlobjects/usereleccertobject.h
HEADERS += sqlobjects/userlicenseobject.h
HEADERS += sqlobjects/userloginhisobject.h
HEADERS += sqlobjects/userpoauthlvlobject.h
HEADERS += sqlobjects/userpswdhisobject.h
HEADERS += sqlobjects/userskillobject.h
HEADERS += sqlobjects/vendoraccountobject.h
HEADERS += sqlobjects/vendorattachmentobject.h
HEADERS += sqlobjects/vendorobject.h
HEADERS += sqlobjects/warrantydefnassmblobject.h
HEADERS += sqlobjects/warrantydefnattachmentobject.h
HEADERS += sqlobjects/warrantydefnobject.h
HEADERS += sqlobjects/warrantydefnpartobject.h
HEADERS += sqlobjects/warrantydefnsubtypeobject.h
HEADERS += sqlobjects/warrantydefntaskobject.h
HEADERS += sqlobjects/warrantydefntypeobject.h
HEADERS += sqlobjects/warrantyevallabourobject.h
HEADERS += sqlobjects/warrantyevalobject.h
HEADERS += sqlobjects/warrantyevalpartobject.h
HEADERS += sqlobjects/warrantyevaltaskobject.h
HEADERS += sqlobjects/warrantyinitinvobject.h
HEADERS += sqlobjects/warrantyinitobject.h
HEADERS += sqlobjects/warrantyinittaskobject.h
HEADERS += sqlobjects/workpackagebuilderobject.h
HEADERS += sqlobjects/worktypeobject.h
HEADERS += tab.h
HEADERS += tagtag.h
HEADERS += tagtaskdefn.h
HEADERS += taskassemblbom.h
HEADERS += taskattachment.h
HEADERS += taskblockreqmap.h
HEADERS += taskcompliance.h
HEADERS += taskdefn.h
HEADERS += taskfigure.h
HEADERS += taskflags.h
HEADERS += taskimpact.h
HEADERS += taskjicreqmap.h
HEADERS += tasklabourreq.h
HEADERS += tasklaboursummary.h
HEADERS += taskmesur.h
HEADERS += tasknrest.h
HEADERS += taskoriginator.h
HEADERS += taskpanel.h
HEADERS += taskpartno.h
HEADERS += taskpartreq.h
HEADERS += taskparttransform.h
HEADERS += taskrefdoc.h
HEADERS += taskschedruleac.h
HEADERS += taskschedruledef.h
HEADERS += taskschedrulemesur.h
HEADERS += taskschedrulepart.h
HEADERS += taskstep.h
HEADERS += tasksubclass.h
HEADERS += tasktask.h
HEADERS += tasktaskdep.h
HEADERS += tasktasklog.h
HEADERS += tasktoolreq.h
HEADERS += taskzone.h
HEADERS += tax.h
HEADERS += todolist.h
HEADERS += todolistbutton.h
HEADERS += todolistrole.h
HEADERS += todolisttab.h
HEADERS += todolistuser.h
HEADERS += transportor.h
HEADERS += userapp.h
HEADERS += userattachment.h
HEADERS += userauthority.h
HEADERS += usereleccert.h
HEADERS += userlicense.h
HEADERS += userloginhis.h
HEADERS += userpoauthlvl.h
HEADERS += userpswdhis.h
HEADERS += userskill.h
HEADERS += vendor.h
HEADERS += vendoraccount.h
HEADERS += vendorattachment.h
HEADERS += warrantydefn.h
HEADERS += warrantydefnassmbl.h
HEADERS += warrantydefnattachment.h
HEADERS += warrantydefnpart.h
HEADERS += warrantydefnsubtype.h
HEADERS += warrantydefntask.h
HEADERS += warrantydefntype.h
HEADERS += warrantyeval.h
HEADERS += warrantyevallabour.h
HEADERS += warrantyevalpart.h
HEADERS += warrantyevaltask.h
HEADERS += warrantyinit.h
HEADERS += warrantyinitinv.h
HEADERS += warrantyinittask.h
HEADERS += workpackagebuilder.h
HEADERS += worktype.h
SOURCES += actionapp.cpp
SOURCES += actionrole.cpp
SOURCES += actionuser.cpp
SOURCES += address.cpp
SOURCES += advsry.cpp
SOURCES += advsryattachment.cpp
SOURCES += advsrypart.cpp
SOURCES += advsrytask.cpp
SOURCES += advsrytaskdept.cpp
SOURCES += advsrytaskrole.cpp
SOURCES += advsrytaskuser.cpp
SOURCES += advsryvendor.cpp
SOURCES += alert.cpp
SOURCES += alertdef.cpp
SOURCES += alertdefdept.cpp
SOURCES += alertdefrole.cpp
SOURCES += alertdefuser.cpp
SOURCES += alertuserlog.cpp
SOURCES += authority.cpp
SOURCES += button.cpp
SOURCES += carrier.cpp
SOURCES += charge.cpp
SOURCES += city.cpp
SOURCES += claim.cpp
SOURCES += claimattachment.cpp
SOURCES += claimlabourline.cpp
SOURCES += claimpartline.cpp
SOURCES += contact.cpp
SOURCES += country.cpp
SOURCES += countryprovince.cpp
SOURCES += currency.cpp
SOURCES += datatype.cpp
SOURCES += dept.cpp
SOURCES += deptsubdept.cpp
SOURCES += deptuser.cpp
SOURCES += eqpassmbl.cpp
SOURCES += eqpassmblbom.cpp
SOURCES += eqpassmblbomcapability.cpp
SOURCES += eqpassmblbomdatatype.cpp
SOURCES += eqpassmblbomlog.cpp
SOURCES += eqpassmblbompart.cpp
SOURCES += eqpassmblbompos.cpp
SOURCES += eqpassmblbomthreshold.cpp
SOURCES += eqpassmblbomtree.cpp
SOURCES += eqpassmbldatatype.cpp
SOURCES += eqpassmbloil.cpp
SOURCES += eqpkitpartno.cpp
SOURCES += eqppanel.cpp
SOURCES += eqppartno.cpp
SOURCES += eqppartnoaltunit.cpp
SOURCES += eqppartnocapability.cpp
SOURCES += eqppartnocompatdef.cpp
SOURCES += eqppartnocompattask.cpp
SOURCES += eqppartnocontrol.cpp
SOURCES += eqppartnolog.cpp
SOURCES += eqppartnoreliab.cpp
SOURCES += eqppartnoshipstoragepackage.cpp
SOURCES += eqppartnotechdata.cpp
SOURCES += eqppartnovendorexchg.cpp
SOURCES += eqppartnovendorprice.cpp
SOURCES += eqppartnovendorpur.cpp
SOURCES += eqppartnovendorrep.cpp
SOURCES += eqpstock.cpp
SOURCES += eqpstocklevel.cpp
SOURCES += eqpstockpartno.cpp
SOURCES += eqpzone.cpp
SOURCES += eqpzonepanel.cpp
SOURCES += evtdept.cpp
SOURCES += evtevent.cpp
SOURCES += evthr.cpp
SOURCES += evtinv.cpp
SOURCES += evtinvusage.cpp
SOURCES += evtlicense.cpp
SOURCES += evtloc.cpp
SOURCES += evtoil.cpp
SOURCES += evtpartno.cpp
SOURCES += evtscheddead.cpp
SOURCES += evttool.cpp
SOURCES += evtvendor.cpp
SOURCES += evtvendorpotype.cpp
SOURCES += faildeferref.cpp
SOURCES += fcmodel.cpp
SOURCES += fcrange.cpp
SOURCES += fcrate.cpp
SOURCES += flightleg.cpp
SOURCES += flightlegnote.cpp
SOURCES += flightlegstatuslog.cpp
SOURCES += fncaccount.cpp
SOURCES += fnctcode.cpp
SOURCES += fncxactionlog.cpp
SOURCES += fncxactionlogaccount.cpp
SOURCES += invacreg.cpp
SOURCES += invadjust.cpp
SOURCES += invattachment.cpp
SOURCES += invcapability.cpp
SOURCES += invcsgnxchg.cpp
SOURCES += invcurrusage.cpp
SOURCES += invinv.cpp
SOURCES += invkit.cpp
SOURCES += invkitmap.cpp
SOURCES += invxfer.cpp
SOURCES += labourskill.cpp
SOURCES += license.cpp
SOURCES += licenseprerequisite.cpp
SOURCES += loc.cpp
SOURCES += locaddress.cpp
SOURCES += locairportsetting.cpp
SOURCES += locbinlevel.cpp
SOURCES += loccontact.cpp
SOURCES += locdocksetting.cpp
SOURCES += locinvrecount.cpp
SOURCES += loclabourcapacity.cpp
SOURCES += loclinesetting.cpp
SOURCES += locpartcount.cpp
SOURCES += locshoprepair.cpp
SOURCES += locsubloc.cpp
SOURCES += locworktypecapability.cpp
SOURCES += maintprgm.cpp
SOURCES += maintprgmcarriermap.cpp
SOURCES += maintprgmcarriertemptask.cpp
SOURCES += maintprgmdefn.cpp
SOURCES += maintprgmlog.cpp
SOURCES += maintprgmtask.cpp
SOURCES += maintprgmtasktempissuelog.cpp
SOURCES += manufact.cpp
SOURCES += manufactattachment.cpp
SOURCES += menu.cpp
SOURCES += menusgroup.cpp
SOURCES += menusgroupmenu.cpp
SOURCES += menusgrouprole.cpp
SOURCES += menusgroupuser.cpp
SOURCES += mesurtypeunit.cpp
SOURCES += mesurunit.cpp
SOURCES += operationcapability.cpp
SOURCES += org.cpp
SOURCES += orgaddress.cpp
SOURCES += orgcode.cpp
SOURCES += orgcontact.cpp
SOURCES += orgdept.cpp
SOURCES += orgsuborg.cpp
SOURCES += orgvendorapproval.cpp
SOURCES += ownerapp.cpp
SOURCES += poattachment.cpp
SOURCES += poauth.cpp
SOURCES += poheader.cpp
SOURCES += poinvoice.cpp
SOURCES += poinvoiceattachment.cpp
SOURCES += poinvoiceline.cpp
SOURCES += poinvoicelinecharge.cpp
SOURCES += poinvoicelinemap.cpp
SOURCES += poinvoicelinetax.cpp
SOURCES += poline.cpp
SOURCES += polinecharge.cpp
SOURCES += polinedoc.cpp
SOURCES += polinekitline.cpp
SOURCES += polinereturnmap.cpp
SOURCES += polinetax.cpp
SOURCES += polinewarranty.cpp
SOURCES += province.cpp
SOURCES += provincecity.cpp
SOURCES += qtyunit.cpp
SOURCES += quaraction.cpp
SOURCES += quaractionassignment.cpp
SOURCES += quarquar.cpp
SOURCES += refaccounttype.cpp
SOURCES += refadvsrytype.cpp
SOURCES += refalertstatus.cpp
SOURCES += refassmblclass.cpp
SOURCES += refbomclass.cpp
SOURCES += refborrowrate.cpp
SOURCES += refcancelwhen.cpp
SOURCES += refclaimto.cpp
SOURCES += refcostlineitemtype.cpp
SOURCES += refcreatewhen.cpp
SOURCES += refdocdisposition.cpp
SOURCES += refdocissueby.cpp
SOURCES += refengunit.cpp
SOURCES += refeventreason.cpp
SOURCES += refeventstatus.cpp
SOURCES += refeventtype.cpp
SOURCES += reffaildefer.cpp
SOURCES += reffailsev.cpp
SOURCES += reffailsevdefer.cpp
SOURCES += reffilesave.cpp
SOURCES += reffirstschedfrom.cpp
SOURCES += refflightlegstatus.cpp
SOURCES += refhazmatdef.cpp
SOURCES += refinvclass.cpp
SOURCES += refinvcond.cpp
SOURCES += reflabourrolestatus.cpp
SOURCES += reflabourroletype.cpp
SOURCES += reflabourstage.cpp
SOURCES += reflicensestatus.cpp
SOURCES += refloctype.cpp
SOURCES += reflogaction.cpp
SOURCES += refmaintprgmstatus.cpp
SOURCES += refmesurtype.cpp
SOURCES += refownby.cpp
SOURCES += refownertype.cpp
SOURCES += refpackingdef.cpp
SOURCES += refpartprovidertype.cpp
SOURCES += refpartstatus.cpp
SOURCES += refparttype.cpp
SOURCES += refpartuse.cpp
SOURCES += refpaymentterms.cpp
SOURCES += refpolinetype.cpp
SOURCES += refpotype.cpp
SOURCES += refpricetype.cpp
SOURCES += refreceivecond.cpp
SOURCES += refreceivepriority.cpp
SOURCES += refremovereason.cpp
SOURCES += refreqaction.cpp
SOURCES += refreqpriority.cpp
SOURCES += refreqtype.cpp
SOURCES += refreschedfrom.cpp
SOURCES += refschedpartstatus.cpp
SOURCES += refsegmentstatus.cpp
SOURCES += refshipmenttype.cpp
SOURCES += refstocklowactn.cpp
SOURCES += reftaskclass.cpp
SOURCES += reftaskdefstatus.cpp
SOURCES += reftaskdepaction.cpp
SOURCES += refthresholdmode.cpp
SOURCES += reftradeterms.cpp
SOURCES += refvendorstatus.cpp
SOURCES += refvendortype.cpp
SOURCES += refwarrantyevalstatus.cpp
SOURCES += refwarrantypriority.cpp
SOURCES += refwarrantystatus.cpp
SOURCES += refwarrantysubtype.cpp
SOURCES += refwarrantytype.cpp
SOURCES += refwarrantytypesubtype.cpp
SOURCES += refworkpackagetype.cpp
SOURCES += refxactiontype.cpp
SOURCES += refxfertype.cpp
SOURCES += regbody.cpp
SOURCES += regbodydoc.cpp
SOURCES += reqpart.cpp
SOURCES += rfqattachment.cpp
SOURCES += rfqheader.cpp
SOURCES += rfqline.cpp
SOURCES += rfqlinevendor.cpp
SOURCES += rfqlinevendorcharge.cpp
SOURCES += rfqlinevendortax.cpp
SOURCES += rfqvendor.cpp
SOURCES += roleapp.cpp
SOURCES += roleuser.cpp
SOURCES += schedattachment.cpp
SOURCES += schedfigure.cpp
SOURCES += schedimpact.cpp
SOURCES += schedinstpart.cpp
SOURCES += schedlabour.cpp
SOURCES += schedlabouractual.cpp
SOURCES += schedlaboursched.cpp
SOURCES += schedpanel.cpp
SOURCES += schedpart.cpp
SOURCES += schedrmvdpart.cpp
SOURCES += schedstask.cpp
SOURCES += schedstaskflags.cpp
SOURCES += schedstep.cpp
SOURCES += schedsteplabour.cpp
SOURCES += schedtaskdeadlineext.cpp
SOURCES += schedtool.cpp
SOURCES += schedwp.cpp
SOURCES += schedwpcostlineitem.cpp
SOURCES += schedwpline.cpp
SOURCES += schedwpmpc.cpp
SOURCES += schedwpsign.cpp
SOURCES += schedwpworktype.cpp
SOURCES += schedzone.cpp
SOURCES += shipsegment.cpp
SOURCES += shipshipment.cpp
SOURCES += shipshipmentline.cpp
SOURCES += shipshipmentlinedoc.cpp
SOURCES += tab.cpp
SOURCES += tagtag.cpp
SOURCES += tagtaskdefn.cpp
SOURCES += taskassemblbom.cpp
SOURCES += taskattachment.cpp
SOURCES += taskblockreqmap.cpp
SOURCES += taskcompliance.cpp
SOURCES += taskdefn.cpp
SOURCES += taskfigure.cpp
SOURCES += taskflags.cpp
SOURCES += taskimpact.cpp
SOURCES += taskjicreqmap.cpp
SOURCES += tasklabourreq.cpp
SOURCES += tasklaboursummary.cpp
SOURCES += taskmesur.cpp
SOURCES += tasknrest.cpp
SOURCES += taskoriginator.cpp
SOURCES += taskpanel.cpp
SOURCES += taskpartno.cpp
SOURCES += taskpartreq.cpp
SOURCES += taskparttransform.cpp
SOURCES += taskrefdoc.cpp
SOURCES += taskschedruleac.cpp
SOURCES += taskschedruledef.cpp
SOURCES += taskschedrulemesur.cpp
SOURCES += taskschedrulepart.cpp
SOURCES += taskstep.cpp
SOURCES += tasksubclass.cpp
SOURCES += tasktask.cpp
SOURCES += tasktaskdep.cpp
SOURCES += tasktasklog.cpp
SOURCES += tasktoolreq.cpp
SOURCES += taskzone.cpp
SOURCES += tax.cpp
SOURCES += todolist.cpp
SOURCES += todolistbutton.cpp
SOURCES += todolistrole.cpp
SOURCES += todolisttab.cpp
SOURCES += todolistuser.cpp
SOURCES += transportor.cpp
SOURCES += userapp.cpp
SOURCES += userattachment.cpp
SOURCES += userauthority.cpp
SOURCES += usereleccert.cpp
SOURCES += userlicense.cpp
SOURCES += userloginhis.cpp
SOURCES += userpoauthlvl.cpp
SOURCES += userpswdhis.cpp
SOURCES += userskill.cpp
SOURCES += vendor.cpp
SOURCES += vendoraccount.cpp
SOURCES += vendorattachment.cpp
SOURCES += warrantydefn.cpp
SOURCES += warrantydefnassmbl.cpp
SOURCES += warrantydefnattachment.cpp
SOURCES += warrantydefnpart.cpp
SOURCES += warrantydefnsubtype.cpp
SOURCES += warrantydefntask.cpp
SOURCES += warrantydefntype.cpp
SOURCES += warrantyeval.cpp
SOURCES += warrantyevallabour.cpp
SOURCES += warrantyevalpart.cpp
SOURCES += warrantyevaltask.cpp
SOURCES += warrantyinit.cpp
SOURCES += warrantyinitinv.cpp
SOURCES += warrantyinittask.cpp
SOURCES += workpackagebuilder.cpp
SOURCES += worktype.cpp
