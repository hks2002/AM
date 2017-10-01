#ifndef MAINTPRGMVALIDATOR_H
#define MAINTPRGMVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT MaintPrgmValidator : public TFormValidator
{
public:
    MaintPrgmValidator();
};

Q_DECLARE_METATYPE(MaintPrgmValidator)

#endif // MAINTPRGMVALIDATOR_H
