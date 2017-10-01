#include <TreeFrogModel>
#include "invinv.h"
#include "invinvobject.h"
#include "refinvclass.h"
#include "eqpassmbl.h"
#include "eqpassmblbom.h"
#include "eqpassmblbompos.h"
#include "eqppartno.h"
#include "loc.h"
#include "authority.h"
#include "vendor.h"
#include "refinvcond.h"
#include "refreceivecond.h"
#include "ownerapp.h"
#include "refownby.h"
#include "poheader.h"
#include "poline.h"
#include "fncaccount.h"

InvInv::InvInv()
    : TAbstractModel(), d(new InvInvObject())
{
    d->inv_no_id = 0;
    d->assmbl_id = 0;
    d->assmbl_bom_id = 0;
    d->assmbl_bom_pos_id = 0;
    d->part_no_id = 0;
    d->loc_id = 0;
    d->authority_id = 0;
    d->h_inv_no_id = 0;
    d->nh_inv_no_id = 0;
    d->assmbl_inv_no_id = 0;
    d->vendor_id = 0;
    d->orig_assmbl_inv_no_id = 0;
    d->owner_id = 0;
    d->bin_qt = 0;
    d->reserve_bin_qt = 0;
    d->po_id = 0;
    d->po_line_id = 0;
    d->account_id = 0;
}

InvInv::InvInv(const InvInv &other)
    : TAbstractModel(), d(new InvInvObject(*other.d))
{ }

InvInv::InvInv(const InvInvObject &object)
    : TAbstractModel(), d(new InvInvObject(object))
{ }

InvInv::~InvInv()
{
    // If the reference count becomes 0,
    // the shared data object 'InvInvObject' is deleted.
}

int InvInv::invNoId() const
{
    return d->inv_no_id;
}

QString InvInv::invClassCd() const
{
    return d->inv_class_cd;
}

void InvInv::setInvClassCd(const QString &invClassCd)
{
    d->inv_class_cd = invClassCd;
}

int InvInv::assmblId() const
{
    return d->assmbl_id;
}

void InvInv::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int InvInv::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void InvInv::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int InvInv::assmblBomPosId() const
{
    return d->assmbl_bom_pos_id;
}

void InvInv::setAssmblBomPosId(int assmblBomPosId)
{
    d->assmbl_bom_pos_id = assmblBomPosId;
}

QString InvInv::configPosDesc() const
{
    return d->config_pos_desc;
}

void InvInv::setConfigPosDesc(const QString &configPosDesc)
{
    d->config_pos_desc = configPosDesc;
}

int InvInv::partNoId() const
{
    return d->part_no_id;
}

void InvInv::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString InvInv::serialNoOem() const
{
    return d->serial_no_oem;
}

void InvInv::setSerialNoOem(const QString &serialNoOem)
{
    d->serial_no_oem = serialNoOem;
}

QString InvInv::batchNoOem() const
{
    return d->batch_no_oem;
}

void InvInv::setBatchNoOem(const QString &batchNoOem)
{
    d->batch_no_oem = batchNoOem;
}

QString InvInv::icnNoDesc() const
{
    return d->icn_no_desc;
}

void InvInv::setIcnNoDesc(const QString &icnNoDesc)
{
    d->icn_no_desc = icnNoDesc;
}

QString InvInv::applEffCd() const
{
    return d->appl_eff_cd;
}

void InvInv::setApplEffCd(const QString &applEffCd)
{
    d->appl_eff_cd = applEffCd;
}

QString InvInv::invNoDesc() const
{
    return d->inv_no_desc;
}

void InvInv::setInvNoDesc(const QString &invNoDesc)
{
    d->inv_no_desc = invNoDesc;
}

QString InvInv::lotOemTag() const
{
    return d->lot_oem_tag;
}

void InvInv::setLotOemTag(const QString &lotOemTag)
{
    d->lot_oem_tag = lotOemTag;
}

QString InvInv::modStatusNote() const
{
    return d->mod_status_note;
}

