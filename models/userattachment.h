#ifndef USERATTACHMENT_H
#define USERATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserAttachmentObject;
class RefFileSave;
class UserApp;


class T_MODEL_EXPORT UserAttachment : public TAbstractModel
{
public:
    UserAttachment();
    UserAttachment(const UserAttachment &other);
    UserAttachment(const UserAttachmentObject &object);
    ~UserAttachment();

    int userAttachmentId() const;
    int userId() const;
    void setUserId(int userId);
    QString fileSaveCd() const;
    void setFileSaveCd(const QString &fileSaveCd);
    QByteArray blobData() const;
    void setBlobData(const QByteArray &blobData);
    QString blobFileName() const;
    void setBlobFileName(const QString &blobFileName);
    QString blobFilePath() const;
    void setBlobFilePath(const QString &blobFilePath);
    QString blobNote() const;
    void setBlobNote(const QString &blobNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefFileSave refFileSaveByfileSaveCd() const;
    UserApp userAppByuserId() const;
    UserAttachment &operator=(const UserAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static UserAttachment create(int userId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static UserAttachment create(const QVariantMap &values);
    static UserAttachment get(int userAttachmentId);
    static int count();
    static QList<UserAttachment> getAll();

private:
    QSharedDataPointer<UserAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const UserAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, UserAttachment &model);
};

Q_DECLARE_METATYPE(UserAttachment)
Q_DECLARE_METATYPE(QList<UserAttachment>)

#endif // USERATTACHMENT_H
