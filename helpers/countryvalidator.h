#ifndef COUNTRYVALIDATOR_H
#define COUNTRYVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT CountryValidator : public TFormValidator
{
public:
    CountryValidator();
};

Q_DECLARE_METATYPE(CountryValidator)

#endif // COUNTRYVALIDATOR_H