void InvInv::setModStatusNote(const QString &modStatusNote)
{
    d->mod_status_note = modStatusNote;
}

QString InvInv::barcodeDesc() const
{
    return d->barcode_desc;
}

void InvInv::setBarcodeDesc(const QString &barcodeDesc)
{
    d->barcode_desc = barcodeDesc;
}

int InvInv::locId() const
{
    return d->loc_id;
}

void InvInv::setLocId(int locId)
{
    d->loc_id = locId;
}

int InvInv::authorityId() const
{
    return d->authority_id;
}

void InvInv::setAuthorityId(int authorityId)
{
    d->authority_id = authorityId;
}

int InvInv::hInvNoId() const
{
    return d->h_inv_no_id;
}

void InvInv::setHInvNoId(int hInvNoId)
{
    d->h_inv_no_id = hInvNoId;
}

int InvInv::nhInvNoId() const
{
    return d->nh_inv_no_id;
}

void InvInv::setNhInvNoId(int nhInvNoId)
{
    d->nh_inv_no_id = nhInvNoId;
}

int InvInv::assmblInvNoId() const
{
    return d->assmbl_inv_no_id;
}

void InvInv::setAssmblInvNoId(int assmblInvNoId)
{
    d->assmbl_inv_no_id = assmblInvNoId;
}

int InvInv::vendorId() const
{
    return d->vendor_id;
}

void InvInv::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

QString InvInv::invCondCd() const
{
    return d->inv_cond_cd;
}

void InvInv::setInvCondCd(const QString &invCondCd)
{
    d->inv_cond_cd = invCondCd;
}

QString InvInv::receiveCondCd() const
{
    return d->receive_cond_cd;
}

void InvInv::setReceiveCondCd(const QString &receiveCondCd)
{
    d->receive_cond_cd = receiveCondCd;
}

QString InvInv::origAssmblCd() const
{
    return d->orig_assmbl_cd;
}

void InvInv::setOrigAssmblCd(const QString &origAssmblCd)
{
    d->orig_assmbl_cd = origAssmblCd;
}

int InvInv::origAssmblInvNoId() const
{
    return d->orig_assmbl_inv_no_id;
}

void InvInv::setOrigAssmblInvNoId(int origAssmblInvNoId)
{
    d->orig_assmbl_inv_no_id = origAssmblInvNoId;
}

QDateTime InvInv::manufactDt() const
{
    return d->manufact_dt;
}

void InvInv::setManufactDt(const QDateTime &manufactDt)
{
    d->manufact_dt = manufactDt;
}

QDateTime InvInv::receivedDt() const
{
    return d->received_dt;
}

void InvInv::setReceivedDt(const QDateTime &receivedDt)
{
    d->received_dt = receivedDt;
}

QDateTime InvInv::installDt() const
{
    return d->install_dt;
}

void InvInv::setInstallDt(const QDateTime &installDt)
{
    d->install_dt = installDt;
}

int InvInv::ownerId() const
{
    return d->owner_id;
}

void InvInv::setOwnerId(int ownerId)
{
    d->owner_id = ownerId;
}

QString InvInv::ownByCd() const
{
    return d->own_by_cd;
}

void InvInv::setOwnByCd(const QString &ownByCd)
{
    d->own_by_cd = ownByCd;
}

bool InvInv::notFoundBool() const
{
    return d->not_found_bool;
}

void InvInv::setNotFoundBool(bool notFoundBool)
{
    d->not_found_bool = notFoundBool;
}

bool InvInv::completeBool() const
{
    return d->complete_bool;
}

void InvInv::setCompleteBool(bool completeBool)
{
    d->complete_bool = completeBool;
}

bool InvInv::issuedBool() const
{
    return d->issued_bool;
}

void InvInv::setIssuedBool(bool issuedBool)
{
    d->issued_bool = issuedBool;
}

bool InvInv::lockedBool() const
{
    return d->locked_bool;
}

void InvInv::setLockedBool(bool lockedBool)
{
    d->locked_bool = lockedBool;
}

