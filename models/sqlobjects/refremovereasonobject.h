#ifndef REFREMOVEREASONOBJECT_H
#define REFREMOVEREASONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefRemoveReasonObject : public TSqlObject, public QSharedData
{
public:
    QString remove_reason_cd;
    QString remove_reason_name_en;
    QString remove_reason_name_zh;
    QString remove_reason_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        RemoveReasonCd = 0,
        RemoveReasonNameEn,
        RemoveReasonNameZh,
        RemoveReasonDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<RemoveReasonCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_remove_reason"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString remove_reason_cd READ getremove_reason_cd WRITE setremove_reason_cd)
    T_DEFINE_PROPERTY(QString, remove_reason_cd)
    Q_PROPERTY(QString remove_reason_name_en READ getremove_reason_name_en WRITE setremove_reason_name_en)
    T_DEFINE_PROPERTY(QString, remove_reason_name_en)
    Q_PROPERTY(QString remove_reason_name_zh READ getremove_reason_name_zh WRITE setremove_reason_name_zh)
    T_DEFINE_PROPERTY(QString, remove_reason_name_zh)
    Q_PROPERTY(QString remove_reason_desc READ getremove_reason_desc WRITE setremove_reason_desc)
    T_DEFINE_PROPERTY(QString, remove_reason_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFREMOVEREASONOBJECT_H
