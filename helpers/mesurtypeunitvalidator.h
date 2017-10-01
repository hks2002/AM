#ifndef MESURTYPEUNITVALIDATOR_H
#define MESURTYPEUNITVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT MesurTypeUnitValidator : public TFormValidator
{
public:
    MesurTypeUnitValidator();
};

Q_DECLARE_METATYPE(MesurTypeUnitValidator)

#endif // MESURTYPEUNITVALIDATOR_H