bool InvInv::pickedBool() const
{
    return d->picked_bool;
}

void InvInv::setPickedBool(bool pickedBool)
{
    d->picked_bool = pickedBool;
}

bool InvInv::usedBool() const
{
    return d->used_bool;
}

void InvInv::setUsedBool(bool usedBool)
{
    d->used_bool = usedBool;
}

QString InvInv::shelfExpiryDt() const
{
    return d->shelf_expiry_dt;
}

void InvInv::setShelfExpiryDt(const QString &shelfExpiryDt)
{
    d->shelf_expiry_dt = shelfExpiryDt;
}

QString InvInv::note() const
{
    return d->note;
}

void InvInv::setNote(const QString &note)
{
    d->note = note;
}

int InvInv::binQt() const
{
    return d->bin_qt;
}

void InvInv::setBinQt(int binQt)
{
    d->bin_qt = binQt;
}

int InvInv::reserveBinQt() const
{
    return d->reserve_bin_qt;
}

void InvInv::setReserveBinQt(int reserveBinQt)
{
    d->reserve_bin_qt = reserveBinQt;
}

bool InvInv::reservedBool() const
{
    return d->reserved_bool;
}

void InvInv::setReservedBool(bool reservedBool)
{
    d->reserved_bool = reservedBool;
}

int InvInv::poId() const
{
    return d->po_id;
}

void InvInv::setPoId(int poId)
{
    d->po_id = poId;
}

int InvInv::poLineId() const
{
    return d->po_line_id;
}

void InvInv::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int InvInv::accountId() const
{
    return d->account_id;
}

void InvInv::setAccountId(int accountId)
{
    d->account_id = accountId;
}

QString InvInv::releaseNumber() const
{
    return d->release_number;
}

void InvInv::setReleaseNumber(const QString &releaseNumber)
{
    d->release_number = releaseNumber;
}

QString InvInv::releaseRemarksDesc() const
{
    return d->release_remarks_desc;
}

void InvInv::setReleaseRemarksDesc(const QString &releaseRemarksDesc)
{
    d->release_remarks_desc = releaseRemarksDesc;
}

QDateTime InvInv::releaseDt() const
{
    return d->release_dt;
}

void InvInv::setReleaseDt(const QDateTime &releaseDt)
{
    d->release_dt = releaseDt;
}

QDateTime InvInv::createdAt() const
{
    return d->created_at;
}

QString InvInv::createdBy() const
{
    return d->created_by;
}

void InvInv::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvInv::updatedAt() const
{
    return d->updated_at;
}

QString InvInv::updatedBy() const
{
    return d->updated_by;
}

void InvInv::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefInvClass InvInv::refInvClassByinvClassCd() const
{
 return RefInvClass::get(d->inv_class_cd);
}

EqpAssmbl InvInv::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpAssmblBom InvInv::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmblBomPos InvInv::eqpAssmblBomPosByassmblBomPosId() const
{
 return EqpAssmblBomPos::get(d->assmbl_bom_pos_id);
}

EqpPartNo InvInv::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

Loc InvInv::locBylocId() const
{
 return Loc::get(d->loc_id);
}

Authority InvInv::authorityByauthorityId() const
{
 return Authority::get(d->authority_id);
}

Vendor InvInv::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

RefInvCond InvInv::refInvCondByinvCondCd() const
{
 return RefInvCond::get(d->inv_cond_cd);
}

RefReceiveCond InvInv::refReceiveCondByreceiveCondCd() const
{
 return RefReceiveCond::get(d->receive_cond_cd);
}

OwnerApp InvInv::ownerAppByownerId() const
{
 return OwnerApp::get(d->owner_id);
}

RefOwnBy InvInv::refOwnByByownByCd() const
{
 return RefOwnBy::get(d->own_by_cd);
}

PoHeader InvInv::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

PoLine InvInv::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

FncAccount InvInv::fncAccountByaccountId() const
{
 return FncAccount::get(d->account_id);
}

