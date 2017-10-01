#ifndef EQPASSMBLBOMDATATYPE_H
#define EQPASSMBLBOMDATATYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblBomDataTypeObject;
class DataType;
class EqpAssmblBom;


class T_MODEL_EXPORT EqpAssmblBomDataType : public TAbstractModel
{
public:
    EqpAssmblBomDataType();
    EqpAssmblBomDataType(const EqpAssmblBomDataType &other);
    EqpAssmblBomDataType(const EqpAssmblBomDataTypeObject &object);
    ~EqpAssmblBomDataType();

    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    DataType dataTypeBydataTypeId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmblBomDataType &operator=(const EqpAssmblBomDataType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblBomDataType create(int assmblBomId, int dataTypeId, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblBomDataType create(const QVariantMap &values);
    static EqpAssmblBomDataType get(int assmblBomId, int dataTypeId);
    static int count();
    static QList<EqpAssmblBomDataType> getAll();

private:
    QSharedDataPointer<EqpAssmblBomDataTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomDataType &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblBomDataType &model);
};

Q_DECLARE_METATYPE(EqpAssmblBomDataType)
Q_DECLARE_METATYPE(QList<EqpAssmblBomDataType>)

#endif // EQPASSMBLBOMDATATYPE_H
