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
        utf8str = Tf::app()->getConfigValue("zh_CN", code, "").toString().trimmed();
    } else {
        utf8str = Tf::app()->getConfigValue("en_US", code, "").toString().trimmed();
    }

    tSystemTrace("UI:%s -> %s", code.toLatin1().data(), utf8str.toLatin1().data());

    if (utf8str.isEmpty()) {
        tError("UI %s not found.", code.toLatin1().data());
        utf8str = code;
    }

    return QString::fromUtf8(utf8str.toLatin1().data());
}

T_HELPER_EXPORT inline QString CFG(const QString &code)
{
    QString utf8str;

    utf8str = Tf::app()->getConfigValue("am", code).toString().trimmed();
    tSystemTrace("CFG %s: %s", code.toLatin1().data(), utf8str.toLatin1().data());
    return utf8str;
}

T_HELPER_EXPORT inline QString hmac(int id)
{
    QString enableHash = CFG("ENABLE_HASH").toLower();

    if (enableHash == "true" || enableHash == "yes" || enableHash == "t" || enableHash == "y" || enableHash == "1") {
        TSession &s = const_cast<TSession &>(Tf::currentContext()->currentController()->session());
        QString hash = TCryptMac::hash(QString::number(id).toLatin1(), Tf::currentContext()->currentController()->session().id(), TCryptMac::Hmac_Md5).toHex();
        s.insert(hash, id);
        tSystemTrace("id->Hash: %d -> %s", id, hash.toLatin1().data());
        return hash;
    } else {
        return QString::number(id);
    }

}

T_HELPER_EXPORT inline QString hmac(const QString &cd)
{
    QString enableHash = CFG("ENABLE_HASH").toLower();

    if (enableHash == "true" || enableHash == "yes" || enableHash == "t" || enableHash == "y" || enableHash == "1") {
        TSession &s = const_cast<TSession &>(Tf::currentContext()->currentController()->session());
        QString hash = TCryptMac::hash(cd.toLatin1(), Tf::currentContext()->currentController()->session().id(), TCryptMac::Hmac_Md5).toHex();
        s.insert(hash, cd);
        tSystemTrace("id->Hash: %s -> %s", cd.toLatin1().data(), hash.toLatin1().data());
        return hash;
    } else {
        return cd;
    }
}

T_HELPER_EXPORT inline QVariant hmacVal(const QString &hash)
{
    if (CFG("ENABLE_HASH").toLower() == "true" || CFG("ENABLE_HASH") == "1") {
        TSession &s = const_cast<TSession &>(Tf::currentContext()->currentController()->session());
        tSystemTrace("Hash->id/cd: %s -> %s", hash.toLatin1().data(), s.value(hash).toString().toLatin1().data());
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
        tTrace("Access :%s is Forbidden", url.toLatin1().data());
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
        tTrace("Access %s is Forbidden", url.toLatin1().data());
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
