#ifndef EQPASSMBLOBJECT_H
#define EQPASSMBLOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpAssmblObject : public TSqlObject, public QSharedData
{
public:
    int assmbl_id {0};
    QString assmbl_cd;
    QString assmbl_class_cd;
    QString assmbl_name;
    QString assmbl_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblId = 0,
        AssmblCd,
        AssmblClassCd,
        AssmblName,
        AssmblDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblId; }
    int autoValueIndex() const override { return AssmblId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AssmblClassCd; }
    QString tableName() const override { return QLatin1String("eqp_assmbl"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(QString assmbl_cd READ getassmbl_cd WRITE setassmbl_cd)
    T_DEFINE_PROPERTY(QString, assmbl_cd)
    Q_PROPERTY(QString assmbl_class_cd READ getassmbl_class_cd WRITE setassmbl_class_cd)
    T_DEFINE_PROPERTY(QString, assmbl_class_cd)
    Q_PROPERTY(QString assmbl_name READ getassmbl_name WRITE setassmbl_name)
    T_DEFINE_PROPERTY(QString, assmbl_name)
    Q_PROPERTY(QString assmbl_desc READ getassmbl_desc WRITE setassmbl_desc)
    T_DEFINE_PROPERTY(QString, assmbl_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPASSMBLOBJECT_H
