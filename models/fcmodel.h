#ifndef FCMODEL_H
#define FCMODEL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FcModelObject;
class Authority;


class T_MODEL_EXPORT FcModel : public TAbstractModel
{
public:
    FcModel();
    FcModel(const FcModel &other);
    FcModel(const FcModelObject &object);
    ~FcModel();

    int fcModelId() const;
    QString fcCd() const;
    void setFcCd(const QString &fcCd);
    bool defaultBool() const;
    void setDefaultBool(bool defaultBool);
    QString descDesc() const;
    void setDescDesc(const QString &descDesc);
    int authorityId() const;
    void setAuthorityId(int authorityId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Authority authorityByauthorityId() const;
    FcModel &operator=(const FcModel &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FcModel create(const QString &fcCd, bool defaultBool, const QString &descDesc, int authorityId, const QString &createdBy, const QString &updatedBy);
    static FcModel create(const QVariantMap &values);
    static FcModel get(int fcModelId);
    static int count();
    static QList<FcModel> getAll();

private:
    QSharedDataPointer<FcModelObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FcModel &model);
    friend QDataStream &operator>>(QDataStream &ds, FcModel &model);
};

Q_DECLARE_METATYPE(FcModel)
Q_DECLARE_METATYPE(QList<FcModel>)

#endif // FCMODEL_H
