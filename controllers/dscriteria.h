#ifndef DSCRITERIA_H
#define DSCRITERIA_H

#include <QVariant>
#include <TGlobal>

//logic copyed from TCriteria, please reference TCriteria's api when use
//property--> fieldName,fieldType

class T_CONTROLLER_EXPORT DSCriteria
{
public:
    DSCriteria();
    DSCriteria(const DSCriteria &other);

    DSCriteria(const QString &fieldName, QVariant::Type fieldType, const QVariant &val);
    DSCriteria(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op);
    DSCriteria(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val);
    DSCriteria(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val1, const QVariant &val2);
    DSCriteria(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op1, TSql::ComparisonOperator op2, const QVariant &val);
    ~DSCriteria() { }

    DSCriteria &add(const QString &fieldName, QVariant::Type fieldType, const QVariant &val);
    DSCriteria &add(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op);
    DSCriteria &add(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val);
    DSCriteria &add(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val1, const QVariant &val2);
    DSCriteria &add(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op1, TSql::ComparisonOperator op2, const QVariant &val);
    DSCriteria &add(const DSCriteria &criteria);
    DSCriteria &addOr(const QString &fieldName, QVariant::Type fieldType, const QVariant &val);
    DSCriteria &addOr(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op);
    DSCriteria &addOr(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val);
    DSCriteria &addOr(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val1, const QVariant &val2);
    DSCriteria &addOr(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op1, TSql::ComparisonOperator op2, const QVariant &val);
    DSCriteria &addOr(const DSCriteria &criteria);

    bool isEmpty() const;
    void clear();

    const DSCriteria operator&&(const DSCriteria &criteria) const;
    const DSCriteria operator||(const DSCriteria &criteria) const;
    const DSCriteria operator!() const;
    DSCriteria &operator=(const DSCriteria &other);

protected:
    enum LogicalOperator {
        None = 0,
        And,
        Or,
        Not,
    };

    const QVariant &first() const { return cri1; }
    const QVariant &second() const { return cri2; }
    LogicalOperator logicalOperator() const { return (LogicalOperator)logiOp; }
    DSCriteria &add(LogicalOperator op, const DSCriteria &criteria);

private:
    QVariant cri1;
    QVariant cri2;
    int logiOp;

    friend class DSCriteriaConverter;
};

Q_DECLARE_METATYPE(DSCriteria)

#endif // DSCRITERIA_H
