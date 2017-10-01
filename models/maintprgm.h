#ifndef MAINTPRGM_H
#define MAINTPRGM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MaintPrgmObject;
class UserApp;
class RefMaintPrgmStatus;
class MaintPrgmDefn;


class T_MODEL_EXPORT MaintPrgm : public TAbstractModel
{
public:
    MaintPrgm();
    MaintPrgm(const MaintPrgm &other);
    MaintPrgm(const MaintPrgmObject &object);
    ~MaintPrgm();

    int maintPrgmId() const;
    int maintPrgmDefnId() const;
    void setMaintPrgmDefnId(int maintPrgmDefnId);
    QString maintPrgmCd() const;
    void setMaintPrgmCd(const QString &maintPrgmCd);
    QString maintPrgmDesc() const;
    void setMaintPrgmDesc(const QString &maintPrgmDesc);
    QString maintPrgmStatusCd() const;
    void setMaintPrgmStatusCd(const QString &maintPrgmStatusCd);
    int revisionOrd() const;
    void setRevisionOrd(int revisionOrd);
    int carrierRevisionOrd() const;
    void setCarrierRevisionOrd(int carrierRevisionOrd);
    int activedBy() const;
    void setActivedBy(int activedBy);
    QDateTime activedDt() const;
    void setActivedDt(const QDateTime &activedDt);
    QString activeDesc() const;
    void setActiveDesc(const QString &activeDesc);
    bool lockedBool() const;
    void setLockedBool(bool lockedBool);
    QDateTime lockedDt() const;
    void setLockedDt(const QDateTime &lockedDt);
    int lockedBy() const;
    void setLockedBy(int lockedBy);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBylockedBy() const;
    RefMaintPrgmStatus refMaintPrgmStatusBymaintPrgmStatusCd() const;
    MaintPrgmDefn maintPrgmDefnBymaintPrgmDefnId() const;
    MaintPrgm &operator=(const MaintPrgm &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MaintPrgm create(int maintPrgmDefnId, const QString &maintPrgmCd, const QString &maintPrgmDesc, const QString &maintPrgmStatusCd, int revisionOrd, int carrierRevisionOrd, int activedBy, const QDateTime &activedDt, const QString &activeDesc, bool lockedBool, const QDateTime &lockedDt, int lockedBy, const QString &createdBy, const QString &updatedBy);
    static MaintPrgm create(const QVariantMap &values);
    static MaintPrgm get(int maintPrgmId);
    static int count();
    static QList<MaintPrgm> getAll();

private:
    QSharedDataPointer<MaintPrgmObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MaintPrgm &model);
    friend QDataStream &operator>>(QDataStream &ds, MaintPrgm &model);
};

Q_DECLARE_METATYPE(MaintPrgm)
Q_DECLARE_METATYPE(QList<MaintPrgm>)

#endif // MAINTPRGM_H
