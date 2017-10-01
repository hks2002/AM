#ifndef REFDOCISSUEBY_H
#define REFDOCISSUEBY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefDocIssueByObject;


class T_MODEL_EXPORT RefDocIssueBy : public TAbstractModel
{
public:
    RefDocIssueBy();
    RefDocIssueBy(const RefDocIssueBy &other);
    RefDocIssueBy(const RefDocIssueByObject &object);
    ~RefDocIssueBy();

    QString docIssueByCd() const;
    void setDocIssueByCd(const QString &docIssueByCd);
    QString docIssueByNameEn() const;
    void setDocIssueByNameEn(const QString &docIssueByNameEn);
    QString docIssueByNameZh() const;
    void setDocIssueByNameZh(const QString &docIssueByNameZh);
    QString docIssueByDesc() const;
    void setDocIssueByDesc(const QString &docIssueByDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefDocIssueBy &operator=(const RefDocIssueBy &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefDocIssueBy create(const QString &docIssueByCd, const QString &docIssueByNameEn, const QString &docIssueByNameZh, const QString &docIssueByDesc, const QString &createdBy, const QString &updatedBy);
    static RefDocIssueBy create(const QVariantMap &values);
    static RefDocIssueBy get(const QString &docIssueByCd);
    static int count();
    static QList<RefDocIssueBy> getAll();

private:
    QSharedDataPointer<RefDocIssueByObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefDocIssueBy &model);
    friend QDataStream &operator>>(QDataStream &ds, RefDocIssueBy &model);
};

Q_DECLARE_METATYPE(RefDocIssueBy)
Q_DECLARE_METATYPE(QList<RefDocIssueBy>)

#endif // REFDOCISSUEBY_H
