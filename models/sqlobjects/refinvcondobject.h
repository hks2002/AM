#ifndef REFINVCONDOBJECT_H
#define REFINVCONDOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefInvCondObject : public TSqlObject, public QSharedData
{
public:
    QString inv_cond_cd;
    QString inv_cond_name_en;
    QString inv_cond_name_zh;
    QString inv_cond_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvCondCd = 0,
        InvCondNameEn,
        InvCondNameZh,
        InvCondDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvCondCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_inv_cond"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString inv_cond_cd READ getinv_cond_cd WRITE setinv_cond_cd)
    T_DEFINE_PROPERTY(QString, inv_cond_cd)
    Q_PROPERTY(QString inv_cond_name_en READ getinv_cond_name_en WRITE setinv_cond_name_en)
    T_DEFINE_PROPERTY(QString, inv_cond_name_en)
    Q_PROPERTY(QString inv_cond_name_zh READ getinv_cond_name_zh WRITE setinv_cond_name_zh)
    T_DEFINE_PROPERTY(QString, inv_cond_name_zh)
    Q_PROPERTY(QString inv_cond_desc READ getinv_cond_desc WRITE setinv_cond_desc)
    T_DEFINE_PROPERTY(QString, inv_cond_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFINVCONDOBJECT_H
