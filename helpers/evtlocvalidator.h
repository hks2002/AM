#ifndef EVTLOCVALIDATOR_H
#define EVTLOCVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EvtLocValidator : public TFormValidator
{
public:
    EvtLocValidator();
};

Q_DECLARE_METATYPE(EvtLocValidator)

#endif // EVTLOCVALIDATOR_H
