#ifndef VENDORATTACHMENT_H
#define VENDORATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VendorAttachmentObject;
class RefFileSave;
class Vendor;


class T_MODEL_EXPORT VendorAttachment : public TAbstractModel
{
public:
    VendorAttachment();
    VendorAttachment(const VendorAttachment &other);
    VendorAttachment(const VendorAttachmentObject &object);
    ~VendorAttachment();

    int vendorAttachmentId() const;
    int vendorId() const;
    void setVendorId(int vendorId);
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
    Vendor vendorByvendorId() const;
    VendorAttachment &operator=(const VendorAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VendorAttachment create(int vendorId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static VendorAttachment create(const QVariantMap &values);
    static VendorAttachment get(int vendorAttachmentId);
    static int count();
    static QList<VendorAttachment> getAll();

private:
    QSharedDataPointer<VendorAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VendorAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, VendorAttachment &model);
};

Q_DECLARE_METATYPE(VendorAttachment)
Q_DECLARE_METATYPE(QList<VendorAttachment>)

#endif // VENDORATTACHMENT_H
