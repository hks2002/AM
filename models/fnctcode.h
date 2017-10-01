#ifndef FNCTCODE_H
#define FNCTCODE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FncTcodeObject;


class T_MODEL_EXPORT FncTcode : public TAbstractModel
{
public:
    FncTcode();
    FncTcode(const FncTcode &other);
    FncTcode(const FncTcodeObject &object);
    ~FncTcode();

    int tcodeId() const;
    QString tcodeCd() const;
    void setTcodeCd(const QString &tcodeCd);
    QString tcodeName() const;
    void setTcodeName(const QString &tcodeName);
    QString descDesc() const;
    void setDescDesc(const QString &descDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FncTcode &operator=(const FncTcode &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FncTcode create(const QString &tcodeCd, const QString &tcodeName, const QString &descDesc, const QString &createdBy, const QString &updatedBy);
    static FncTcode create(const QVariantMap &values);
    static FncTcode get(int tcodeId);
    static int count();
    static QList<FncTcode> getAll();

private:
    QSharedDataPointer<FncTcodeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FncTcode &model);
    friend QDataStream &operator>>(QDataStream &ds, FncTcode &model);
};

Q_DECLARE_METATYPE(FncTcode)
Q_DECLARE_METATYPE(QList<FncTcode>)

#endif // FNCTCODE_H
