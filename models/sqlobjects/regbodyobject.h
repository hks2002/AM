#ifndef REGBODYOBJECT_H
#define REGBODYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RegBodyObject : public TSqlObject, public QSharedData
{
public:
    int reg_body_id {0};
    QString reg_body_cd;
    QString reg_body_name_zh;
    QString reg_body_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        RegBodyId = 0,
        RegBodyCd,
        RegBodyNameZh,
        RegBodyNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<RegBodyId; }
    int autoValueIndex() const override { return RegBodyId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("reg_body"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int reg_body_id READ getreg_body_id WRITE setreg_body_id)
    T_DEFINE_PROPERTY(int, reg_body_id)
    Q_PROPERTY(QString reg_body_cd READ getreg_body_cd WRITE setreg_body_cd)
    T_DEFINE_PROPERTY(QString, reg_body_cd)
    Q_PROPERTY(QString reg_body_name_zh READ getreg_body_name_zh WRITE setreg_body_name_zh)
    T_DEFINE_PROPERTY(QString, reg_body_name_zh)
    Q_PROPERTY(QString reg_body_name_en READ getreg_body_name_en WRITE setreg_body_name_en)
    T_DEFINE_PROPERTY(QString, reg_body_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REGBODYOBJECT_H
