#include "sci-errorhandling.h"

void xsip_SetStatus(REALcontrolInstance ctl, int status)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSTATUS, status, 0);
}
int xsip_getStatus(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSTATUS, 0, 0);
}
