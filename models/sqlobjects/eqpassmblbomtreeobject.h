#ifndef EQPASSMBLBOMTREEOBJECT_H
#define EQPASSMBLBOMTREEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpAssmblBomTreeObject : public TSqlObject, public QSharedData
{
public:
    int assmbl_bom_id {0};
    int assmbl_bom_nh_id {0};
    bool shade_bom_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblBomId = 0,
        AssmblBomNhId,
        ShadeBomBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblBomId<<AssmblBomNhId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AssmblBomNhId<<AssmblBomId; }
    QString tableName() const override { return QLatin1String("eqp_assmbl_bom_tree"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int assmbl_bom_nh_id READ getassmbl_bom_nh_id WRITE setassmbl_bom_nh_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_nh_id)
    Q_PROPERTY(bool shade_bom_bool READ getshade_bom_bool WRITE setshade_bom_bool)
    T_DEFINE_PROPERTY(bool, shade_bom_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPASSMBLBOMTREEOBJECT_H
