#ifndef EVTTOOLVALIDATOR_H
#define EVTTOOLVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EvtToolValidator : public TFormValidator
{
public:
    EvtToolValidator();
};

Q_DECLARE_METATYPE(EvtToolValidator)

#endif // EVTTOOLVALIDATOR_H
