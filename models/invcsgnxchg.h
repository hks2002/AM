#ifndef INVCSGNXCHG_H
#define INVCSGNXCHG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvCsgnXchgObject;
class InvInv;
class PoHeader;


class T_MODEL_EXPORT InvCsgnXchg : public TAbstractModel
{
public:
    InvCsgnXchg();
    InvCsgnXchg(const InvCsgnXchg &other);
    InvCsgnXchg(const InvCsgnXchgObject &object);
    ~InvCsgnXchg();

    int invCsgnXchgId() const;
    int poId() const;
    void setPoId(int poId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int rtrnInvNoId() const;
    void setRtrnInvNoId(int rtrnInvNoId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    InvInv invInvByrtrnInvNoId() const;
    PoHeader poHeaderBypoId() const;
    InvCsgnXchg &operator=(const InvCsgnXchg &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvCsgnXchg create(int poId, int invNoId, int rtrnInvNoId, const QString &createdBy, const QString &updatedBy);
    static InvCsgnXchg create(const QVariantMap &values);
    static InvCsgnXchg get(int invCsgnXchgId);
    static int count();
    static QList<InvCsgnXchg> getAll();

private:
    QSharedDataPointer<InvCsgnXchgObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvCsgnXchg &model);
    friend QDataStream &operator>>(QDataStream &ds, InvCsgnXchg &model);
};

Q_DECLARE_METATYPE(InvCsgnXchg)
Q_DECLARE_METATYPE(QList<InvCsgnXchg>)

#endif // INVCSGNXCHG_H
