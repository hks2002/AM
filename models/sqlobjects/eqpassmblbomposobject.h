#ifndef EQPASSMBLBOMPOSOBJECT_H
#define EQPASSMBLBOMPOSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpAssmblBomPosObject : public TSqlObject, public QSharedData
{
public:
    int assmbl_bom_pos_id {0};
    int assmbl_bom_id {0};
    QString eqp_pos_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblBomPosId = 0,
        AssmblBomId,
        EqpPosCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblBomPosId; }
    int autoValueIndex() const override { return AssmblBomPosId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AssmblBomId; }
    QString tableName() const override { return QLatin1String("eqp_assmbl_bom_pos"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int assmbl_bom_pos_id READ getassmbl_bom_pos_id WRITE setassmbl_bom_pos_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_pos_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(QString eqp_pos_cd READ geteqp_pos_cd WRITE seteqp_pos_cd)
    T_DEFINE_PROPERTY(QString, eqp_pos_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPASSMBLBOMPOSOBJECT_H
