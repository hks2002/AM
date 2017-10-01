#ifndef REFTASKCLASS_H
#define REFTASKCLASS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefTaskClassObject;


class T_MODEL_EXPORT RefTaskClass : public TAbstractModel
{
public:
    RefTaskClass();
    RefTaskClass(const RefTaskClass &other);
    RefTaskClass(const RefTaskClassObject &object);
    ~RefTaskClass();

    QString taskClassCd() const;
    void setTaskClassCd(const QString &taskClassCd);
    QString taskClassNameEn() const;
    void setTaskClassNameEn(const QString &taskClassNameEn);
    QString taskClassNameZh() const;
    void setTaskClassNameZh(const QString &taskClassNameZh);
    QString taskClassDesc() const;
    void setTaskClassDesc(const QString &taskClassDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefTaskClass &operator=(const RefTaskClass &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefTaskClass create(const QString &taskClassCd, const QString &taskClassNameEn, const QString &taskClassNameZh, const QString &taskClassDesc, const QString &createdBy, const QString &updatedBy);
    static RefTaskClass create(const QVariantMap &values);
    static RefTaskClass get(const QString &taskClassCd);
    static int count();
    static QList<RefTaskClass> getAll();

private:
    QSharedDataPointer<RefTaskClassObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefTaskClass &model);
    friend QDataStream &operator>>(QDataStream &ds, RefTaskClass &model);
};

Q_DECLARE_METATYPE(RefTaskClass)
Q_DECLARE_METATYPE(QList<RefTaskClass>)

#endif // REFTASKCLASS_H
