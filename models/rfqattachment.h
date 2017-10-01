#ifndef RFQATTACHMENT_H
#define RFQATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RfqAttachmentObject;
class RefFileSave;
class RfqHeader;


class T_MODEL_EXPORT RfqAttachment : public TAbstractModel
{
public:
    RfqAttachment();
    RfqAttachment(const RfqAttachment &other);
    RfqAttachment(const RfqAttachmentObject &object);
    ~RfqAttachment();

    int rfqAttachmentId() const;
    int rfqId() const;
    void setRfqId(int rfqId);
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
    RfqHeader rfqHeaderByrfqId() const;
    RfqAttachment &operator=(const RfqAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RfqAttachment create(int rfqId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static RfqAttachment create(const QVariantMap &values);
    static RfqAttachment get(int rfqAttachmentId);
    static int count();
    static QList<RfqAttachment> getAll();

private:
    QSharedDataPointer<RfqAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RfqAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, RfqAttachment &model);
};

Q_DECLARE_METATYPE(RfqAttachment)
Q_DECLARE_METATYPE(QList<RfqAttachment>)

#endif // RFQATTACHMENT_H
