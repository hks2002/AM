#ifndef MAINTPRGMDEFN_H
#define MAINTPRGMDEFN_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MaintPrgmDefnObject;


class T_MODEL_EXPORT MaintPrgmDefn : public TAbstractModel
{
public:
    MaintPrgmDefn();
    MaintPrgmDefn(const MaintPrgmDefn &other);
    MaintPrgmDefn(const MaintPrgmDefnObject &object);
    ~MaintPrgmDefn();

    int maintPrgmDefnId() const;
    int lastRevisionOrd() const;
    void setLastRevisionOrd(int lastRevisionOrd);
    bool newRevisionBool() const;
    void setNewRevisionBool(bool newRevisionBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    MaintPrgmDefn &operator=(const MaintPrgmDefn &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MaintPrgmDefn create(int lastRevisionOrd, bool newRevisionBool, const QString &createdBy, const QString &updatedBy);
    static MaintPrgmDefn create(const QVariantMap &values);
    static MaintPrgmDefn get(int maintPrgmDefnId);
    static int count();
    static QList<MaintPrgmDefn> getAll();

private:
    QSharedDataPointer<MaintPrgmDefnObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MaintPrgmDefn &model);
    friend QDataStream &operator>>(QDataStream &ds, MaintPrgmDefn &model);
};

Q_DECLARE_METATYPE(MaintPrgmDefn)
Q_DECLARE_METATYPE(QList<MaintPrgmDefn>)

#endif // MAINTPRGMDEFN_H
