#ifndef REFLOGACTIONOBJECT_H
#define REFLOGACTIONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefLogActionObject : public TSqlObject, public QSharedData
{
public:
    QString log_action_cd;
    QString log_action_name_en;
    QString log_action_name_zh;
    QString log_action_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LogActionCd = 0,
        LogActionNameEn,
        LogActionNameZh,
        LogActionDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LogActionCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_log_action"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString log_action_cd READ getlog_action_cd WRITE setlog_action_cd)
    T_DEFINE_PROPERTY(QString, log_action_cd)
    Q_PROPERTY(QString log_action_name_en READ getlog_action_name_en WRITE setlog_action_name_en)
    T_DEFINE_PROPERTY(QString, log_action_name_en)
    Q_PROPERTY(QString log_action_name_zh READ getlog_action_name_zh WRITE setlog_action_name_zh)
    T_DEFINE_PROPERTY(QString, log_action_name_zh)
    Q_PROPERTY(QString log_action_desc READ getlog_action_desc WRITE setlog_action_desc)
    T_DEFINE_PROPERTY(QString, log_action_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFLOGACTIONOBJECT_H
