#ifndef DATATYPE_H
#define DATATYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class DataTypeObject;
class RefEngUnit;


class T_MODEL_EXPORT DataType : public TAbstractModel
{
public:
    DataType();
    DataType(const DataType &other);
    DataType(const DataTypeObject &object);
    ~DataType();

    int dataTypeId() const;
    QString dataTypeCd() const;
    void setDataTypeCd(const QString &dataTypeCd);
    QString dataTypeNameZh() const;
    void setDataTypeNameZh(const QString &dataTypeNameZh);
    QString dataTypeNameEn() const;
    void setDataTypeNameEn(const QString &dataTypeNameEn);
    QString engUnitCd() const;
    void setEngUnitCd(const QString &engUnitCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefEngUnit refEngUnitByengUnitCd() const;
    DataType &operator=(const DataType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static DataType create(const QString &dataTypeCd, const QString &dataTypeNameZh, const QString &dataTypeNameEn, const QString &engUnitCd, const QString &createdBy, const QString &updatedBy);
    static DataType create(const QVariantMap &values);
    static DataType get(int dataTypeId);
    static int count();
    static QList<DataType> getAll();

private:
    QSharedDataPointer<DataTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const DataType &model);
    friend QDataStream &operator>>(QDataStream &ds, DataType &model);
};

Q_DECLARE_METATYPE(DataType)
Q_DECLARE_METATYPE(QList<DataType>)

#endif // DATATYPE_H
