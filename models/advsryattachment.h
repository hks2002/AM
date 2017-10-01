#ifndef ADVSRYATTACHMENT_H
#define ADVSRYATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AdvsryAttachmentObject;
class RefFileSave;
class Advsry;


class T_MODEL_EXPORT AdvsryAttachment : public TAbstractModel
{
public:
    AdvsryAttachment();
    AdvsryAttachment(const AdvsryAttachment &other);
    AdvsryAttachment(const AdvsryAttachmentObject &object);
    ~AdvsryAttachment();

    int advsryAttachmentId() const;
    int advsryId() const;
    void setAdvsryId(int advsryId);
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
    Advsry advsryByadvsryId() const;
    AdvsryAttachment &operator=(const AdvsryAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AdvsryAttachment create(int advsryId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static AdvsryAttachment create(const QVariantMap &values);
    static AdvsryAttachment get(int advsryAttachmentId);
    static int count();
    static QList<AdvsryAttachment> getAll();

private:
    QSharedDataPointer<AdvsryAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AdvsryAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, AdvsryAttachment &model);
};

Q_DECLARE_METATYPE(AdvsryAttachment)
Q_DECLARE_METATYPE(QList<AdvsryAttachment>)

#endif // ADVSRYATTACHMENT_H
