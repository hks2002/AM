#include <QSqlDatabase>
#include <QSqlField>
#include "dscriteria.h"
#include "dscriteriaconverter.h"

//logic copyed from TCriteria, please reference TCriteria's api when use
//property--> fieldName,fieldType

DSCriteria::DSCriteria()
    : logiOp(None)
{ }

DSCriteria::DSCriteria(const DSCriteria &other)
    : cri1(other.cri1), cri2(other.cri2), logiOp(other.logiOp)
{ }

DSCriteria::DSCriteria(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op)
    : logiOp(None)
{
    cri1 = QVariant::fromValue(DSCriteriaData(fieldName, fieldType, op));
}

DSCriteria::DSCriteria(const QString &fieldName, QVariant::Type fieldType, const QVariant &val)
    : logiOp(None)
{
    cri1 = QVariant::fromValue(DSCriteriaData(fieldName, fieldType, TSql::Equal, val));
}

DSCriteria::DSCriteria(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val)
    : logiOp(None)
{
    cri1 = QVariant::fromValue(DSCriteriaData(fieldName, fieldType, op, val));
}

DSCriteria::DSCriteria(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val1, const QVariant &val2)
    : logiOp(None)
{
    cri1 = QVariant::fromValue(DSCriteriaData(fieldName, fieldType, op, val1, val2));
}


DSCriteria::DSCriteria(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op1, TSql::ComparisonOperator op2, const QVariant &val)
    : logiOp(None)
{
    cri1 = QVariant::fromValue(DSCriteriaData(fieldName, fieldType, op1, op2, val));
}

DSCriteria &DSCriteria::add(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op)
{
    return add(And, DSCriteria(fieldName, fieldType, op));
}

DSCriteria &DSCriteria::add(const QString &fieldName, QVariant::Type fieldType, const QVariant &val)
{
    return add(And, DSCriteria(fieldName, fieldType, val));
}

DSCriteria &DSCriteria::add(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val)
{
    return add(And, DSCriteria(fieldName, fieldType, op, val));
}

DSCriteria &DSCriteria::add(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val1, const QVariant &val2)
{
    return add(And, DSCriteria(fieldName, fieldType, op, val1, val2));
}

DSCriteria &DSCriteria::add(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op1, TSql::ComparisonOperator op2, const QVariant &val)
{
    return add(And, DSCriteria(fieldName, fieldType, op1, op2, val));
}


DSCriteria &DSCriteria::add(const DSCriteria &criteria)
{
    return add(And, criteria);
}

DSCriteria &DSCriteria::addOr(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op)
{
    return add(Or, DSCriteria(fieldName, fieldType, op));
}

DSCriteria &DSCriteria::addOr(const QString &fieldName, QVariant::Type fieldType, const QVariant &val)
{
    return add(Or, DSCriteria(fieldName, fieldType, val));
}


DSCriteria &DSCriteria::addOr(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val)
{
    return add(Or, DSCriteria(fieldName, fieldType, op, val));
}

DSCriteria &DSCriteria::addOr(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val1, const QVariant &val2)
{
    return add(Or, DSCriteria(fieldName, fieldType, op, val1, val2));
}


DSCriteria &DSCriteria::addOr(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op1, TSql::ComparisonOperator op2, const QVariant &val)
{
    return add(Or, DSCriteria(fieldName, fieldType, op1, op2, val));
}


DSCriteria &DSCriteria::addOr(const DSCriteria &criteria)
{
    return add(Or, criteria);
}

DSCriteria &DSCriteria::add(LogicalOperator op, const DSCriteria &criteria)
{
    if (cri1.isNull()) {
        cri1 = QVariant::fromValue(criteria);
        logiOp = None;
        cri2.clear();
    } else {
        if (logiOp != None) {
            cri1 = QVariant::fromValue(*this);
        }

        logiOp = op;
        cri2 = QVariant::fromValue(criteria);
    }

    return *this;
}

const DSCriteria DSCriteria::operator&&(const DSCriteria &criteria) const
{
    DSCriteria res(*this);
    res.add(criteria);
    return res;
}

const DSCriteria DSCriteria::operator||(const DSCriteria &criteria) const
{
    DSCriteria res(*this);
    res.addOr(criteria);
    return res;
}

const DSCriteria DSCriteria::operator!() const
{
    DSCriteria cri(*this);
    cri.logiOp = Not;
    return cri;
}

DSCriteria &DSCriteria::operator=(const DSCriteria &other)
{
    cri1 = other.cri1;
    cri2 = other.cri2;
    logiOp = other.logiOp;
    return *this;
}

bool DSCriteria::isEmpty() const
{
    return cri1.isNull();
}

void DSCriteria::clear()
{
    cri1.clear();
    logiOp = None;
    cri2.clear();
}


