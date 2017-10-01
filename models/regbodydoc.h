#ifndef REGBODYDOC_H
#define REGBODYDOC_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RegBodyDocObject;


class T_MODEL_EXPORT RegBodyDoc : public TAbstractModel
{
public:
    RegBodyDoc();
    RegBodyDoc(const RegBodyDoc &other);
    RegBodyDoc(const RegBodyDocObject &object);
    ~RegBodyDoc();

    int regBodyDocId() const;
    QString regBodyDocCd() const;
    void setRegBodyDocCd(const QString &regBodyDocCd);
    QString regBodyDocNameZh() const;
    void setRegBodyDocNameZh(const QString &regBodyDocNameZh);
    QString regBodyDocNameEn() const;
    void setRegBodyDocNameEn(const QString &regBodyDocNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RegBodyDoc &operator=(const RegBodyDoc &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RegBodyDoc create(const QString &regBodyDocCd, const QString &regBodyDocNameZh, const QString &regBodyDocNameEn, const QString &createdBy, const QString &updatedBy);
    static RegBodyDoc create(const QVariantMap &values);
    static RegBodyDoc get(int regBodyDocId);
    static int count();
    static QList<RegBodyDoc> getAll();

private:
    QSharedDataPointer<RegBodyDocObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RegBodyDoc &model);
    friend QDataStream &operator>>(QDataStream &ds, RegBodyDoc &model);
};

Q_DECLARE_METATYPE(RegBodyDoc)
Q_DECLARE_METATYPE(QList<RegBodyDoc>)

#endif // REGBODYDOC_H
