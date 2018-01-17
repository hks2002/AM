#ifndef REFMESURTYPEVALIDATOR_H
#define REFMESURTYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefMesurTypeValidator : public TFormValidator
{
public:
    RefMesurTypeValidator();
};

Q_DECLARE_METATYPE(RefMesurTypeValidator)

#endif // REFMESURTYPEVALIDATOR_H
