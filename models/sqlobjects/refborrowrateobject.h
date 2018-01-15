#ifndef REFBORROWRATEOBJECT_H
#define REFBORROWRATEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefBorrowRateObject : public TSqlObject, public QSharedData
{
public:
    QString borrow_rate_cd;
    QString borrow_rate_name_en;
    QString borrow_rate_name_zh;
    QString borrow_rate_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        BorrowRateCd = 0,
        BorrowRateNameEn,
        BorrowRateNameZh,
        BorrowRateDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<BorrowRateCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_borrow_rate"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString borrow_rate_cd READ getborrow_rate_cd WRITE setborrow_rate_cd)
    T_DEFINE_PROPERTY(QString, borrow_rate_cd)
    Q_PROPERTY(QString borrow_rate_name_en READ getborrow_rate_name_en WRITE setborrow_rate_name_en)
    T_DEFINE_PROPERTY(QString, borrow_rate_name_en)
    Q_PROPERTY(QString borrow_rate_name_zh READ getborrow_rate_name_zh WRITE setborrow_rate_name_zh)
    T_DEFINE_PROPERTY(QString, borrow_rate_name_zh)
    Q_PROPERTY(QString borrow_rate_desc READ getborrow_rate_desc WRITE setborrow_rate_desc)
    T_DEFINE_PROPERTY(QString, borrow_rate_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFBORROWRATEOBJECT_H
