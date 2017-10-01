#ifndef MANUFACTOBJECT_H
#define MANUFACTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ManufactObject : public TSqlObject, public QSharedData
{
public:
    int manufact_id {0};
    QString manufact_cd;
    QString manufact_name;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ManufactId = 0,
        ManufactCd,
        ManufactName,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ManufactId; }
    int autoValueIndex() const override { return ManufactId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("manufact"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int manufact_id READ getmanufact_id WRITE setmanufact_id)
    T_DEFINE_PROPERTY(int, manufact_id)
    Q_PROPERTY(QString manufact_cd READ getmanufact_cd WRITE setmanufact_cd)
    T_DEFINE_PROPERTY(QString, manufact_cd)
    Q_PROPERTY(QString manufact_name READ getmanufact_name WRITE setmanufact_name)
    T_DEFINE_PROPERTY(QString, manufact_name)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // MANUFACTOBJECT_H
