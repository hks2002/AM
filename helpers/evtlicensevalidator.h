#ifndef EVTLICENSEVALIDATOR_H
#define EVTLICENSEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EvtLicenseValidator : public TFormValidator
{
public:
    EvtLicenseValidator();
};

Q_DECLARE_METATYPE(EvtLicenseValidator)

#endif // EVTLICENSEVALIDATOR_H
