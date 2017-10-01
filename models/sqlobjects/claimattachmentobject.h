#ifndef CLAIMATTACHMENTOBJECT_H
#define CLAIMATTACHMENTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ClaimAttachmentObject : public TSqlObject, public QSharedData
{
public:
    int claim_attachment_id {0};
    int claim_id {0};
    QString file_save_cd;
    QByteArray blob_data;
    QString blob_file_name;
    QString blob_file_path;
    QString blob_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ClaimAttachmentId = 0,
        ClaimId,
        FileSaveCd,
        BlobData,
        BlobFileName,
        BlobFilePath,
        BlobNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ClaimAttachmentId; }
    int autoValueIndex() const override { return ClaimAttachmentId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<FileSaveCd<<ClaimId; }
    QString tableName() const override { return QLatin1String("claim_attachment"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int claim_attachment_id READ getclaim_attachment_id WRITE setclaim_attachment_id)
    T_DEFINE_PROPERTY(int, claim_attachment_id)
    Q_PROPERTY(int claim_id READ getclaim_id WRITE setclaim_id)
    T_DEFINE_PROPERTY(int, claim_id)
    Q_PROPERTY(QString file_save_cd READ getfile_save_cd WRITE setfile_save_cd)
    T_DEFINE_PROPERTY(QString, file_save_cd)
    Q_PROPERTY(QByteArray blob_data READ getblob_data WRITE setblob_data)
    T_DEFINE_PROPERTY(QByteArray, blob_data)
    Q_PROPERTY(QString blob_file_name READ getblob_file_name WRITE setblob_file_name)
    T_DEFINE_PROPERTY(QString, blob_file_name)
    Q_PROPERTY(QString blob_file_path READ getblob_file_path WRITE setblob_file_path)
    T_DEFINE_PROPERTY(QString, blob_file_path)
    Q_PROPERTY(QString blob_note READ getblob_note WRITE setblob_note)
    T_DEFINE_PROPERTY(QString, blob_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // CLAIMATTACHMENTOBJECT_H
