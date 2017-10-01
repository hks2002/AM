#ifndef REFFILESAVEOBJECT_H
#define REFFILESAVEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefFileSaveObject : public TSqlObject, public QSharedData
{
public:
    QString file_save_cd;
    QString file_save_name_zh;
    QString file_save_name_en;
    QString file_save_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FileSaveCd = 0,
        FileSaveNameZh,
        FileSaveNameEn,
        FileSaveDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FileSaveCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_file_save"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString file_save_cd READ getfile_save_cd WRITE setfile_save_cd)
    T_DEFINE_PROPERTY(QString, file_save_cd)
    Q_PROPERTY(QString file_save_name_zh READ getfile_save_name_zh WRITE setfile_save_name_zh)
    T_DEFINE_PROPERTY(QString, file_save_name_zh)
    Q_PROPERTY(QString file_save_name_en READ getfile_save_name_en WRITE setfile_save_name_en)
    T_DEFINE_PROPERTY(QString, file_save_name_en)
    Q_PROPERTY(QString file_save_desc READ getfile_save_desc WRITE setfile_save_desc)
    T_DEFINE_PROPERTY(QString, file_save_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFFILESAVEOBJECT_H
