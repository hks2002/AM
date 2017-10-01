#ifndef EVTPARTNOVALIDATOR_H
#define EVTPARTNOVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EvtPartNoValidator : public TFormValidator
{
public:
    EvtPartNoValidator();
};

Q_DECLARE_METATYPE(EvtPartNoValidator)

#endif // EVTPARTNOVALIDATOR_H
