#ifndef MANUFACTATTACHMENT_H
#define MANUFACTATTACHMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ManufactAttachmentObject;
class RefFileSave;
class Manufact;


class T_MODEL_EXPORT ManufactAttachment : public TAbstractModel
{
public:
    ManufactAttachment();
    ManufactAttachment(const ManufactAttachment &other);
    ManufactAttachment(const ManufactAttachmentObject &object);
    ~ManufactAttachment();

    int manufactAttachmentId() const;
    int manufactId() const;
    void setManufactId(int manufactId);
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
    Manufact manufactBymanufactId() const;
    ManufactAttachment &operator=(const ManufactAttachment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ManufactAttachment create(int manufactId, const QString &fileSaveCd, const QByteArray &blobData, const QString &blobFileName, const QString &blobFilePath, const QString &blobNote, const QString &createdBy, const QString &updatedBy);
    static ManufactAttachment create(const QVariantMap &values);
    static ManufactAttachment get(int manufactAttachmentId);
    static int count();
    static QList<ManufactAttachment> getAll();

private:
    QSharedDataPointer<ManufactAttachmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ManufactAttachment &model);
    friend QDataStream &operator>>(QDataStream &ds, ManufactAttachment &model);
};

Q_DECLARE_METATYPE(ManufactAttachment)
Q_DECLARE_METATYPE(QList<ManufactAttachment>)

#endif // MANUFACTATTACHMENT_H
