#ifndef ADVSRYATTACHMENTOBJECT_H
#define ADVSRYATTACHMENTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AdvsryAttachmentObject : public TSqlObject, public QSharedData
{
public:
    int advsry_attachment_id {0};
    int advsry_id {0};
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
        AdvsryAttachmentId = 0,
        AdvsryId,
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

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AdvsryAttachmentId; }
    int autoValueIndex() const override { return AdvsryAttachmentId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<FileSaveCd<<AdvsryId; }
    QString tableName() const override { return QLatin1String("advsry_attachment"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int advsry_attachment_id READ getadvsry_attachment_id WRITE setadvsry_attachment_id)
    T_DEFINE_PROPERTY(int, advsry_attachment_id)
    Q_PROPERTY(int advsry_id READ getadvsry_id WRITE setadvsry_id)
    T_DEFINE_PROPERTY(int, advsry_id)
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

#endif // ADVSRYATTACHMENTOBJECT_H
