#ifndef CLAIMATTACHMENT_H
#define CLAIMATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ClaimAttachmentObject;
class RefFileSave;
class Claim;


class T_MODEL_EXPORT ClaimAttachment : public TAbstractModel
{
public:
    ClaimAttachment();
    ClaimAttachment(const ClaimAttachment &other);
    ClaimAttachment(const ClaimAttachmentObject &object);
    ~ClaimAttachment();

    int claimAttachmentId() const;
    int claimId() const;
    void setClaimId(int claimId);
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
    Claim claimByclaimId() const;
    ClaimAttachment &operator=(const ClaimAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ClaimAttachment create(int claimId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static ClaimAttachment create(const QVariantMap &values);
    static ClaimAttachment get(int claimAttachmentId);
    static int count();
    static QList<ClaimAttachment> getAll();

private:
    QSharedDataPointer<ClaimAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ClaimAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, ClaimAttachment &model);
};

Q_DECLARE_METATYPE(ClaimAttachment)
Q_DECLARE_METATYPE(QList<ClaimAttachment>)

#endif // CLAIMATTACHMENT_H
