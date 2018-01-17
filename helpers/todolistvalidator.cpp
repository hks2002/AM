#include "todolistvalidator.h"

TodoListValidator::TodoListValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("todoListCd", Tf::Required, false);
    //setRule("todoListNameZh", Tf::Required, false);
    //setRule("todoListNameEn", Tf::Required, false);
    setRule("todoListTooltip", Tf::Required, false);


    setRule("todoListCd", Tf::MaxLength, 64);
    setRule("todoListNameZh", Tf::MaxLength, 64);
    setRule("todoListNameEn", Tf::MaxLength, 64);
    setRule("todoListTooltip", Tf::MaxLength, 256);

}
