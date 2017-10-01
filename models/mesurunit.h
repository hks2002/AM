#ifndef MESURUNIT_H
#define MESURUNIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MesurUnitObject;


class T_MODEL_EXPORT MesurUnit : public TAbstractModel
{
public:
    MesurUnit();
    MesurUnit(const MesurUnit &other);
    MesurUnit(const MesurUnitObject &object);
    ~MesurUnit();

    int mesurUnitId() const;
    QString mesurUnitCd() const;
    void setMesurUnitCd(const QString &mesurUnitCd);
    QString mesurUnitNameZh() const;
    void setMesurUnitNameZh(const QString &mesurUnitNameZh);
    QString mesurUnitNameEn() const;
    void setMesurUnitNameEn(const QString &mesurUnitNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    MesurUnit &operator=(const MesurUnit &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MesurUnit create(const QString &mesurUnitCd, const QString &mesurUnitNameZh, const QString &mesurUnitNameEn, const QString &createdBy, const QString &updatedBy);
    static MesurUnit create(const QVariantMap &values);
    static MesurUnit get(int mesurUnitId);
    static int count();
    static QList<MesurUnit> getAll();

private:
    QSharedDataPointer<MesurUnitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MesurUnit &model);
    friend QDataStream &operator>>(QDataStream &ds, MesurUnit &model);
};

Q_DECLARE_METATYPE(MesurUnit)
Q_DECLARE_METATYPE(QList<MesurUnit>)

#endif // MESURUNIT_H
