#include <TreeFrogModel>
#include "claimattachment.h"
#include "claimattachmentobject.h"
#include "reffilesave.h"
#include "claim.h"

ClaimAttachment::ClaimAttachment()
    : TAbstractModel(), d(new ClaimAttachmentObject())
{
    d->claim_attachment_id = 0;
    d->claim_id = 0;
}

ClaimAttachment::ClaimAttachment(const ClaimAttachment &other)
    : TAbstractModel(), d(new ClaimAttachmentObject(*other.d))
{ }

ClaimAttachment::ClaimAttachment(const ClaimAttachmentObject &object)
    : TAbstractModel(), d(new ClaimAttachmentObject(object))
{ }

ClaimAttachment::~ClaimAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'ClaimAttachmentObject' is deleted.
}

int ClaimAttachment::claimAttachmentId() const
{
    return d->claim_attachment_id;
}

int ClaimAttachment::claimId() const
{
    return d->claim_id;
}

void ClaimAttachment::setClaimId(int claimId)
{
    d->claim_id = claimId;
}

QString ClaimAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void ClaimAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray ClaimAttachment::blobData() const
{
    return d->blob_data;
}

void ClaimAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString ClaimAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void ClaimAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString ClaimAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void ClaimAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString ClaimAttachment::blobNote() const
{
    return d->blob_note;
}

void ClaimAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime ClaimAttachment::createdAt() const
{
    return d->created_at;
}

QString ClaimAttachment::createdBy() const
{
    return d->created_by;
}

void ClaimAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ClaimAttachment::updatedAt() const
{
    return d->updated_at;
}

QString ClaimAttachment::updatedBy() const
{
    return d->updated_by;
}

void ClaimAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave ClaimAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

Claim ClaimAttachment::claimByclaimId() const
{
 return Claim::get(d->claim_id);
}

ClaimAttachment &ClaimAttachment::operator=(const ClaimAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ClaimAttachment ClaimAttachment::create(int claimId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    ClaimAttachmentObject obj;
    obj.claim_id = claimId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ClaimAttachment();
    }
    return ClaimAttachment(obj);
}

ClaimAttachment ClaimAttachment::create(const QVariantMap &values)
{
    ClaimAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ClaimAttachment ClaimAttachment::get(int claimAttachmentId)
{
    TSqlORMapper<ClaimAttachmentObject> mapper;
    return ClaimAttachment(mapper.findByPrimaryKey(claimAttachmentId));
}

int ClaimAttachment::count()
{
    TSqlORMapper<ClaimAttachmentObject> mapper;
    return mapper.findCount();
}

QList<ClaimAttachment> ClaimAttachment::getAll()
{
    return tfGetModelListByCriteria<ClaimAttachment, ClaimAttachmentObject>();
}

TModelObject *ClaimAttachment::modelData()
{
    return d.data();
}

const TModelObject *ClaimAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ClaimAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ClaimAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ClaimAttachment)
