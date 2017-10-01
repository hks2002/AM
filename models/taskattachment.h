#ifndef TASKATTACHMENT_H
#define TASKATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskAttachmentObject;
class RefFileSave;
class TaskTask;


class T_MODEL_EXPORT TaskAttachment : public TAbstractModel
{
public:
    TaskAttachment();
    TaskAttachment(const TaskAttachment &other);
    TaskAttachment(const TaskAttachmentObject &object);
    ~TaskAttachment();

    int taskAttachmentId() const;
    int taskId() const;
    void setTaskId(int taskId);
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
    TaskTask taskTaskBytaskId() const;
    TaskAttachment &operator=(const TaskAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskAttachment create(int taskId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static TaskAttachment create(const QVariantMap &values);
    static TaskAttachment get(int taskAttachmentId);
    static int count();
    static QList<TaskAttachment> getAll();

private:
    QSharedDataPointer<TaskAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskAttachment &model);
};

Q_DECLARE_METATYPE(TaskAttachment)
Q_DECLARE_METATYPE(QList<TaskAttachment>)

#endif // TASKATTACHMENT_H
