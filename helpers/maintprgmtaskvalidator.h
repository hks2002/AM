#ifndef MAINTPRGMTASKVALIDATOR_H
#define MAINTPRGMTASKVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT MaintPrgmTaskValidator : public TFormValidator
{
public:
    MaintPrgmTaskValidator();
};

Q_DECLARE_METATYPE(MaintPrgmTaskValidator)

#endif // MAINTPRGMTASKVALIDATOR_H
