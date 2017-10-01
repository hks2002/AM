#ifndef APPLICATIONHELPER_H
#define APPLICATIONHELPER_H

#include <TGlobal>
#include <TActionContext>
#include <THttpRequest>
#include <TCryptMac>
#include <TActionController>
#include <TCriteria>
#include <TSqlORMapper>
#include <TAbstractModel>
#include <QList>

//this is mainly used for transfer pk and pk value between views template
Q_DECLARE_METATYPE(QVariantMap)

class T_HELPER_EXPORT ApplicationHelper
{
public:
    ApplicationHelper();
};

T_HELPER_EXPORT inline QString UI(const QString &code)
{
    QString lang = Tf::currentContext()->httpRequest().cookie("lang");
    QString utf8str;

    if (lang == "zh") {
        utf8str = Tf::app()->getConfigValue("zh_CN", code, code).toString();
    } else {
        utf8str = Tf::app()->getConfigValue("en_US", code, code).toString();
    }

    tTrace(QString("UI:").append(code).append("->").append(utf8str).toLatin1().data());
    return QString::fromUtf8(utf8str.toLatin1().data());
}

T_HELPER_EXPORT inline QString CFG(const QString &code)
{
    QString utf8str;

    utf8str = Tf::app()->getConfigValue("AM", code).toString();
    tTrace(QString("CFG:").append(code).append("->").append(utf8str).toLatin1().data());
    return utf8str;
}

T_HELPER_EXPORT inline QString hmac(int id)
{
    if (CFG("ENABLE_HASH").toLower() == "true" || CFG("ENABLE_HASH") == "1") {
        TSession &s = const_cast<TSession &>(Tf::currentContext()->currentController()->session());
        QString hash = TCryptMac::hash(QString::number(id).toLatin1(), Tf::currentContext()->currentController()->session().id(), TCryptMac::Hmac_Md5).toHex();
        s.insert(hash, id);
        tTrace() << "id->Hash:" << id << "->" << hash;
        return hash;
    } else {
        return QString::number(id);
    }

}

T_HELPER_EXPORT inline QString hmac(const QString &cd)
{
    if (CFG("ENABLE_HASH").toLower() == "true" || CFG("ENABLE_HASH") == "1") {
        TSession &s = const_cast<TSession &>(Tf::currentContext()->currentController()->session());
        QString hash = TCryptMac::hash(cd.toLatin1(), Tf::currentContext()->currentController()->session().id(), TCryptMac::Hmac_Md5).toHex();
        s.insert(hash, cd);
        tTrace() << "cd->Hash:" << cd << "->" << hash;
        return hash;
    } else {
        return cd;
    }
}

T_HELPER_EXPORT inline QVariant hmacVal(const QString &hash)
{
    if (CFG("ENABLE_HASH").toLower() == "true" || CFG("ENABLE_HASH") == "1") {
        TSession &s = const_cast<TSession &>(Tf::currentContext()->currentController()->session());
        tTrace() << "hash->id/cd:" << hash << "->" << s.value(hash).toString();
        return s.value(hash);
    } else {
        return hash;
    }
}

T_HELPER_EXPORT inline bool accessAllow(const QString &ctl, const QString &act)
{
    QString url =  ctl + "/" + act;
    int currentUserId = Tf::currentContext()->currentController()->session().value(url).toInt();

    if (currentUserId <= 0) {
        tDebug() << "Access:" << url << " is Forbidden";
        //FIXME should be false, please change it
        //Use true for development
        return true;
    }

    return true;
}

T_HELPER_EXPORT inline bool accessAllow(const QString &url)
{
    int currentUserId = Tf::currentContext()->currentController()->session().value(url).toInt();

    if (currentUserId <= 0) {
        tDebug() << "Access:" << url << " is Forbidden";
        //FIXME should be false, please change it
        //Use true for development
        return true;
    }

    return true;
}

T_HELPER_EXPORT inline QJsonObject jsonObj(bool success, const QString &msg = "")
{
    QJsonObject obj;
    obj.insert("success", success);
    obj.insert("msg", msg);
    return obj;
}

T_HELPER_EXPORT inline QString domToJsStr(const QString &input)
{
    const QLatin1Char dquot('"');
    const QLatin1Char squot('\'');
    const QLatin1Char backslash('\\');
    const QLatin1Char newline('\n');
    const QLatin1Char carriagereturn('\r');

    const QString edquot("\\\"");
    const QString esquot("\\'");
    const QString ebackslash("\\\\");
    const QString enewline(" ");
    const QString ecarriagereturn(" ");

    QString escaped;
    escaped.reserve(int(input.length() * 1.1));

    for (int i = 0; i < input.length(); ++i) {
        if (input.at(i) == dquot) {
            escaped += edquot;
        } else if (input.at(i) == squot) {
            escaped += esquot;
        } else if (input.at(i) == backslash) {
            escaped += ebackslash;
        } else if (input.at(i) == newline) {
            escaped += enewline;
        } else if (input.at(i) == carriagereturn) {
            escaped += ecarriagereturn;
        } else {
            escaped += input.at(i);
        }
    }

    return escaped.prepend('"').append('"');
}

T_HELPER_EXPORT inline QString csrfVal()
{
    QString s;

    if (Tf::currentContext()->currentController()->csrfProtectionEnabled()) {
        s =  Tf::currentContext()->currentController()->authenticityToken();
    }

    return s;
}

T_HELPER_EXPORT inline QVariantMap mapNoHash(const QVariantMap &varMaps, const QStringList &fieldlist)
{
    QVariantMap map;

    for (QMapIterator<QString, QVariant> it(varMaps); it.hasNext();) {
        it.next();

        if (fieldlist.contains(it.key())) {
            map.insert(it.key(), hmacVal(it.value().toString()));
        } else {
            map.insert(it.key(), it.value());
        }
    }

    return map;
}

template<class V>
inline QString mapValidate(QVariantMap &varMaps)
{
    V validator;
    QString err;

    if (!validator.validate(varMaps)) {
        QStringList errs = validator.errorMessages();

        for (auto &s : errs) {
            err += UI(s).append("\n");
        }
    }

    return err;
}

T_HELPER_EXPORT inline QString tId()
{
    qint64 time1, time2;
    time1 = QDateTime::currentMSecsSinceEpoch();

    do {
        time2 = QDateTime::currentMSecsSinceEpoch();
    } while (time1 == time2);

    return QString::number(time2);
}

#endif // APPLICATIONHELPER_H
