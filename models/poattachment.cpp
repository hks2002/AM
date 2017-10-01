#include <TreeFrogModel>
#include "poattachment.h"
#include "poattachmentobject.h"
#include "reffilesave.h"
#include "poheader.h"

PoAttachment::PoAttachment()
    : TAbstractModel(), d(new PoAttachmentObject())
{
    d->po_attachment_id = 0;
    d->po_id = 0;
}

PoAttachment::PoAttachment(const PoAttachment &other)
    : TAbstractModel(), d(new PoAttachmentObject(*other.d))
{ }

PoAttachment::PoAttachment(const PoAttachmentObject &object)
    : TAbstractModel(), d(new PoAttachmentObject(object))
{ }

PoAttachment::~PoAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'PoAttachmentObject' is deleted.
}

int PoAttachment::poAttachmentId() const
{
    return d->po_attachment_id;
}

int PoAttachment::poId() const
{
    return d->po_id;
}

void PoAttachment::setPoId(int poId)
{
    d->po_id = poId;
}

QString PoAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void PoAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray PoAttachment::blobData() const
{
    return d->blob_data;
}

void PoAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString PoAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void PoAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString PoAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void PoAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString PoAttachment::blobNote() const
{
    return d->blob_note;
}

void PoAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime PoAttachment::createdAt() const
{
    return d->created_at;
}

QString PoAttachment::createdBy() const
{
    return d->created_by;
}

void PoAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoAttachment::updatedAt() const
{
    return d->updated_at;
}

QString PoAttachment::updatedBy() const
{
    return d->updated_by;
}

void PoAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave PoAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

PoHeader PoAttachment::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

PoAttachment &PoAttachment::operator=(const PoAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoAttachment PoAttachment::create(int poId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    PoAttachmentObject obj;
    obj.po_id = poId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoAttachment();
    }
    return PoAttachment(obj);
}

PoAttachment PoAttachment::create(const QVariantMap &values)
{
    PoAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoAttachment PoAttachment::get(int poAttachmentId)
{
    TSqlORMapper<PoAttachmentObject> mapper;
    return PoAttachment(mapper.findByPrimaryKey(poAttachmentId));
}

int PoAttachment::count()
{
    TSqlORMapper<PoAttachmentObject> mapper;
    return mapper.findCount();
}

QList<PoAttachment> PoAttachment::getAll()
{
    return tfGetModelListByCriteria<PoAttachment, PoAttachmentObject>();
}

TModelObject *PoAttachment::modelData()
{
    return d.data();
}

const TModelObject *PoAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoAttachment)
