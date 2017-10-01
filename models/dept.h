#ifndef DEPT_H
#define DEPT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class DeptObject;


class T_MODEL_EXPORT Dept : public TAbstractModel
{
public:
    Dept();
    Dept(const Dept &other);
    Dept(const DeptObject &object);
    ~Dept();

    int deptId() const;
    QString deptCd() const;
    void setDeptCd(const QString &deptCd);
    QString deptNameZh() const;
    void setDeptNameZh(const QString &deptNameZh);
    QString deptNameEn() const;
    void setDeptNameEn(const QString &deptNameEn);
    QString deptDesc() const;
    void setDeptDesc(const QString &deptDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Dept &operator=(const Dept &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Dept create(const QString &deptCd, const QString &deptNameZh, const QString &deptNameEn, const QString &deptDesc, const QString &createdBy, const QString &updatedBy);
    static Dept create(const QVariantMap &values);
    static Dept get(int deptId);
    static int count();
    static QList<Dept> getAll();

private:
    QSharedDataPointer<DeptObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Dept &model);
    friend QDataStream &operator>>(QDataStream &ds, Dept &model);
};

Q_DECLARE_METATYPE(Dept)
Q_DECLARE_METATYPE(QList<Dept>)

#endif // DEPT_H
