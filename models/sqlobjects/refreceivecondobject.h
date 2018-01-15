#ifndef REFRECEIVECONDOBJECT_H
#define REFRECEIVECONDOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefReceiveCondObject : public TSqlObject, public QSharedData
{
public:
    QString receive_cond_cd;
    QString receive_cond_name_en;
    QString receive_cond_name_zh;
    QString receive_cond_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ReceiveCondCd = 0,
        ReceiveCondNameEn,
        ReceiveCondNameZh,
        ReceiveCondDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ReceiveCondCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_receive_cond"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString receive_cond_cd READ getreceive_cond_cd WRITE setreceive_cond_cd)
    T_DEFINE_PROPERTY(QString, receive_cond_cd)
    Q_PROPERTY(QString receive_cond_name_en READ getreceive_cond_name_en WRITE setreceive_cond_name_en)
    T_DEFINE_PROPERTY(QString, receive_cond_name_en)
    Q_PROPERTY(QString receive_cond_name_zh READ getreceive_cond_name_zh WRITE setreceive_cond_name_zh)
    T_DEFINE_PROPERTY(QString, receive_cond_name_zh)
    Q_PROPERTY(QString receive_cond_desc READ getreceive_cond_desc WRITE setreceive_cond_desc)
    T_DEFINE_PROPERTY(QString, receive_cond_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFRECEIVECONDOBJECT_H
