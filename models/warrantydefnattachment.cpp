#include <TreeFrogModel>
#include "warrantydefnattachment.h"
#include "warrantydefnattachmentobject.h"
#include "reffilesave.h"
#include "warrantydefn.h"

WarrantyDefnAttachment::WarrantyDefnAttachment()
    : TAbstractModel(), d(new WarrantyDefnAttachmentObject())
{
    d->warranty_defn_attachment_id = 0;
    d->warranty_defn_id = 0;
}

WarrantyDefnAttachment::WarrantyDefnAttachment(const WarrantyDefnAttachment &other)
    : TAbstractModel(), d(new WarrantyDefnAttachmentObject(*other.d))
{ }

WarrantyDefnAttachment::WarrantyDefnAttachment(const WarrantyDefnAttachmentObject &object)
    : TAbstractModel(), d(new WarrantyDefnAttachmentObject(object))
{ }

WarrantyDefnAttachment::~WarrantyDefnAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyDefnAttachmentObject' is deleted.
}

int WarrantyDefnAttachment::warrantyDefnAttachmentId() const
{
    return d->warranty_defn_attachment_id;
}

int WarrantyDefnAttachment::warrantyDefnId() const
{
    return d->warranty_defn_id;
}

void WarrantyDefnAttachment::setWarrantyDefnId(int warrantyDefnId)
{
    d->warranty_defn_id = warrantyDefnId;
}

QString WarrantyDefnAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void WarrantyDefnAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray WarrantyDefnAttachment::blobData() const
{
    return d->blob_data;
}

void WarrantyDefnAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString WarrantyDefnAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void WarrantyDefnAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString WarrantyDefnAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void WarrantyDefnAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString WarrantyDefnAttachment::blobNote() const
{
    return d->blob_note;
}

void WarrantyDefnAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime WarrantyDefnAttachment::createdAt() const
{
    return d->created_at;
}

QString WarrantyDefnAttachment::createdBy() const
{
    return d->created_by;
}

void WarrantyDefnAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyDefnAttachment::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyDefnAttachment::updatedBy() const
{
    return d->updated_by;
}

void WarrantyDefnAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave WarrantyDefnAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

WarrantyDefn WarrantyDefnAttachment::warrantyDefnBywarrantyDefnId() const
{
 return WarrantyDefn::get(d->warranty_defn_id);
}

WarrantyDefnAttachment &WarrantyDefnAttachment::operator=(const WarrantyDefnAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyDefnAttachment WarrantyDefnAttachment::create(int warrantyDefnId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    WarrantyDefnAttachmentObject obj;
    obj.warranty_defn_id = warrantyDefnId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyDefnAttachment();
    }
    return WarrantyDefnAttachment(obj);
}

WarrantyDefnAttachment WarrantyDefnAttachment::create(const QVariantMap &values)
{
    WarrantyDefnAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyDefnAttachment WarrantyDefnAttachment::get(int warrantyDefnAttachmentId)
{
    TSqlORMapper<WarrantyDefnAttachmentObject> mapper;
    return WarrantyDefnAttachment(mapper.findByPrimaryKey(warrantyDefnAttachmentId));
}

int WarrantyDefnAttachment::count()
{
    TSqlORMapper<WarrantyDefnAttachmentObject> mapper;
    return mapper.findCount();
}

QList<WarrantyDefnAttachment> WarrantyDefnAttachment::getAll()
{
    return tfGetModelListByCriteria<WarrantyDefnAttachment, WarrantyDefnAttachmentObject>();
}

TModelObject *WarrantyDefnAttachment::modelData()
{
    return d.data();
}

const TModelObject *WarrantyDefnAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyDefnAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyDefnAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyDefnAttachment)
