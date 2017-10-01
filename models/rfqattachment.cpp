#include <TreeFrogModel>
#include "rfqattachment.h"
#include "rfqattachmentobject.h"
#include "reffilesave.h"
#include "rfqheader.h"

RfqAttachment::RfqAttachment()
    : TAbstractModel(), d(new RfqAttachmentObject())
{
    d->rfq_attachment_id = 0;
    d->rfq_id = 0;
}

RfqAttachment::RfqAttachment(const RfqAttachment &other)
    : TAbstractModel(), d(new RfqAttachmentObject(*other.d))
{ }

RfqAttachment::RfqAttachment(const RfqAttachmentObject &object)
    : TAbstractModel(), d(new RfqAttachmentObject(object))
{ }

RfqAttachment::~RfqAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'RfqAttachmentObject' is deleted.
}

int RfqAttachment::rfqAttachmentId() const
{
    return d->rfq_attachment_id;
}

int RfqAttachment::rfqId() const
{
    return d->rfq_id;
}

void RfqAttachment::setRfqId(int rfqId)
{
    d->rfq_id = rfqId;
}

QString RfqAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void RfqAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray RfqAttachment::blobData() const
{
    return d->blob_data;
}

void RfqAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString RfqAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void RfqAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString RfqAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void RfqAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString RfqAttachment::blobNote() const
{
    return d->blob_note;
}

void RfqAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime RfqAttachment::createdAt() const
{
    return d->created_at;
}

QString RfqAttachment::createdBy() const
{
    return d->created_by;
}

void RfqAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RfqAttachment::updatedAt() const
{
    return d->updated_at;
}

QString RfqAttachment::updatedBy() const
{
    return d->updated_by;
}

void RfqAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave RfqAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

RfqHeader RfqAttachment::rfqHeaderByrfqId() const
{
 return RfqHeader::get(d->rfq_id);
}

RfqAttachment &RfqAttachment::operator=(const RfqAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RfqAttachment RfqAttachment::create(int rfqId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    RfqAttachmentObject obj;
    obj.rfq_id = rfqId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RfqAttachment();
    }
    return RfqAttachment(obj);
}

RfqAttachment RfqAttachment::create(const QVariantMap &values)
{
    RfqAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RfqAttachment RfqAttachment::get(int rfqAttachmentId)
{
    TSqlORMapper<RfqAttachmentObject> mapper;
    return RfqAttachment(mapper.findByPrimaryKey(rfqAttachmentId));
}

int RfqAttachment::count()
{
    TSqlORMapper<RfqAttachmentObject> mapper;
    return mapper.findCount();
}

QList<RfqAttachment> RfqAttachment::getAll()
{
    return tfGetModelListByCriteria<RfqAttachment, RfqAttachmentObject>();
}

TModelObject *RfqAttachment::modelData()
{
    return d.data();
}

const TModelObject *RfqAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RfqAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RfqAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RfqAttachment)
