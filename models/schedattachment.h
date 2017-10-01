#ifndef SCHEDATTACHMENT_H
#define SCHEDATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedAttachmentObject;
class RefFileSave;
class SchedStask;


class T_MODEL_EXPORT SchedAttachment : public TAbstractModel
{
public:
    SchedAttachment();
    SchedAttachment(const SchedAttachment &other);
    SchedAttachment(const SchedAttachmentObject &object);
    ~SchedAttachment();

    int schedAttachmentId() const;
    int schedId() const;
    void setSchedId(int schedId);
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
    SchedStask schedStaskByschedId() const;
    SchedAttachment &operator=(const SchedAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedAttachment create(int schedId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static SchedAttachment create(const QVariantMap &values);
    static SchedAttachment get(int schedAttachmentId);
    static int count();
    static QList<SchedAttachment> getAll();

private:
    QSharedDataPointer<SchedAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedAttachment &model);
};

Q_DECLARE_METATYPE(SchedAttachment)
Q_DECLARE_METATYPE(QList<SchedAttachment>)

#endif // SCHEDATTACHMENT_H
