#ifndef DATATYPEOBJECT_H
#define DATATYPEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT DataTypeObject : public TSqlObject, public QSharedData
{
public:
    int data_type_id {0};
    QString data_type_cd;
    QString data_type_name_zh;
    QString data_type_name_en;
    QString eng_unit_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        DataTypeId = 0,
        DataTypeCd,
        DataTypeNameZh,
        DataTypeNameEn,
        EngUnitCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<DataTypeId; }
    int autoValueIndex() const override { return DataTypeId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<EngUnitCd; }
    QString tableName() const override { return QLatin1String("data_type"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int data_type_id READ getdata_type_id WRITE setdata_type_id)
    T_DEFINE_PROPERTY(int, data_type_id)
    Q_PROPERTY(QString data_type_cd READ getdata_type_cd WRITE setdata_type_cd)
    T_DEFINE_PROPERTY(QString, data_type_cd)
    Q_PROPERTY(QString data_type_name_zh READ getdata_type_name_zh WRITE setdata_type_name_zh)
    T_DEFINE_PROPERTY(QString, data_type_name_zh)
    Q_PROPERTY(QString data_type_name_en READ getdata_type_name_en WRITE setdata_type_name_en)
    T_DEFINE_PROPERTY(QString, data_type_name_en)
    Q_PROPERTY(QString eng_unit_cd READ geteng_unit_cd WRITE seteng_unit_cd)
    T_DEFINE_PROPERTY(QString, eng_unit_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // DATATYPEOBJECT_H
