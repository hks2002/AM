#ifndef REFENGUNIT_H
#define REFENGUNIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefEngUnitObject;


class T_MODEL_EXPORT RefEngUnit : public TAbstractModel
{
public:
    RefEngUnit();
    RefEngUnit(const RefEngUnit &other);
    RefEngUnit(const RefEngUnitObject &object);
    ~RefEngUnit();

    QString engUnitCd() const;
    void setEngUnitCd(const QString &engUnitCd);
    QString engUnitNameEn() const;
    void setEngUnitNameEn(const QString &engUnitNameEn);
    QString engUnitNameZh() const;
    void setEngUnitNameZh(const QString &engUnitNameZh);
    QString engUnitDesc() const;
    void setEngUnitDesc(const QString &engUnitDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefEngUnit &operator=(const RefEngUnit &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefEngUnit create(const QString &engUnitCd, const QString &engUnitNameEn, const QString &engUnitNameZh, const QString &engUnitDesc, const QString &createdBy, const QString &updatedBy);
    static RefEngUnit create(const QVariantMap &values);
    static RefEngUnit get(const QString &engUnitCd);
    static int count();
    static QList<RefEngUnit> getAll();

private:
    QSharedDataPointer<RefEngUnitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefEngUnit &model);
    friend QDataStream &operator>>(QDataStream &ds, RefEngUnit &model);
};

Q_DECLARE_METATYPE(RefEngUnit)
Q_DECLARE_METATYPE(QList<RefEngUnit>)

#endif // REFENGUNIT_H
