#ifndef EVTINVVALIDATOR_H
#define EVTINVVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EvtInvValidator : public TFormValidator
{
public:
    EvtInvValidator();
};

Q_DECLARE_METATYPE(EvtInvValidator)

#endif // EVTINVVALIDATOR_H
