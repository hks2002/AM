#ifndef EVTVENDORVALIDATOR_H
#define EVTVENDORVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EvtVendorValidator : public TFormValidator
{
public:
    EvtVendorValidator();
};

Q_DECLARE_METATYPE(EvtVendorValidator)

#endif // EVTVENDORVALIDATOR_H
