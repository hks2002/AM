#include "currencyvalidator.h"

CurrencyValidator::CurrencyValidator() : TFormValidator()
{
    setRule("CurrencyCd", Tf::MaxLength, 16);
    setRule("CurrencyName", Tf::MaxLength, 64);
}
