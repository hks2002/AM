#ifndef EQPASSMBLBOMPART_H
#define EQPASSMBLBOMPART_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblBomPartObject;
class EqpPartNo;
class EqpAssmblBom;


class T_MODEL_EXPORT EqpAssmblBomPart : public TAbstractModel
{
public:
    EqpAssmblBomPart();
    EqpAssmblBomPart(const EqpAssmblBomPart &other);
    EqpAssmblBomPart(const EqpAssmblBomPartObject &object);
    ~EqpAssmblBomPart();

    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    bool standardBool() const;
    void setStandardBool(bool standardBool);
    bool approvedBool() const;
    void setApprovedBool(bool approvedBool);
    int interchgOrd() const;
    void setInterchgOrd(int interchgOrd);
    bool conditionalBool() const;
    void setConditionalBool(bool conditionalBool);
    QString applDesc() const;
    void setApplDesc(const QString &applDesc);
    QString applEffDesc() const;
    void setApplEffDesc(const QString &applEffDesc);
    QString applSqlDesc() const;
    void setApplSqlDesc(const QString &applSqlDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmblBomPart &operator=(const EqpAssmblBomPart &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblBomPart create(int assmblBomId, int partNoId, bool standardBool, bool approvedBool, int interchgOrd, bool conditionalBool, const QString &applDesc, const QString &applEffDesc, const QString &applSqlDesc, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblBomPart create(const QVariantMap &values);
    static EqpAssmblBomPart get(int assmblBomId, int partNoId);
    static int count();
    static QList<EqpAssmblBomPart> getAll();

private:
    QSharedDataPointer<EqpAssmblBomPartObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomPart &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblBomPart &model);
};

Q_DECLARE_METATYPE(EqpAssmblBomPart)
Q_DECLARE_METATYPE(QList<EqpAssmblBomPart>)

#endif // EQPASSMBLBOMPART_H
