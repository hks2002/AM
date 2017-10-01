#ifndef LOC_H
#define LOC_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocObject;
class RefLocType;


class T_MODEL_EXPORT Loc : public TAbstractModel
{
public:
    Loc();
    Loc(const Loc &other);
    Loc(const LocObject &object);
    ~Loc();

    int locId() const;
    QString locCd() const;
    void setLocCd(const QString &locCd);
    QString locTypeCd() const;
    void setLocTypeCd(const QString &locTypeCd);
    QString locName() const;
    void setLocName(const QString &locName);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLocType refLocTypeBylocTypeCd() const;
    Loc &operator=(const Loc &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Loc create(const QString &locCd, const QString &locTypeCd, const QString &locName, const QString &createdBy, const QString &updatedBy);
    static Loc create(const QVariantMap &values);
    static Loc get(int locId);
    static int count();
    static QList<Loc> getAll();

private:
    QSharedDataPointer<LocObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Loc &model);
    friend QDataStream &operator>>(QDataStream &ds, Loc &model);
};

Q_DECLARE_METATYPE(Loc)
Q_DECLARE_METATYPE(QList<Loc>)

#endif // LOC_H
