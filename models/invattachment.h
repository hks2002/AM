#ifndef INVATTACHMENT_H
#define INVATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvAttachmentObject;
class RefFileSave;
class InvInv;


class T_MODEL_EXPORT InvAttachment : public TAbstractModel
{
public:
    InvAttachment();
    InvAttachment(const InvAttachment &other);
    InvAttachment(const InvAttachmentObject &object);
    ~InvAttachment();

    int invAttachmentId() const;
    int invNoId() const;
    void setInvNoId(int invNoId);
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
    InvInv invInvByinvNoId() const;
    InvAttachment &operator=(const InvAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvAttachment create(int invNoId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static InvAttachment create(const QVariantMap &values);
    static InvAttachment get(int invAttachmentId);
    static int count();
    static QList<InvAttachment> getAll();

private:
    QSharedDataPointer<InvAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, InvAttachment &model);
};

Q_DECLARE_METATYPE(InvAttachment)
Q_DECLARE_METATYPE(QList<InvAttachment>)

#endif // INVATTACHMENT_H
