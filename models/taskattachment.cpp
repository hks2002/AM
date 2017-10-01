#include <TreeFrogModel>
#include "taskattachment.h"
#include "taskattachmentobject.h"
#include "reffilesave.h"
#include "tasktask.h"

TaskAttachment::TaskAttachment()
    : TAbstractModel(), d(new TaskAttachmentObject())
{
    d->task_attachment_id = 0;
    d->task_id = 0;
}

TaskAttachment::TaskAttachment(const TaskAttachment &other)
    : TAbstractModel(), d(new TaskAttachmentObject(*other.d))
{ }

TaskAttachment::TaskAttachment(const TaskAttachmentObject &object)
    : TAbstractModel(), d(new TaskAttachmentObject(object))
{ }

TaskAttachment::~TaskAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskAttachmentObject' is deleted.
}

int TaskAttachment::taskAttachmentId() const
{
    return d->task_attachment_id;
}

int TaskAttachment::taskId() const
{
    return d->task_id;
}

void TaskAttachment::setTaskId(int taskId)
{
    d->task_id = taskId;
}

QString TaskAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void TaskAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray TaskAttachment::blobData() const
{
    return d->blob_data;
}

void TaskAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString TaskAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void TaskAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString TaskAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void TaskAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString TaskAttachment::blobNote() const
{
    return d->blob_note;
}

void TaskAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime TaskAttachment::createdAt() const
{
    return d->created_at;
}

QString TaskAttachment::createdBy() const
{
    return d->created_by;
}

void TaskAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskAttachment::updatedAt() const
{
    return d->updated_at;
}

QString TaskAttachment::updatedBy() const
{
    return d->updated_by;
}

void TaskAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave TaskAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

TaskTask TaskAttachment::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskAttachment &TaskAttachment::operator=(const TaskAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskAttachment TaskAttachment::create(int taskId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    TaskAttachmentObject obj;
    obj.task_id = taskId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskAttachment();
    }
    return TaskAttachment(obj);
}

TaskAttachment TaskAttachment::create(const QVariantMap &values)
{
    TaskAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskAttachment TaskAttachment::get(int taskAttachmentId)
{
    TSqlORMapper<TaskAttachmentObject> mapper;
    return TaskAttachment(mapper.findByPrimaryKey(taskAttachmentId));
}

int TaskAttachment::count()
{
    TSqlORMapper<TaskAttachmentObject> mapper;
    return mapper.findCount();
}

QList<TaskAttachment> TaskAttachment::getAll()
{
    return tfGetModelListByCriteria<TaskAttachment, TaskAttachmentObject>();
}

TModelObject *TaskAttachment::modelData()
{
    return d.data();
}

const TModelObject *TaskAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskAttachment)
