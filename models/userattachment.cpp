#include <TreeFrogModel>
#include "userattachment.h"
#include "userattachmentobject.h"
#include "reffilesave.h"
#include "userapp.h"

UserAttachment::UserAttachment()
    : TAbstractModel(), d(new UserAttachmentObject())
{
    d->user_attachment_id = 0;
    d->user_id = 0;
}

UserAttachment::UserAttachment(const UserAttachment &other)
    : TAbstractModel(), d(new UserAttachmentObject(*other.d))
{ }

UserAttachment::UserAttachment(const UserAttachmentObject &object)
    : TAbstractModel(), d(new UserAttachmentObject(object))
{ }

UserAttachment::~UserAttachment()
{
    // If the reference count becomes 0,
    // the shared data object 'UserAttachmentObject' is deleted.
}

int UserAttachment::userAttachmentId() const
{
    return d->user_attachment_id;
}

int UserAttachment::userId() const
{
    return d->user_id;
}

void UserAttachment::setUserId(int userId)
{
    d->user_id = userId;
}

QString UserAttachment::fileSaveCd() const
{
    return d->file_save_cd;
}

void UserAttachment::setFileSaveCd(const QString &fileSaveCd)
{
    d->file_save_cd = fileSaveCd;
}

QByteArray UserAttachment::blobData() const
{
    return d->blob_data;
}

void UserAttachment::setBlobData(const QByteArray &blobData)
{
    d->blob_data = blobData;
}

QString UserAttachment::blobFileName() const
{
    return d->blob_file_name;
}

void UserAttachment::setBlobFileName(const QString &blobFileName)
{
    d->blob_file_name = blobFileName;
}

QString UserAttachment::blobFilePath() const
{
    return d->blob_file_path;
}

void UserAttachment::setBlobFilePath(const QString &blobFilePath)
{
    d->blob_file_path = blobFilePath;
}

QString UserAttachment::blobNote() const
{
    return d->blob_note;
}

void UserAttachment::setBlobNote(const QString &blobNote)
{
    d->blob_note = blobNote;
}

QDateTime UserAttachment::createdAt() const
{
    return d->created_at;
}

QString UserAttachment::createdBy() const
{
    return d->created_by;
}

void UserAttachment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime UserAttachment::updatedAt() const
{
    return d->updated_at;
}

QString UserAttachment::updatedBy() const
{
    return d->updated_by;
}

void UserAttachment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFileSave UserAttachment::refFileSaveByfileSaveCd() const
{
 return RefFileSave::get(d->file_save_cd);
}

UserApp UserAttachment::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

UserAttachment &UserAttachment::operator=(const UserAttachment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserAttachment UserAttachment::create(int userId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy)
{
    UserAttachmentObject obj;
    obj.user_id = userId;
    obj.file_save_cd = fileSaveCd;
    obj.blob_data = blobData;
    obj.blob_file_name = blobFileName;
    obj.blob_file_path = blobFilePath;
    obj.blob_note = blobNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return UserAttachment();
    }
    return UserAttachment(obj);
}

UserAttachment UserAttachment::create(const QVariantMap &values)
{
    UserAttachment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserAttachment UserAttachment::get(int userAttachmentId)
{
    TSqlORMapper<UserAttachmentObject> mapper;
    return UserAttachment(mapper.findByPrimaryKey(userAttachmentId));
}

int UserAttachment::count()
{
    TSqlORMapper<UserAttachmentObject> mapper;
    return mapper.findCount();
}

QList<UserAttachment> UserAttachment::getAll()
{
    return tfGetModelListByCriteria<UserAttachment, UserAttachmentObject>();
}

TModelObject *UserAttachment::modelData()
{
    return d.data();
}

const TModelObject *UserAttachment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserAttachment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserAttachment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserAttachment)
