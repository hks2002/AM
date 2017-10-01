#ifndef ORGSUBORG_H
#define ORGSUBORG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OrgSuborgObject;
class Org;


class T_MODEL_EXPORT OrgSuborg : public TAbstractModel
{
public:
    OrgSuborg();
    OrgSuborg(const OrgSuborg &other);
    OrgSuborg(const OrgSuborgObject &object);
    ~OrgSuborg();

    int orgId() const;
    void setOrgId(int orgId);
    int subOrgId() const;
    void setSubOrgId(int subOrgId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Org orgBysubOrgId() const;
    OrgSuborg &operator=(const OrgSuborg &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static OrgSuborg create(int orgId, int subOrgId, const QString &createdBy, const QString &updatedBy);
    static OrgSuborg create(const QVariantMap &values);
    static OrgSuborg get(int orgId, int subOrgId);
    static int count();
    static QList<OrgSuborg> getAll();

private:
    QSharedDataPointer<OrgSuborgObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const OrgSuborg &model);
    friend QDataStream &operator>>(QDataStream &ds, OrgSuborg &model);
};

Q_DECLARE_METATYPE(OrgSuborg)
Q_DECLARE_METATYPE(QList<OrgSuborg>)

#endif // ORGSUBORG_H
