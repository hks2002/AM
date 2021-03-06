#ifndef EQPASSMBLDATATYPEOBJECT_H
#define EQPASSMBLDATATYPEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpAssmblDataTypeObject : public TSqlObject, public QSharedData
{
public:
    int assmbl_id {0};
    int data_type_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblId = 0,
        DataTypeId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblId<<DataTypeId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<DataTypeId<<AssmblId; }
    QString tableName() const override { return QLatin1String("eqp_assmbl_data_type"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int data_type_id READ getdata_type_id WRITE setdata_type_id)
    T_DEFINE_PROPERTY(int, data_type_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPASSMBLDATATYPEOBJECT_H
