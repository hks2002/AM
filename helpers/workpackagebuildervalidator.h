#ifndef WORKPACKAGEBUILDERVALIDATOR_H
#define WORKPACKAGEBUILDERVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT WorkpackageBuilderValidator : public TFormValidator
{
public:
    WorkpackageBuilderValidator();
};

Q_DECLARE_METATYPE(WorkpackageBuilderValidator)

#endif // WORKPACKAGEBUILDERVALIDATOR_H
