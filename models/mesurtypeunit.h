#ifndef MESURTYPEUNIT_H
#define MESURTYPEUNIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MesurTypeUnitObject;
class MesurUnit;
class RefMesurType;


class T_MODEL_EXPORT MesurTypeUnit : public TAbstractModel
{
public:
    MesurTypeUnit();
    MesurTypeUnit(const MesurTypeUnit &other);
    MesurTypeUnit(const MesurTypeUnitObject &object);
    ~MesurTypeUnit();

    QString mesurTypeCd() const;
    void setMesurTypeCd(const QString &mesurTypeCd);
    int mesurUnitId() const;
    void setMesurUnitId(int mesurUnitId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    MesurUnit mesurUnitBymesurUnitId() const;
    RefMesurType refMesurTypeBymesurTypeCd() const;
    MesurTypeUnit &operator=(const MesurTypeUnit &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MesurTypeUnit create(const QString &mesurTypeCd, int mesurUnitId, const QString &createdBy, const QString &updatedBy);
    static MesurTypeUnit create(const QVariantMap &values);
    static MesurTypeUnit get(const QString &mesurTypeCd, int mesurUnitId);
    static int count();
    static QList<MesurTypeUnit> getAll();

private:
    QSharedDataPointer<MesurTypeUnitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MesurTypeUnit &model);
    friend QDataStream &operator>>(QDataStream &ds, MesurTypeUnit &model);
};

Q_DECLARE_METATYPE(MesurTypeUnit)
Q_DECLARE_METATYPE(QList<MesurTypeUnit>)

#endif // MESURTYPEUNIT_H
