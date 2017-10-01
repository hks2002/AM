#include <TreeFrogModel>
#include "vendorattachment.h"
#include "vendorattachmentobject.h"
#include "reffilesave.h"
#include "vendor.h"

VendorAttachment::VendorAttachment()
    : TAbstractModel(), d(new VendorAttachmentObject())
{
    d->vendor_attachment_id = 0;
    d->vendor_id = 0;
}

VendorAttachment::VendorAttachment(const VendorAttachment &other)
    : TAbstractModel(), d(new VendorAttachmentObject(*other.d))
{ }

VendorAttachment::VendorAttachment(const VendorAttachmentObject &object)
    : TAbstractModel(), d(new VendorAttachmentObject(object))
{ }

VendorAttachment::~VendorAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'VendorAttachmentObject' is deleted.
}

int VendorAttachment::vendorAttachmentId() const
{
    return d->vendor_attachment_id;
}

int VendorAttachment::vendorId() const
{
    return d->vendor_id;
}

void VendorAttachment::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

QString VendorAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void VendorAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray VendorAttachment::blobData() const
{
    return d->blob_data;
}

void VendorAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString VendorAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void VendorAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString VendorAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void VendorAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString VendorAttachment::blobNote() const
{
    return d->blob_note;
}

void VendorAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime VendorAttachment::createdAt() const
{
    return d->created_at;
}

QString VendorAttachment::createdBy() const
{
    return d->created_by;
}

void VendorAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime VendorAttachment::updatedAt() const
{
    return d->updated_at;
}

QString VendorAttachment::updatedBy() const
{
    return d->updated_by;
}

void VendorAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave VendorAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

Vendor VendorAttachment::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

VendorAttachment &VendorAttachment::operator=(const VendorAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VendorAttachment VendorAttachment::create(int vendorId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    VendorAttachmentObject obj;
    obj.vendor_id = vendorId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return VendorAttachment();
    }
    return VendorAttachment(obj);
}

VendorAttachment VendorAttachment::create(const QVariantMap &values)
{
    VendorAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VendorAttachment VendorAttachment::get(int vendorAttachmentId)
{
    TSqlORMapper<VendorAttachmentObject> mapper;
    return VendorAttachment(mapper.findByPrimaryKey(vendorAttachmentId));
}

int VendorAttachment::count()
{
    TSqlORMapper<VendorAttachmentObject> mapper;
    return mapper.findCount();
}

QList<VendorAttachment> VendorAttachment::getAll()
{
    return tfGetModelListByCriteria<VendorAttachment, VendorAttachmentObject>();
}

TModelObject *VendorAttachment::modelData()
{
    return d.data();
}

const TModelObject *VendorAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VendorAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VendorAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VendorAttachment)
