#ifndef REFPACKINGDEF_H
#define REFPACKINGDEF_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefPackingDefObject;


class T_MODEL_EXPORT RefPackingDef : public TAbstractModel
{
public:
    RefPackingDef();
    RefPackingDef(const RefPackingDef &other);
    RefPackingDef(const RefPackingDefObject &object);
    ~RefPackingDef();

    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPackingDef &operator=(const RefPackingDef &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefPackingDef create(const QString &createdBy, const QString &updatedBy);
    static RefPackingDef create(const QVariantMap &values);
    static RefPackingDef get(const QString &createdBy, const QString &updatedBy);
    static int count();
    static QList<RefPackingDef> getAll();

private:
    QSharedDataPointer<RefPackingDefObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefPackingDef &model);
    friend QDataStream &operator>>(QDataStream &ds, RefPackingDef &model);
};

Q_DECLARE_METATYPE(RefPackingDef)
Q_DECLARE_METATYPE(QList<RefPackingDef>)

#endif // REFPACKINGDEF_H
