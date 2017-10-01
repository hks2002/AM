#ifndef REFPARTUSEOBJECT_H
#define REFPARTUSEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefPartUseObject : public TSqlObject, public QSharedData
{
public:
    QString part_use_cd;
    QString part_use_name_en;
    QString part_use_name_zh;
    QString part_use_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartUseCd = 0,
        PartUseNameEn,
        PartUseNameZh,
        PartUseDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartUseCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_part_use"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString part_use_cd READ getpart_use_cd WRITE setpart_use_cd)
    T_DEFINE_PROPERTY(QString, part_use_cd)
    Q_PROPERTY(QString part_use_name_en READ getpart_use_name_en WRITE setpart_use_name_en)
    T_DEFINE_PROPERTY(QString, part_use_name_en)
    Q_PROPERTY(QString part_use_name_zh READ getpart_use_name_zh WRITE setpart_use_name_zh)
    T_DEFINE_PROPERTY(QString, part_use_name_zh)
    Q_PROPERTY(QString part_use_desc READ getpart_use_desc WRITE setpart_use_desc)
    T_DEFINE_PROPERTY(QString, part_use_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFPARTUSEOBJECT_H
