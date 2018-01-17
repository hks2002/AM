#include "menusgroupvalidator.h"

MenusGroupValidator::MenusGroupValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("menusGroupCd", Tf::Required, false);
    //setRule("menusGroupNameZh", Tf::Required, false);
    //setRule("menusGroupNameEn", Tf::Required, false);
    setRule("menusGroupTooltip", Tf::Required, false);


    setRule("menusGroupCd", Tf::MaxLength, 16);
    setRule("menusGroupNameZh", Tf::MaxLength, 64);
    setRule("menusGroupNameEn", Tf::MaxLength, 64);
    setRule("menusGroupTooltip", Tf::MaxLength, 256);

}
