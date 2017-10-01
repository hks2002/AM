#ifndef INVKIT_H
#define INVKIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvKitObject;
class InvInv;


class T_MODEL_EXPORT InvKit : public TAbstractModel
{
public:
    InvKit();
    InvKit(const InvKit &other);
    InvKit(const InvKitObject &object);
    ~InvKit();

    int invNoId() const;
    void setInvNoId(int invNoId);
    bool kitCompleteBool() const;
    void setKitCompleteBool(bool kitCompleteBool);
    bool kitSealedBool() const;
    void setKitSealedBool(bool kitSealedBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    InvInv invInvByinvNoId() const;
    InvKit &operator=(const InvKit &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvKit create(int invNoId, bool kitCompleteBool, bool kitSealedBool, const QString &createdBy, const QString &updatedBy);
    static InvKit create(const QVariantMap &values);
    static InvKit get(int invNoId);
    static int count();
    static QList<InvKit> getAll();

private:
    QSharedDataPointer<InvKitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvKit &model);
    friend QDataStream &operator>>(QDataStream &ds, InvKit &model);
};

Q_DECLARE_METATYPE(InvKit)
Q_DECLARE_METATYPE(QList<InvKit>)

#endif // INVKIT_H
