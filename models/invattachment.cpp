#include <TreeFrogModel>
#include "invattachment.h"
#include "invattachmentobject.h"
#include "reffilesave.h"
#include "invinv.h"

InvAttachment::InvAttachment()
    : TAbstractModel(), d(new InvAttachmentObject())
{
    d->inv_attachment_id = 0;
    d->inv_no_id = 0;
}

InvAttachment::InvAttachment(const InvAttachment &other)
    : TAbstractModel(), d(new InvAttachmentObject(*other.d))
{ }

InvAttachment::InvAttachment(const InvAttachmentObject &object)
    : TAbstractModel(), d(new InvAttachmentObject(object))
{ }

InvAttachment::~InvAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'InvAttachmentObject' is deleted.
}

int InvAttachment::invAttachmentId() const
{
    return d->inv_attachment_id;
}

int InvAttachment::invNoId() const
{
    return d->inv_no_id;
}

void InvAttachment::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

QString InvAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void InvAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray InvAttachment::blobData() const
{
    return d->blob_data;
}

void InvAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString InvAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void InvAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString InvAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void InvAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString InvAttachment::blobNote() const
{
    return d->blob_note;
}

void InvAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime InvAttachment::createdAt() const
{
    return d->created_at;
}

QString InvAttachment::createdBy() const
{
    return d->created_by;
}

void InvAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvAttachment::updatedAt() const
{
    return d->updated_at;
}

QString InvAttachment::updatedBy() const
{
    return d->updated_by;
}

void InvAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave InvAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

InvInv InvAttachment::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

InvAttachment &InvAttachment::operator=(const InvAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvAttachment InvAttachment::create(int invNoId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    InvAttachmentObject obj;
    obj.inv_no_id = invNoId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvAttachment();
    }
    return InvAttachment(obj);
}

InvAttachment InvAttachment::create(const QVariantMap &values)
{
    InvAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvAttachment InvAttachment::get(int invAttachmentId)
{
    TSqlORMapper<InvAttachmentObject> mapper;
    return InvAttachment(mapper.findByPrimaryKey(invAttachmentId));
}

int InvAttachment::count()
{
    TSqlORMapper<InvAttachmentObject> mapper;
    return mapper.findCount();
}

QList<InvAttachment> InvAttachment::getAll()
{
    return tfGetModelListByCriteria<InvAttachment, InvAttachmentObject>();
}

TModelObject *InvAttachment::modelData()
{
    return d.data();
}

const TModelObject *InvAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvAttachment)
