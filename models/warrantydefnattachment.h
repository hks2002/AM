#ifndef WARRANTYDEFNATTACHMENT_H
#define WARRANTYDEFNATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyDefnAttachmentObject;
class RefFileSave;
class WarrantyDefn;


class T_MODEL_EXPORT WarrantyDefnAttachment : public TAbstractModel
{
public:
    WarrantyDefnAttachment();
    WarrantyDefnAttachment(const WarrantyDefnAttachment &other);
    WarrantyDefnAttachment(const WarrantyDefnAttachmentObject &object);
    ~WarrantyDefnAttachment();

    int warrantyDefnAttachmentId() const;
    int warrantyDefnId() const;
    void setWarrantyDefnId(int warrantyDefnId);
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
    WarrantyDefn warrantyDefnBywarrantyDefnId() const;
    WarrantyDefnAttachment &operator=(const WarrantyDefnAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyDefnAttachment create(int warrantyDefnId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static WarrantyDefnAttachment create(const QVariantMap &values);
    static WarrantyDefnAttachment get(int warrantyDefnAttachmentId);
    static int count();
    static QList<WarrantyDefnAttachment> getAll();

private:
    QSharedDataPointer<WarrantyDefnAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyDefnAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyDefnAttachment &model);
};

Q_DECLARE_METATYPE(WarrantyDefnAttachment)
Q_DECLARE_METATYPE(QList<WarrantyDefnAttachment>)

#endif // WARRANTYDEFNATTACHMENT_H
