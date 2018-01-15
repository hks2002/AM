#ifndef REFCANCELWHENOBJECT_H
#define REFCANCELWHENOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefCancelWhenObject : public TSqlObject, public QSharedData
{
public:
    QString cancel_when_cd;
    QString cancel_when_name_en;
    QString cancel_when_name_zh;
    QString cancel_when_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        CancelWhenCd = 0,
        CancelWhenNameEn,
        CancelWhenNameZh,
        CancelWhenDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<CancelWhenCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_cancel_when"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString cancel_when_cd READ getcancel_when_cd WRITE setcancel_when_cd)
    T_DEFINE_PROPERTY(QString, cancel_when_cd)
    Q_PROPERTY(QString cancel_when_name_en READ getcancel_when_name_en WRITE setcancel_when_name_en)
    T_DEFINE_PROPERTY(QString, cancel_when_name_en)
    Q_PROPERTY(QString cancel_when_name_zh READ getcancel_when_name_zh WRITE setcancel_when_name_zh)
    T_DEFINE_PROPERTY(QString, cancel_when_name_zh)
    Q_PROPERTY(QString cancel_when_desc READ getcancel_when_desc WRITE setcancel_when_desc)
    T_DEFINE_PROPERTY(QString, cancel_when_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFCANCELWHENOBJECT_H
