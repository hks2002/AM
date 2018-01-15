#ifndef DSCRITERIACONVERTER_H
#define DSCRITERIACONVERTER_H

#include <QVariant>
#include <TCriteriaConverter>
#include <TSqlQuery>
#include <TGlobal>
#include "dscriteria.h"
#include "tsystemglobal.h"

//logic is copyed form TCriteriaConverter
//property--> fieldName,fieldType

class T_CONTROLLER_EXPORT DSCriteriaData
{
public:
    DSCriteriaData();
    DSCriteriaData(const DSCriteriaData &other);
    DSCriteriaData(const QString &fieldName, QVariant::Type fieldType, int op);
    DSCriteriaData(const QString &fieldName, QVariant::Type fieldType, int op, const QVariant &val);
    DSCriteriaData(const QString &fieldName, QVariant::Type fieldType, int op, const QVariant &val1, const QVariant &val2);
    DSCriteriaData(const QString &fieldName, QVariant::Type fieldType, int op1, int op2, const QVariant &val);
    bool isEmpty() const;

    QString fieldName;
    QVariant::Type fieldType {QVariant::Invalid};
    int op1 {TSql::Invalid};
    int op2 {TSql::Invalid};
    QVariant val1;
    QVariant val2;
};

inline DSCriteriaData::DSCriteriaData()
{ }

inline DSCriteriaData::DSCriteriaData(const DSCriteriaData &other)
    :  fieldName(other.fieldName), fieldType(other.fieldType), op1(other.op1), op2(other.op2), val1(other.val1), val2(other.val2)
{ }

inline DSCriteriaData::DSCriteriaData(const QString &fieldName, QVariant::Type fieldType, int op)
    : fieldName(fieldName), fieldType(fieldType), op1(op), op2(TSql::Invalid)
{ }

inline DSCriteriaData::DSCriteriaData(const QString &fieldName, QVariant::Type fieldType, int op, const QVariant &val)
    : fieldName(fieldName), fieldType(fieldType), op1(op), op2(TSql::Invalid), val1(val)
{ }

inline DSCriteriaData::DSCriteriaData(const QString &fieldName, QVariant::Type fieldType, int op, const QVariant &val1, const QVariant &val2)
    : fieldName(fieldName), fieldType(fieldType), op1(op), op2(TSql::Invalid), val1(val1), val2(val2)
{ }

inline DSCriteriaData::DSCriteriaData(const QString &fieldName, QVariant::Type fieldType, int op1, int op2, const QVariant &val)
    : fieldName(fieldName), fieldType(fieldType), op1(op1), op2(op2), val1(val)
{ }

inline bool DSCriteriaData::isEmpty() const
{
    return (fieldName.isEmpty() || op1 == TSql::Invalid);
}

Q_DECLARE_METATYPE(DSCriteriaData)

///////////////////////////////////////////////////////////////////////////////////

class T_CONTROLLER_EXPORT DSCriteriaConverter
{
public:
    DSCriteriaConverter(const DSCriteria &cri, const QSqlDatabase &db) : criteria(cri), database(db) { }
    QString toString() const;

protected:
    QString criteriaToString(const QVariant &cri) const;
    static QString criteriaToString(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val1, const QVariant &val2, const QSqlDatabase &database);
    static QString criteriaToString(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op1, TSql::ComparisonOperator op2, const QVariant &val, const QSqlDatabase &database);
    static QString concat(const QString &s1, DSCriteria::LogicalOperator op, const QString &s2);

private:
    DSCriteria criteria;
    QSqlDatabase database;
};


inline QString DSCriteriaConverter::toString() const
{
    return criteriaToString(QVariant::fromValue(criteria));
}

inline QString DSCriteriaConverter::criteriaToString(const QVariant &var) const
{
    QString sqlString;

    if (var.isNull()) {
        return QString();
    }

    if (var.canConvert<DSCriteria>()) {
        DSCriteria cri = var.value<DSCriteria>();

        if (cri.isEmpty()) {
            return QString();
        }

        sqlString = concat(criteriaToString(cri.first()), cri.logicalOperator(),
                           criteriaToString(cri.second()));

    } else if (var.canConvert<DSCriteriaData>()) {
        DSCriteriaData cri = var.value<DSCriteriaData>();

        if (cri.isEmpty()) {
            return QString();
        }

        if (cri.fieldName.isEmpty()) {
            return QString();
        }

        if (cri.op1 != TSql::Invalid && cri.op2 != TSql::Invalid && !cri.val1.isNull()) {
            sqlString += criteriaToString(cri.fieldName, cri.fieldType, (TSql::ComparisonOperator)cri.op1, (TSql::ComparisonOperator)cri.op2, cri.val1, database);

        } else if (cri.op1 != TSql::Invalid && !cri.val1.isNull() && !cri.val2.isNull()) {
            sqlString += criteriaToString(cri.fieldName, cri.fieldType, (TSql::ComparisonOperator)cri.op1, cri.val1, cri.val2, database);

        } else if (cri.op1 != TSql::Invalid) {
            switch (cri.op1) {
                case TSql::Equal:
                case TSql::NotEqual:
                case TSql::LessThan:
                case TSql::GreaterThan:
                case TSql::LessEqual:
                case TSql::GreaterEqual:
                case TSql::Like:
                case TSql::NotLike:
                case TSql::ILike:
                case TSql::NotILike:
                    sqlString += cri.fieldName + TSql::formatArg(cri.op1, TSqlQuery::formatValue(cri.val1, cri.fieldType, database));
                    break;

                case TSql::In:
                case TSql::NotIn: {
                        QString str;
                        const QList<QVariant> lst = cri.val1.toList();

                        for (auto &v : lst) {
                            QString s = TSqlQuery::formatValue(v, cri.fieldType, database);

                            if (!s.isEmpty()) {
                                str.append(s).append(',');
                            }
                        }

                        str.chop(1);

                        if (!str.isEmpty()) {
                            sqlString += cri.fieldName + TSql::formatArg(cri.op1, str);
                        } else {
                            tWarn("error parameter");
                        }

                        break;
                    }

                case TSql::LikeEscape:
                case TSql::NotLikeEscape:
                case TSql::ILikeEscape:
                case TSql::NotILikeEscape:
                case TSql::Between:
                case TSql::NotBetween: {
                        QList<QVariant> lst = cri.val1.toList();

                        if (lst.count() == 2) {
                            sqlString += criteriaToString(cri.fieldName, cri.fieldType, (TSql::ComparisonOperator)cri.op1, lst[0], lst[1], database);
                        }

                        break;
                    }

                case TSql::IsNull:
                case TSql::IsNotNull:
                    sqlString += cri.fieldName + TSql::formatArg(cri.op1);
                    break;

                case TSql::IsEmpty:
                case TSql::IsNotEmpty:
                    sqlString += TSql::formatArg(cri.op1, cri.fieldName);
                    break;

                default:
                    tWarn("error parameter");
                    break;
            }

        } else {
            tSystemError("Logic error: [%s:%d]", __FILE__, __LINE__);
        }

    } else {
        tSystemError("Logic error [%s:%d]", __FILE__, __LINE__);
    }

    return sqlString;
}


inline QString DSCriteriaConverter::criteriaToString(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op, const QVariant &val1, const QVariant &val2, const QSqlDatabase &database)
{
    QString sqlString;
    QString v1 = TSqlQuery::formatValue(val1, fieldType, database);
    QString v2 = TSqlQuery::formatValue(val2, fieldType, database);

    if (!v1.isEmpty() && !v2.isEmpty()) {
        switch (op) {
            case TSql::LikeEscape:
            case TSql::NotLikeEscape:
            case TSql::ILikeEscape:
            case TSql::NotILikeEscape:
            case TSql::Between:
            case TSql::NotBetween:
                sqlString = QLatin1Char('(') + fieldName + TSql::formatArg(op, v1, v2) + QLatin1Char(')');
                break;

            default:
                tWarn("Invalid parameters  [%s:%d]", __FILE__, __LINE__);
                break;
        }
    } else {
        tWarn("Invalid parameters  [%s:%d]", __FILE__, __LINE__);
    }

    return sqlString;
}


inline QString DSCriteriaConverter::criteriaToString(const QString &fieldName, QVariant::Type fieldType, TSql::ComparisonOperator op1, TSql::ComparisonOperator op2, const QVariant &val, const QSqlDatabase &database)
{
    QString sqlString;

    if (op1 != TSql::Invalid && op2 != TSql::Invalid && !val.isNull()) {
        switch (op2) {
            case TSql::Any:
            case TSql::All: {
                    QString str;
                    const QList<QVariant> lst = val.toList();

                    for (auto &v : lst) {
                        QString s = TSqlQuery::formatValue(v, fieldType, database);

                        if (!s.isEmpty()) {
                            str.append(s).append(',');
                        }
                    }

                    str.chop(1);
                    str = TSql::formatArg(op2, str);

                    if (!str.isEmpty()) {
                        sqlString += fieldName + TSql::formatArg(op1, str);
                    }

                    break;
                }

            default:
                tWarn("Invalid parameters  [%s:%d]", __FILE__, __LINE__);
        }
    } else {
        tWarn("Invalid parameters  [%s:%d]", __FILE__, __LINE__);
    }

    return sqlString;
}


inline QString DSCriteriaConverter::concat(const QString &s1, DSCriteria::LogicalOperator op, const QString &s2)
{
    if (op == DSCriteria::None || (s2.isEmpty() && op != DSCriteria::Not)) {
        return s1;
    }

    QString string;

    switch (op) {
        case DSCriteria::And:
            string = s1 + " AND " + s2;
            break;

        case DSCriteria::Or:
            string = QLatin1Char('(') + s1 + QLatin1String(" OR ") + s2 + QLatin1Char(')');
            break;

        case DSCriteria::Not:
            string = QLatin1String("(NOT ") + s1 + QLatin1Char(')');
            break;

        default:
            tSystemError("Logic error: [%s:%d]", __FILE__, __LINE__);
            break;
    }

    return string;
}

#endif // DSCRITERIACONVERTER_H
