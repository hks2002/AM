#ifndef PROVINCE_H
#define PROVINCE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ProvinceObject;


class T_MODEL_EXPORT Province : public TAbstractModel
{
public:
    Province();
    Province(const Province &other);
    Province(const ProvinceObject &object);
    ~Province();

    int provinceId() const;
    QString provinceNameZh() const;
    void setProvinceNameZh(const QString &provinceNameZh);
    QString provinceNameEn() const;
    void setProvinceNameEn(const QString &provinceNameEn);
    QString provinceDesc() const;
    void setProvinceDesc(const QString &provinceDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Province &operator=(const Province &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Province create(const QString &provinceNameZh, const QString &provinceNameEn, const QString &provinceDesc, const QString &createdBy, const QString &updatedBy);
    static Province create(const QVariantMap &values);
    static Province get(int provinceId);
    static int count();
    static QList<Province> getAll();

private:
    QSharedDataPointer<ProvinceObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Province &model);
    friend QDataStream &operator>>(QDataStream &ds, Province &model);
};

Q_DECLARE_METATYPE(Province)
Q_DECLARE_METATYPE(QList<Province>)

#endif // PROVINCE_H
