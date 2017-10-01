#include <TreeFrogModel>
#include "manufactattachment.h"
#include "manufactattachmentobject.h"
#include "reffilesave.h"
#include "manufact.h"

ManufactAttachment::ManufactAttachment()
    : TAbstractModel(), d(new ManufactAttachmentObject())
{
    d->manufact_attachment_id = 0;
    d->manufact_id = 0;
}

ManufactAttachment::ManufactAttachment(const ManufactAttachment &other)
    : TAbstractModel(), d(new ManufactAttachmentObject(*other.d))
{ }

ManufactAttachment::ManufactAttachment(const ManufactAttachmentObject &object)
    : TAbstractModel(), d(new ManufactAttachmentObject(object))
{ }

ManufactAttachment::~ManufactAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'ManufactAttachmentObject' is deleted.
}

int ManufactAttachment::manufactAttachmentId() const
{
    return d->manufact_attachment_id;
}

int ManufactAttachment::manufactId() const
{
    return d->manufact_id;
}

void ManufactAttachment::setManufactId(int manufactId)
{
    d->manufact_id = manufactId;
}

QString ManufactAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void ManufactAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray ManufactAttachment::blobData() const
{
    return d->blob_data;
}

void ManufactAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString ManufactAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void ManufactAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString ManufactAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void ManufactAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString ManufactAttachment::blobNote() const
{
    return d->blob_note;
}

void ManufactAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime ManufactAttachment::createdAt() const
{
    return d->created_at;
}

QString ManufactAttachment::createdBy() const
{
    return d->created_by;
}

void ManufactAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ManufactAttachment::updatedAt() const
{
    return d->updated_at;
}

QString ManufactAttachment::updatedBy() const
{
    return d->updated_by;
}

void ManufactAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave ManufactAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

Manufact ManufactAttachment::manufactBymanufactId() const
{
 return Manufact::get(d->manufact_id);
}

ManufactAttachment &ManufactAttachment::operator=(const ManufactAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ManufactAttachment ManufactAttachment::create(int manufactId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    ManufactAttachmentObject obj;
    obj.manufact_id = manufactId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ManufactAttachment();
    }
    return ManufactAttachment(obj);
}

ManufactAttachment ManufactAttachment::create(const QVariantMap &values)
{
    ManufactAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ManufactAttachment ManufactAttachment::get(int manufactAttachmentId)
{
    TSqlORMapper<ManufactAttachmentObject> mapper;
    return ManufactAttachment(mapper.findByPrimaryKey(manufactAttachmentId));
}

int ManufactAttachment::count()
{
    TSqlORMapper<ManufactAttachmentObject> mapper;
    return mapper.findCount();
}

QList<ManufactAttachment> ManufactAttachment::getAll()
{
    return tfGetModelListByCriteria<ManufactAttachment, ManufactAttachmentObject>();
}

TModelObject *ManufactAttachment::modelData()
{
    return d.data();
}

const TModelObject *ManufactAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ManufactAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ManufactAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ManufactAttachment)
