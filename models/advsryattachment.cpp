#include <TreeFrogModel>
#include "advsryattachment.h"
#include "advsryattachmentobject.h"
#include "reffilesave.h"
#include "advsry.h"

AdvsryAttachment::AdvsryAttachment()
    : TAbstractModel(), d(new AdvsryAttachmentObject())
{
    d->advsry_attachment_id = 0;
    d->advsry_id = 0;
}

AdvsryAttachment::AdvsryAttachment(const AdvsryAttachment &other)
    : TAbstractModel(), d(new AdvsryAttachmentObject(*other.d))
{ }

AdvsryAttachment::AdvsryAttachment(const AdvsryAttachmentObject &object)
    : TAbstractModel(), d(new AdvsryAttachmentObject(object))
{ }

AdvsryAttachment::~AdvsryAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'AdvsryAttachmentObject' is deleted.
}

int AdvsryAttachment::advsryAttachmentId() const
{
    return d->advsry_attachment_id;
}

int AdvsryAttachment::advsryId() const
{
    return d->advsry_id;
}

void AdvsryAttachment::setAdvsryId(int advsryId)
{
    d->advsry_id = advsryId;
}

QString AdvsryAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void AdvsryAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray AdvsryAttachment::blobData() const
{
    return d->blob_data;
}

void AdvsryAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString AdvsryAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void AdvsryAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString AdvsryAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void AdvsryAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString AdvsryAttachment::blobNote() const
{
    return d->blob_note;
}

void AdvsryAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime AdvsryAttachment::createdAt() const
{
    return d->created_at;
}

QString AdvsryAttachment::createdBy() const
{
    return d->created_by;
}

void AdvsryAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AdvsryAttachment::updatedAt() const
{
    return d->updated_at;
}

QString AdvsryAttachment::updatedBy() const
{
    return d->updated_by;
}

void AdvsryAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave AdvsryAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

Advsry AdvsryAttachment::advsryByadvsryId() const
{
 return Advsry::get(d->advsry_id);
}

AdvsryAttachment &AdvsryAttachment::operator=(const AdvsryAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AdvsryAttachment AdvsryAttachment::create(int advsryId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    AdvsryAttachmentObject obj;
    obj.advsry_id = advsryId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AdvsryAttachment();
    }
    return AdvsryAttachment(obj);
}

AdvsryAttachment AdvsryAttachment::create(const QVariantMap &values)
{
    AdvsryAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AdvsryAttachment AdvsryAttachment::get(int advsryAttachmentId)
{
    TSqlORMapper<AdvsryAttachmentObject> mapper;
    return AdvsryAttachment(mapper.findByPrimaryKey(advsryAttachmentId));
}

int AdvsryAttachment::count()
{
    TSqlORMapper<AdvsryAttachmentObject> mapper;
    return mapper.findCount();
}

QList<AdvsryAttachment> AdvsryAttachment::getAll()
{
    return tfGetModelListByCriteria<AdvsryAttachment, AdvsryAttachmentObject>();
}

TModelObject *AdvsryAttachment::modelData()
{
    return d.data();
}

const TModelObject *AdvsryAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AdvsryAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AdvsryAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AdvsryAttachment)
