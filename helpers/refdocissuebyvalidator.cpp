#include "refdocissuebyvalidator.h"

RefDocIssueByValidator::RefDocIssueByValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("docIssueByNameEn", Tf::Required, false);
    //setRule("docIssueByNameZh", Tf::Required, false);
    //setRule("docIssueByDesc", Tf::Required, false);

 
    setRule("docIssueByNameEn", Tf::MaxLength, 64);
    setRule("docIssueByNameZh", Tf::MaxLength, 64);

}
