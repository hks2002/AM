#ifndef EQPASSMBLBOMTREE_H
#define EQPASSMBLBOMTREE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblBomTreeObject;
class EqpAssmblBom;


class T_MODEL_EXPORT EqpAssmblBomTree : public TAbstractModel
{
public:
    EqpAssmblBomTree();
    EqpAssmblBomTree(const EqpAssmblBomTree &other);
    EqpAssmblBomTree(const EqpAssmblBomTreeObject &object);
    ~EqpAssmblBomTree();

    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int assmblBomNhId() const;
    void setAssmblBomNhId(int assmblBomNhId);
    bool shadeBomBool() const;
    void setShadeBomBool(bool shadeBomBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpAssmblBom eqpAssmblBomByassmblBomNhId() const;
    EqpAssmblBomTree &operator=(const EqpAssmblBomTree &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblBomTree create(int assmblBomId, int assmblBomNhId, bool shadeBomBool, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblBomTree create(const QVariantMap &values);
    static EqpAssmblBomTree get(int assmblBomId, int assmblBomNhId);
    static int count();
    static QList<EqpAssmblBomTree> getAll();

private:
    QSharedDataPointer<EqpAssmblBomTreeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomTree &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblBomTree &model);
};

Q_DECLARE_METATYPE(EqpAssmblBomTree)
Q_DECLARE_METATYPE(QList<EqpAssmblBomTree>)

#endif // EQPASSMBLBOMTREE_H
