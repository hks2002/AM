#ifndef RFQHEADER_H
#define RFQHEADER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RfqHeaderObject;
class UserApp;


class T_MODEL_EXPORT RfqHeader : public TAbstractModel
{
public:
    RfqHeader();
    RfqHeader(const RfqHeader &other);
    RfqHeader(const RfqHeaderObject &object);
    ~RfqHeader();

    int rfqId() const;
    QString rfqCd() const;
    void setRfqCd(const QString &rfqCd);
    int contactTo() const;
    void setContactTo(int contactTo);
    QDateTime rfqIssuedDt() const;
    void setRfqIssuedDt(const QDateTime &rfqIssuedDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBycontactTo() const;
    RfqHeader &operator=(const RfqHeader &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RfqHeader create(const QString &rfqCd, int contactTo, const QDateTime &rfqIssuedDt, const QString &createdBy, const QString &updatedBy);
    static RfqHeader create(const QVariantMap &values);
    static RfqHeader get(int rfqId);
    static int count();
    static QList<RfqHeader> getAll();

private:
    QSharedDataPointer<RfqHeaderObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RfqHeader &model);
    friend QDataStream &operator>>(QDataStream &ds, RfqHeader &model);
};

Q_DECLARE_METATYPE(RfqHeader)
Q_DECLARE_METATYPE(QList<RfqHeader>)

#endif // RFQHEADER_H
