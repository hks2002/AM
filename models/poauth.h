#ifndef POAUTH_H
#define POAUTH_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoAuthObject;
class UserApp;
class PoHeader;


class T_MODEL_EXPORT PoAuth : public TAbstractModel
{
public:
    PoAuth();
    PoAuth(const PoAuth &other);
    PoAuth(const PoAuthObject &object);
    ~PoAuth();

    int poAuthId() const;
    int poId() const;
    void setPoId(int poId);
    bool aogOverrideBool() const;
    void setAogOverrideBool(bool aogOverrideBool);
    bool revertedBool() const;
    void setRevertedBool(bool revertedBool);
    QDateTime authDt() const;
    void setAuthDt(const QDateTime &authDt);
    QString authNote() const;
    void setAuthNote(const QString &authNote);
    int authBy() const;
    void setAuthBy(int authBy);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByauthBy() const;
    PoHeader poHeaderBypoId() const;
    PoAuth &operator=(const PoAuth &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoAuth create(int poId, bool aogOverrideBool, bool revertedBool, const QDateTime &authDt, const QString &authNote, int authBy, const QString &createdBy, const QString &updatedBy);
    static PoAuth create(const QVariantMap &values);
    static PoAuth get(int poAuthId);
    static int count();
    static QList<PoAuth> getAll();

private:
    QSharedDataPointer<PoAuthObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoAuth &model);
    friend QDataStream &operator>>(QDataStream &ds, PoAuth &model);
};

Q_DECLARE_METATYPE(PoAuth)
Q_DECLARE_METATYPE(QList<PoAuth>)

#endif // POAUTH_H
