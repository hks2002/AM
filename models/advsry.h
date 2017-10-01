#ifndef ADVSRY_H
#define ADVSRY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AdvsryObject;
class RefAdvsryType;


class T_MODEL_EXPORT Advsry : public TAbstractModel
{
public:
    Advsry();
    Advsry(const Advsry &other);
    Advsry(const AdvsryObject &object);
    ~Advsry();

    int advsryId() const;
    QString advsryTypeCd() const;
    void setAdvsryTypeCd(const QString &advsryTypeCd);
    QString advsryName() const;
    void setAdvsryName(const QString &advsryName);
    QString advsryDesc() const;
    void setAdvsryDesc(const QString &advsryDesc);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime clearDt() const;
    void setClearDt(const QDateTime &clearDt);
    QString clearNote() const;
    void setClearNote(const QString &clearNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefAdvsryType refAdvsryTypeByadvsryTypeCd() const;
    Advsry &operator=(const Advsry &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Advsry create(const QString &advsryTypeCd, const QString &advsryName, const QString &advsryDesc, bool activeBool, const QDateTime &clearDt, const QString &clearNote, const QString &createdBy, const QString &updatedBy);
    static Advsry create(const QVariantMap &values);
    static Advsry get(int advsryId);
    static int count();
    static QList<Advsry> getAll();

private:
    QSharedDataPointer<AdvsryObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Advsry &model);
    friend QDataStream &operator>>(QDataStream &ds, Advsry &model);
};

Q_DECLARE_METATYPE(Advsry)
Q_DECLARE_METATYPE(QList<Advsry>)

#endif // ADVSRY_H
