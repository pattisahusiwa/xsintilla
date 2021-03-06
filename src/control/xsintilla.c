#include "xsintilla.h"
#include <stdlib.h>

xsiControlData* xsi_getControlData(REALcontrolInstance ctl)
{
    return REALGetControlData(ctl, &xsiControl);
}

Rect xsi_getRect(REALcontrolInstance ctl)
{
    Rect rect;
    REALGetControlBounds(ctl, &rect);
    return rect;
}

sptr_t xsi_ssm(ScintillaObject* sci, unsigned int iMessage, uptr_t wParam, sptr_t lParam)
{
    return scintilla_send_message(sci, iMessage, wParam, lParam);
}

ScintillaObject* xsciObj(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);
    return data->sci;
}

RBColor xsi_invertColor(RBColor color)
{
    int r = (color >> 16) & 0xFF;
    int g = (color >> 8) & 0xFF;
    int b = color & 0xFF;

    // right conversion formula
    // (r << 16) + (g << 8) + b;

    // based on scintilla documentation
    return r | (g << 8) | (b << 16);
}

REALstring xsi_toREALstring(char* buffer, int length, bool nullTerminated)
{
    if(length <= 0) {
        free(buffer);
        return NULL;
    }

    if(nullTerminated == false)
        length = length + 1;

    REALstring text = REALBuildStringWithEncoding(buffer, length - 1, kREALTextEncodingUTF8);
    REALLockString(text);
    free(buffer);
    return text;
}
