#ifndef TRANSPORTOR_H
#define TRANSPORTOR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TransportorObject;


class T_MODEL_EXPORT Transportor : public TAbstractModel
{
public:
    Transportor();
    Transportor(const Transportor &other);
    Transportor(const TransportorObject &object);
    ~Transportor();

    int transportorId() const;
    QString transportorCd() const;
    void setTransportorCd(const QString &transportorCd);
    QString transportorNameZh() const;
    void setTransportorNameZh(const QString &transportorNameZh);
    QString transportorNameEn() const;
    void setTransportorNameEn(const QString &transportorNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Transportor &operator=(const Transportor &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Transportor create(const QString &transportorCd, const QString &transportorNameZh, const QString &transportorNameEn, const QString &createdBy, const QString &updatedBy);
    static Transportor create(const QVariantMap &values);
    static Transportor get(int transportorId);
    static int count();
    static QList<Transportor> getAll();

private:
    QSharedDataPointer<TransportorObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Transportor &model);
    friend QDataStream &operator>>(QDataStream &ds, Transportor &model);
};

Q_DECLARE_METATYPE(Transportor)
Q_DECLARE_METATYPE(QList<Transportor>)

#endif // TRANSPORTOR_H
