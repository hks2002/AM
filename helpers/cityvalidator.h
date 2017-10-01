#ifndef CITYVALIDATOR_H
#define CITYVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT CityValidator : public TFormValidator
{
public:
    CityValidator();
};

Q_DECLARE_METATYPE(CityValidator)

#endif // CITYVALIDATOR_H
