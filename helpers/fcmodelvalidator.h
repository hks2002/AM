#ifndef FCMODELVALIDATOR_H
#define FCMODELVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT FcModelValidator : public TFormValidator
{
public:
    FcModelValidator();
};

Q_DECLARE_METATYPE(FcModelValidator)

#endif // FCMODELVALIDATOR_H
