#ifndef EVTEVENTVALIDATOR_H
#define EVTEVENTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EvtEventValidator : public TFormValidator
{
public:
    EvtEventValidator();
};

Q_DECLARE_METATYPE(EvtEventValidator)

#endif // EVTEVENTVALIDATOR_H
