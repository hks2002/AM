#ifndef EQPASSMBLBOM_H
#define EQPASSMBLBOM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblBomObject;
class RefBomClass;
class EqpAssmbl;


class T_MODEL_EXPORT EqpAssmblBom : public TAbstractModel
{
public:
    EqpAssmblBom();
    EqpAssmblBom(const EqpAssmblBom &other);
    EqpAssmblBom(const EqpAssmblBomObject &object);
    ~EqpAssmblBom();

    int assmblBomId() const;
    int assmblId() const;
    void setAssmblId(int assmblId);
    QString assmblBomCd() const;
    void setAssmblBomCd(const QString &assmblBomCd);
    QString assmblBomName() const;
    void setAssmblBomName(const QString &assmblBomName);
    QString bomClassCd() const;
    void setBomClassCd(const QString &bomClassCd);
    bool mandatoryBool() const;
    void setMandatoryBool(bool mandatoryBool);
    bool softwareBool() const;
    void setSoftwareBool(bool softwareBool);
    int posCt() const;
    void setPosCt(int posCt);
    bool mustSpecialPartNo() const;
    void setMustSpecialPartNo(bool mustSpecialPartNo);
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
    RefBomClass refBomClassBybomClassCd() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpAssmblBom &operator=(const EqpAssmblBom &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblBom create(int assmblId, const QString &assmblBomCd, const QString &assmblBomName, const QString &bomClassCd, bool mandatoryBool, bool softwareBool, int posCt, bool mustSpecialPartNo, const QString &applDesc, const QString &applEffDesc, const QString &applSqlDesc, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblBom create(const QVariantMap &values);
    static EqpAssmblBom get(int assmblBomId);
    static int count();
    static QList<EqpAssmblBom> getAll();

private:
    QSharedDataPointer<EqpAssmblBomObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblBom &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblBom &model);
};

Q_DECLARE_METATYPE(EqpAssmblBom)
Q_DECLARE_METATYPE(QList<EqpAssmblBom>)

#endif // EQPASSMBLBOM_H
