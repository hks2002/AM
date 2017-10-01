#ifndef EQPPARTNOCOMPATDEF_H
#define EQPPARTNOCOMPATDEF_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoCompatDefObject;
class EqpPartNo;
class EqpAssmbl;


class T_MODEL_EXPORT EqpPartNoCompatDef : public TAbstractModel
{
public:
    EqpPartNoCompatDef();
    EqpPartNoCompatDef(const EqpPartNoCompatDef &other);
    EqpPartNoCompatDef(const EqpPartNoCompatDefObject &object);
    ~EqpPartNoCompatDef();

    int assmblId() const;
    void setAssmblId(int assmblId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int compatPartNoId() const;
    void setCompatPartNoId(int compatPartNoId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBycompatPartNoId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpPartNoCompatDef &operator=(const EqpPartNoCompatDef &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoCompatDef create(int assmblId, int partNoId, int compatPartNoId, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoCompatDef create(const QVariantMap &values);
    static EqpPartNoCompatDef get(int assmblId, int partNoId, int compatPartNoId);
    static int count();
    static QList<EqpPartNoCompatDef> getAll();

private:
    QSharedDataPointer<EqpPartNoCompatDefObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoCompatDef &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoCompatDef &model);
};

Q_DECLARE_METATYPE(EqpPartNoCompatDef)
Q_DECLARE_METATYPE(QList<EqpPartNoCompatDef>)

#endif // EQPPARTNOCOMPATDEF_H
