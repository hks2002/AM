#ifndef REFHAZMATDEF_H
#define REFHAZMATDEF_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefHazmatDefObject;


class T_MODEL_EXPORT RefHazmatDef : public TAbstractModel
{
public:
    RefHazmatDef();
    RefHazmatDef(const RefHazmatDef &other);
    RefHazmatDef(const RefHazmatDefObject &object);
    ~RefHazmatDef();

    QString hazmatDefCd() const;
    void setHazmatDefCd(const QString &hazmatDefCd);
    QString hazmatDefNameEn() const;
    void setHazmatDefNameEn(const QString &hazmatDefNameEn);
    QString hazmatDefNameZh() const;
    void setHazmatDefNameZh(const QString &hazmatDefNameZh);
    QString hazmatDefDesc() const;
    void setHazmatDefDesc(const QString &hazmatDefDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefHazmatDef &operator=(const RefHazmatDef &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefHazmatDef create(const QString &hazmatDefCd, const QString &hazmatDefNameEn, const QString &hazmatDefNameZh, const QString &hazmatDefDesc, const QString &createdBy, const QString &updatedBy);
    static RefHazmatDef create(const QVariantMap &values);
    static RefHazmatDef get(const QString &hazmatDefCd);
    static int count();
    static QList<RefHazmatDef> getAll();

private:
    QSharedDataPointer<RefHazmatDefObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefHazmatDef &model);
    friend QDataStream &operator>>(QDataStream &ds, RefHazmatDef &model);
};

Q_DECLARE_METATYPE(RefHazmatDef)
Q_DECLARE_METATYPE(QList<RefHazmatDef>)

#endif // REFHAZMATDEF_H
