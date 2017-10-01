#ifndef EQPASSMBLBOMPOS_H
#define EQPASSMBLBOMPOS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblBomPosObject;
class EqpAssmblBom;


class T_MODEL_EXPORT EqpAssmblBomPos : public TAbstractModel
{
public:
    EqpAssmblBomPos();
    EqpAssmblBomPos(const EqpAssmblBomPos &other);
    EqpAssmblBomPos(const EqpAssmblBomPosObject &object);
    ~EqpAssmblBomPos();

    int assmblBomPosId() const;
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    QString eqpPosCd() const;
    void setEqpPosCd(const QString &eqpPosCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmblBomPos &operator=(const EqpAssmblBomPos &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblBomPos create(int assmblBomId, const QString &eqpPosCd, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblBomPos create(const QVariantMap &values);
    static EqpAssmblBomPos get(int assmblBomPosId);
    static int count();
    static QList<EqpAssmblBomPos> getAll();

private:
    QSharedDataPointer<EqpAssmblBomPosObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomPos &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblBomPos &model);
};

Q_DECLARE_METATYPE(EqpAssmblBomPos)
Q_DECLARE_METATYPE(QList<EqpAssmblBomPos>)

#endif // EQPASSMBLBOMPOS_H
