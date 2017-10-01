#ifndef EQPASSMBLDATATYPE_H
#define EQPASSMBLDATATYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblDataTypeObject;
class DataType;
class EqpAssmbl;


class T_MODEL_EXPORT EqpAssmblDataType : public TAbstractModel
{
public:
    EqpAssmblDataType();
    EqpAssmblDataType(const EqpAssmblDataType &other);
    EqpAssmblDataType(const EqpAssmblDataTypeObject &object);
    ~EqpAssmblDataType();

    int assmblId() const;
    void setAssmblId(int assmblId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    DataType dataTypeBydataTypeId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpAssmblDataType &operator=(const EqpAssmblDataType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblDataType create(int assmblId, int dataTypeId, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblDataType create(const QVariantMap &values);
    static EqpAssmblDataType get(int assmblId, int dataTypeId);
    static int count();
    static QList<EqpAssmblDataType> getAll();

private:
    QSharedDataPointer<EqpAssmblDataTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblDataType &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblDataType &model);
};

Q_DECLARE_METATYPE(EqpAssmblDataType)
Q_DECLARE_METATYPE(QList<EqpAssmblDataType>)

#endif // EQPASSMBLDATATYPE_H