InvInv &InvInv::operator=(const InvInv &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvInv InvInv::create(const QString &invClassCd, int assmblId, int assmblBomId, int assmblBomPosId, const QString &configPosDesc, int partNoId, const QString &serialNoOem, const QString &batchNoOem, const QString &icnNoDesc, const QString &applEffCd, const QString &invNoDesc, const QString &lotOemTag, const QString &modStatusNote, const QString &barcodeDesc, int locId, int authorityId, int hInvNoId, int nhInvNoId, int assmblInvNoId, int vendorId, const QString &invCondCd, const QString &receiveCondCd, const QString &origAssmblCd, int origAssmblInvNoId, const QDateTime &manufactDt, const QDateTime &receivedDt, const QDateTime &installDt, int ownerId, const QString &ownByCd, bool notFoundBool, bool completeBool, bool issuedBool, bool lockedBool, bool pickedBool, bool usedBool, const QString &shelfExpiryDt, const QString &note, int binQt, int reserveBinQt, bool reservedBool, int poId, int poLineId, int accountId, const QString &releaseNumber, const QString &releaseRemarksDesc, const QDateTime &releaseDt, const QString &createdBy, const QString &updatedBy)
{
    InvInvObject obj;
    obj.inv_class_cd = invClassCd;
    obj.assmbl_id = assmblId;
    obj.assmbl_bom_id = assmblBomId;
    obj.assmbl_bom_pos_id = assmblBomPosId;
    obj.config_pos_desc = configPosDesc;
    obj.part_no_id = partNoId;
    obj.serial_no_oem = serialNoOem;
    obj.batch_no_oem = batchNoOem;
    obj.icn_no_desc = icnNoDesc;
    obj.appl_eff_cd = applEffCd;
    obj.inv_no_desc = invNoDesc;
    obj.lot_oem_tag = lotOemTag;
    obj.mod_status_note = modStatusNote;
    obj.barcode_desc = barcodeDesc;
    obj.loc_id = locId;
    obj.authority_id = authorityId;
    obj.h_inv_no_id = hInvNoId;
    obj.nh_inv_no_id = nhInvNoId;
    obj.assmbl_inv_no_id = assmblInvNoId;
    obj.vendor_id = vendorId;
    obj.inv_cond_cd = invCondCd;
    obj.receive_cond_cd = receiveCondCd;
    obj.orig_assmbl_cd = origAssmblCd;
    obj.orig_assmbl_inv_no_id = origAssmblInvNoId;
    obj.manufact_dt = manufactDt;
    obj.received_dt = receivedDt;
    obj.install_dt = installDt;
    obj.owner_id = ownerId;
    obj.own_by_cd = ownByCd;
    obj.not_found_bool = notFoundBool;
    obj.complete_bool = completeBool;
    obj.issued_bool = issuedBool;
    obj.locked_bool = lockedBool;
    obj.picked_bool = pickedBool;
    obj.used_bool = usedBool;
    obj.shelf_expiry_dt = shelfExpiryDt;
    obj.note = note;
    obj.bin_qt = binQt;
    obj.reserve_bin_qt = reserveBinQt;
    obj.reserved_bool = reservedBool;
    obj.po_id = poId;
    obj.po_line_id = poLineId;
    obj.account_id = accountId;
    obj.release_number = releaseNumber;
    obj.release_remarks_desc = releaseRemarksDesc;
    obj.release_dt = releaseDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvInv();
    }
    return InvInv(obj);
}

InvInv InvInv::create(const QVariantMap &values)
{
    InvInv model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvInv InvInv::get(int invNoId)
{
    TSqlORMapper<InvInvObject> mapper;
    return InvInv(mapper.findByPrimaryKey(invNoId));
}

int InvInv::count()
{
    TSqlORMapper<InvInvObject> mapper;
    return mapper.findCount();
}

QList<InvInv> InvInv::getAll()
{
    return tfGetModelListByCriteria<InvInv, InvInvObject>();
}

TModelObject *InvInv::modelData()
{
    return d.data();
}

const TModelObject *InvInv::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvInv &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvInv &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvInv)
