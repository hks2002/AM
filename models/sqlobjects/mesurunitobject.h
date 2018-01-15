#ifndef MESURUNITOBJECT_H
#define MESURUNITOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MesurUnitObject : public TSqlObject, public QSharedData
{
public:
    int mesur_unit_id {0};
    QString mesur_unit_cd;
    QString mesur_unit_name_zh;
    QString mesur_unit_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MesurUnitId = 0,
        MesurUnitCd,
        MesurUnitNameZh,
        MesurUnitNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MesurUnitId; }
    int autoValueIndex() const override { return MesurUnitId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("mesur_unit"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int mesur_unit_id READ getmesur_unit_id WRITE setmesur_unit_id)
    T_DEFINE_PROPERTY(int, mesur_unit_id)
    Q_PROPERTY(QString mesur_unit_cd READ getmesur_unit_cd WRITE setmesur_unit_cd)
    T_DEFINE_PROPERTY(QString, mesur_unit_cd)
    Q_PROPERTY(QString mesur_unit_name_zh READ getmesur_unit_name_zh WRITE setmesur_unit_name_zh)
    T_DEFINE_PROPERTY(QString, mesur_unit_name_zh)
    Q_PROPERTY(QString mesur_unit_name_en READ getmesur_unit_name_en WRITE setmesur_unit_name_en)
    T_DEFINE_PROPERTY(QString, mesur_unit_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // MESURUNITOBJECT_H
