#ifndef POATTACHMENT_H
#define POATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoAttachmentObject;
class RefFileSave;
class PoHeader;


class T_MODEL_EXPORT PoAttachment : public TAbstractModel
{
public:
    PoAttachment();
    PoAttachment(const PoAttachment &other);
    PoAttachment(const PoAttachmentObject &object);
    ~PoAttachment();

    int poAttachmentId() const;
    int poId() const;
    void setPoId(int poId);
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
    PoHeader poHeaderBypoId() const;
    PoAttachment &operator=(const PoAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoAttachment create(int poId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static PoAttachment create(const QVariantMap &values);
    static PoAttachment get(int poAttachmentId);
    static int count();
    static QList<PoAttachment> getAll();

private:
    QSharedDataPointer<PoAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, PoAttachment &model);
};

Q_DECLARE_METATYPE(PoAttachment)
Q_DECLARE_METATYPE(QList<PoAttachment>)

#endif // POATTACHMENT_H
