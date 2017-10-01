#ifndef POINVOICEATTACHMENT_H
#define POINVOICEATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoInvoiceAttachmentObject;
class RefFileSave;
class PoInvoice;


class T_MODEL_EXPORT PoInvoiceAttachment : public TAbstractModel
{
public:
    PoInvoiceAttachment();
    PoInvoiceAttachment(const PoInvoiceAttachment &other);
    PoInvoiceAttachment(const PoInvoiceAttachmentObject &object);
    ~PoInvoiceAttachment();

    int poInvoiceAttachmentId() const;
    int poInvoiceId() const;
    void setPoInvoiceId(int poInvoiceId);
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
    PoInvoice poInvoiceBypoInvoiceId() const;
    PoInvoiceAttachment &operator=(const PoInvoiceAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoInvoiceAttachment create(int poInvoiceId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static PoInvoiceAttachment create(const QVariantMap &values);
    static PoInvoiceAttachment get(int poInvoiceAttachmentId);
    static int count();
    static QList<PoInvoiceAttachment> getAll();

private:
    QSharedDataPointer<PoInvoiceAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoInvoiceAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, PoInvoiceAttachment &model);
};

Q_DECLARE_METATYPE(PoInvoiceAttachment)
Q_DECLARE_METATYPE(QList<PoInvoiceAttachment>)

#endif // POINVOICEATTACHMENT_H
