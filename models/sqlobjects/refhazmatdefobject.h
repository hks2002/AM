#ifndef REFHAZMATDEFOBJECT_H
#define REFHAZMATDEFOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefHazmatDefObject : public TSqlObject, public QSharedData
{
public:
    QString hazmat_def_cd;
    QString hazmat_def_name_en;
    QString hazmat_def_name_zh;
    QString hazmat_def_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        HazmatDefCd = 0,
        HazmatDefNameEn,
        HazmatDefNameZh,
        HazmatDefDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<HazmatDefCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_hazmat_def"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString hazmat_def_cd READ gethazmat_def_cd WRITE sethazmat_def_cd)
    T_DEFINE_PROPERTY(QString, hazmat_def_cd)
    Q_PROPERTY(QString hazmat_def_name_en READ gethazmat_def_name_en WRITE sethazmat_def_name_en)
    T_DEFINE_PROPERTY(QString, hazmat_def_name_en)
    Q_PROPERTY(QString hazmat_def_name_zh READ gethazmat_def_name_zh WRITE sethazmat_def_name_zh)
    T_DEFINE_PROPERTY(QString, hazmat_def_name_zh)
    Q_PROPERTY(QString hazmat_def_desc READ gethazmat_def_desc WRITE sethazmat_def_desc)
    T_DEFINE_PROPERTY(QString, hazmat_def_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFHAZMATDEFOBJECT_H
