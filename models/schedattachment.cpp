#include <TreeFrogModel>
#include "schedattachment.h"
#include "schedattachmentobject.h"
#include "reffilesave.h"
#include "schedstask.h"

SchedAttachment::SchedAttachment()
    : TAbstractModel(), d(new SchedAttachmentObject())
{
    d->sched_attachment_id = 0;
    d->sched_id = 0;
}

SchedAttachment::SchedAttachment(const SchedAttachment &other)
    : TAbstractModel(), d(new SchedAttachmentObject(*other.d))
{ }

SchedAttachment::SchedAttachment(const SchedAttachmentObject &object)
    : TAbstractModel(), d(new SchedAttachmentObject(object))
{ }

SchedAttachment::~SchedAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedAttachmentObject' is deleted.
}

int SchedAttachment::schedAttachmentId() const
{
    return d->sched_attachment_id;
}

int SchedAttachment::schedId() const
{
    return d->sched_id;
}

void SchedAttachment::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

QString SchedAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void SchedAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray SchedAttachment::blobData() const
{
    return d->blob_data;
}

void SchedAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString SchedAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void SchedAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString SchedAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void SchedAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString SchedAttachment::blobNote() const
{
    return d->blob_note;
}

void SchedAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime SchedAttachment::createdAt() const
{
    return d->created_at;
}

QString SchedAttachment::createdBy() const
{
    return d->created_by;
}

void SchedAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedAttachment::updatedAt() const
{
    return d->updated_at;
}

QString SchedAttachment::updatedBy() const
{
    return d->updated_by;
}

void SchedAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave SchedAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

SchedStask SchedAttachment::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedAttachment &SchedAttachment::operator=(const SchedAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedAttachment SchedAttachment::create(int schedId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    SchedAttachmentObject obj;
    obj.sched_id = schedId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedAttachment();
    }
    return SchedAttachment(obj);
}

SchedAttachment SchedAttachment::create(const QVariantMap &values)
{
    SchedAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedAttachment SchedAttachment::get(int schedAttachmentId)
{
    TSqlORMapper<SchedAttachmentObject> mapper;
    return SchedAttachment(mapper.findByPrimaryKey(schedAttachmentId));
}

int SchedAttachment::count()
{
    TSqlORMapper<SchedAttachmentObject> mapper;
    return mapper.findCount();
}

QList<SchedAttachment> SchedAttachment::getAll()
{
    return tfGetModelListByCriteria<SchedAttachment, SchedAttachmentObject>();
}

TModelObject *SchedAttachment::modelData()
{
    return d.data();
}

const TModelObject *SchedAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedAttachment)
