#ifndef REQPARTVALIDATOR_H
#define REQPARTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ReqPartValidator : public TFormValidator
{
public:
    ReqPartValidator();
};

Q_DECLARE_METATYPE(ReqPartValidator)

#endif // REQPARTVALIDATOR_H
