// Control headers
#include "behaviour.h"
#include "definition.h"
#include "event.h"
#include "xsintilla.h"

// Properties headers
#include "error-properties.h"
#include "selection-properties.h"
#include "text-properties.h"

// Method headers
#include "selection-method.h"
#include "text-method.h"

// Enum headers

////#include "sci-autoc.h"
////#include "sci-lexer.h"
////#include "sci-marker.h"
////#include "sci-styledef.h"
////#include "sci-styling.h"
////#include "sci-words.h"

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
// group, name, type, flags, getter, setter, param, editor, enumCount, enumEntries, attributeCount, attributes
REALproperty xsiProperties[] = {
    /*+++++++++++++++++++++++++
     * CLASSES
     +++++++++++++++++++++++++*/
    {"", "margin", "xsiMargin", REALpropRuntimeOnly, (REALproc)xsi_getMarginObject, REALnoImplementation},
    {"", "lexer", "xsiLexer", REALpropRuntimeOnly, (REALproc)xsi_getLexerObject, REALnoImplementation},

    /*+++++++++++++++++++++++++
     * text-properties.h
     +++++++++++++++++++++++++*/
    {"", "readonly", "Boolean", REALpropRuntimeOnly, (REALproc)xsip_getReadonly, (REALproc)xsip_setReadonly},
    {"", "text", "String", REALpropRuntimeOnly, (REALproc)xsip_getText, (REALproc)xsip_setText},

    /*+++++++++++++++++++++++++
     * error-properties.h
     +++++++++++++++++++++++++*/
    {"", "status", "Integer", REALpropRuntimeOnly, (REALproc)xsip_getStatus, (REALproc)xsip_SetStatus},

    /*+++++++++++++++++++++++++
     * selection-properties.h
     +++++++++++++++++++++++++*/
    {"", "textLength", "Integer", REALpropRuntimeOnly, (REALproc)xsip_getTextLength, REALnoImplementation},
    {"", "length", "Integer", REALpropRuntimeOnly, (REALproc)xsip_getLength, REALnoImplementation},
    {"", "lineCount", "Integer", REALpropRuntimeOnly, (REALproc)xsip_getLineCount, REALnoImplementation},
    {"", "lineOnScreen", "Integer", REALpropRuntimeOnly, (REALproc)xsip_lineOnScreen, REALnoImplementation},
    {"", "modified", "Boolean", REALpropRuntimeOnly, (REALproc)xsip_getModify, REALnoImplementation},
    {"", "currentPos", "Integer", REALpropRuntimeOnly, (REALproc)xsip_getCurrentPos, (REALproc)xsip_setCurrentPos},
    {"", "anchor", "Integer", REALpropRuntimeOnly, (REALproc)xsip_getAnchor, (REALproc)xsip_setAnchor},
    {"", "selectionStart", "Integer", REALpropRuntimeOnly, (REALproc)xsip_getSelectionStart,
     (REALproc)xsip_setSelectionStart},
    {"", "selectionEnd", "Integer", REALpropRuntimeOnly, (REALproc)xsip_getSelectionEnd,
     (REALproc)xsip_setSelectionEnd},
    {"", "hideSelection", "Boolean", REALpropRuntimeOnly, REALnoImplementation, (REALproc)xsip_hideSelection},
    {"", "seltext", "String", REALpropRuntimeOnly, (REALproc)xsip_getSeltext, REALnoImplementation},
    {"", "selectionIsRectangle", "Boolean", REALpropRuntimeOnly, (REALproc)xsip_selectionIsRectangle,
     REALnoImplementation},
    {"", "selectionMode", "Integer", REALpropRuntimeOnly, (REALproc)xsip_getSelectionMode,
     (REALproc)xsip_setSelectionMode},
    {"", "mouseSelectionRectangularSwitch", "Boolean", REALpropRuntimeOnly,
     (REALproc)xsip_getMouseSelectionRectangularSwitch, (REALproc)xsip_setMouseSelectionRectangularSwitch},

    //    /*+++++++++++++++++++++++++
    //     * sci-marker.h
    //     +++++++++++++++++++++++++*/
    //    {"", "rgbaImageSetWidth", "Integer", REALpropRuntimeOnly, REALnoImplementation,
    //     (REALproc)xsip_rgbaImageSetWidth},
    //    {"", "rgbaImageSetHeight", "Integer", REALpropRuntimeOnly, REALnoImplementation,
    //     (REALproc)xsip_rgbaImageSetHeight},
    //    {"", "rgbaImageSetScale", "Integer", REALpropRuntimeOnly, REALnoImplementation,
    //     (REALproc)xsip_rgbaImageSetScale},
    //    {"", "markerEnableHighlight", "Boolean", REALpropRuntimeOnly, REALnoImplementation,
    //     (REALproc)xsip_markerEnableHighlight},
    //
    //    /*+++++++++++++++++++++++++
    //     * sci-autoc.h
    //     +++++++++++++++++++++++++*/
    //    {"", "autocIgnoreCase", "Boolean", REALpropRuntimeOnly, (REALproc)xsip_autocGetIgnoreCase,
    //     (REALproc)xsip_autocSetIgnoreCase},
    //    {"", "autocSeparator", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetSeparator,
    //     (REALproc)xsip_autocSetSeparator},
    //    {"", "autocCancelAtStart", "Boolean", REALpropRuntimeOnly,
    //    (REALproc)xsip_autocGetCancelAtStart,
    //     (REALproc)xsip_autocSetCancelAtStart},
    //    {"", "autocChooseSingle", "Boolean", REALpropRuntimeOnly,
    //    (REALproc)xsip_autocGetChooseSingle,
    //     (REALproc)xsip_autocSetChooseSingle},
    //    {"", "autocCaseInsensitiveBehaviour", "Integer", REALpropRuntimeOnly,
    //     (REALproc)xsip_autocGetCaseInsensitiveBehaviour, (REALproc)xsip_autocSetCaseInsensitiveBehaviour},
    //    {"", "autocMulti", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetMulti,
    //     (REALproc)xsip_autocSetMulti},
    //    {"", "autocOrder", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetOrder,
    //     (REALproc)xsip_autocSetOrder},
    //    {"", "autocAutoHide", "Boolean", REALpropRuntimeOnly, (REALproc)xsip_autocGetAutoHide,
    //     (REALproc)xsip_autocSetAutoHide},
    //    {"", "autocDropRestOfWord", "Boolean", REALpropRuntimeOnly,
    //    (REALproc)xsip_autocGetDropRestOfWord,
    //     (REALproc)xsip_autocSetDropRestOfWord},
    //    {"", "autocTypeSeparator", "Integer", REALpropRuntimeOnly,
    //    (REALproc)xsip_autocGetTypeSeparator,
    //     (REALproc)xsip_autocSetTypeSeparator},
    //    {"", "autocMaxHeight", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetMaxHeight,
    //     (REALproc)xsip_autocSetMaxHeight},
    //    {"", "autocMaxWidth", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetMaxWidth,
    //     (REALproc)xsip_autocSetMaxWidth},
};

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
// function, setterFunction, declaration, mFlags, attributeCount, attributes
REALmethodDefinition xsiMethods[] = {
    //{(REALproc)xsi_getMarginObject, REALnoImplementation, "margin() as xsiMargin"},
    /*+++++++++++++++++++++++++
     * text-method.h
     +++++++++++++++++++++++++*/
    {(REALproc)xsim_setSavePoint, REALnoImplementation, "SetSavePoint()"},
    {(REALproc)xsim_getLine, REALnoImplementation, "GetLine(lineNum as Integer) as String"},
    {(REALproc)xsim_replaceSel, REALnoImplementation, "ReplaceSel(text as String)"},
    {(REALproc)xsim_allocate, REALnoImplementation, "Allocate(bytes as Integer)"},
    {(REALproc)xsim_addText, REALnoImplementation, "AddText(length as Integer, text as String)"},
    {(REALproc)xsim_appendText, REALnoImplementation, "AppendText(length as Integer, text as String)"},
    {(REALproc)xsim_insertText, REALnoImplementation, "InsertText(pos as Integer, text as String)"},
    {(REALproc)xsim_clearAll, REALnoImplementation, "ClearAll()"},
    {(REALproc)xsim_deleteRange, REALnoImplementation, "DeleteRange(start as Integer, lengthDelete as Integer)"},
    {(REALproc)xsim_clearDocumentStyle, REALnoImplementation, "ClearDocumentStyle()"},
    {(REALproc)xsim_getCharAt, REALnoImplementation, "GetCharAt(pos as Integer) as String"},
    {(REALproc)xsim_getStyleAt, REALnoImplementation, "GetStyleAt(pos as Integer) as Integer"},
    {(REALproc)xsim_releaseAllExtendedStyles, REALnoImplementation, "ReleaseAllExtendedStyle()"},
    {(REALproc)xsim_allocateExtendedStyles, REALnoImplementation,
     "AllocateExtendedStyles(numberStyles as Integer) as Integer"},
    {(REALproc)xsim_getTextRange, REALnoImplementation, "TextRange(startPos as Integer, endPos as Integer) as String"},
    {(REALproc)xsim_targetAsUtf8, REALnoImplementation, "TargetAsUTF8() as String"},
    {(REALproc)xsim_encodeFromUtf8, REALnoImplementation,
     "EncodeFromUTF8(length as Integer, utf8 as String) as String"},
    {(REALproc)xsim_addStyledText, REALnoImplementation, "AddStyledText(length as Integer, styled_text as String)"},
    {(REALproc)xsim_getStyledText, REALnoImplementation,
     "GetStyledText(startPos as Integer, endPos as Integer) as String"},
    {(REALproc)xsim_changeInsertion, REALnoImplementation, "ChangeInsertion(length as Integer, text as String)"},

    /*+++++++++++++++++++++++++
     * selection-method.h
     +++++++++++++++++++++++++*/
    {(REALproc)xsim_setSel, REALnoImplementation, "SetSel(anchor as Integer, caret as Integer)"},
    {(REALproc)xsim_gotoPos, REALnoImplementation, "GotoPos(caret as Integer)"},
    {(REALproc)xsim_gotoLine, REALnoImplementation, "GotoLine(line as Integer)"},
    {(REALproc)xsim_setEmptySelection, REALnoImplementation, "SetEmptySelection(caret as Integer)"},
    {(REALproc)xsim_selectAll, REALnoImplementation, "SelectAll()"},
    {(REALproc)xsim_lineFromPosition, REALnoImplementation, "LineFromPosition(pos as Integer) as Integer"},
    {(REALproc)xsim_positionFromLine, REALnoImplementation, "PositionFromLine(line as Integer) as Integer"},
    {(REALproc)xsim_getLineEndPosition, REALnoImplementation, "GetLineEndPosition(line as Integer) as Integer"},
    {(REALproc)xsim_lineLength, REALnoImplementation, "LineLength(line as Integer) as Integer"},
    {(REALproc)xsim_getColumn, REALnoImplementation, "GetColumn(pos as Integer) as Integer"},
    {(REALproc)xsim_findColumn, REALnoImplementation, "FindColumn(line as Integer, column as Integer) as Integer "},
    {(REALproc)xsim_positionFromPoint, REALnoImplementation,
     "PositionFromPoint(x as Integer, y as Integer) as Integer"},
    {(REALproc)xsim_positionFromPointClose, REALnoImplementation,
     "PositionFromPointClose(x as Integer, y as Integer) as Integer"},
    {(REALproc)xsim_charPositionFromPoint, REALnoImplementation,
     "CharPositionFromPoint(x as Integer, y as Integer) as Integer"},
    {(REALproc)xsim_charPositionFromPointClose, REALnoImplementation,
     "CharPositionFromPointClose(x as Integer, y as Integer) as Integer"},
    {(REALproc)xsim_pointXFromPosition, REALnoImplementation, "PointXFromPosition(pos as Integer) as Integer"},
    {(REALproc)xsim_pointYFromPosition, REALnoImplementation, "PointYFromPosition(pos as Integer) as Integer"},
    {(REALproc)xsim_getCurLine, REALnoImplementation, "GetCurLine() as String"},
    {(REALproc)xsim_getLineSelStartPosition, REALnoImplementation,
     "GetLineSelStartPosition(line as Integer) as Integer"},
    {(REALproc)xsim_getLineSelEndPosition, REALnoImplementation, "GetLineSelEndPosition(line as Integer) as Integer "},
    {(REALproc)xsim_moveCaretInsideView, REALnoImplementation, "MoveCaretInsideView()"},
    {(REALproc)xsim_positionBefore, REALnoImplementation, "PositionBefore(pos as Integer) as Integer"},
    {(REALproc)xsim_positionAfter, REALnoImplementation, "PositionAfter(pos as Integer) as Integer"},
    {(REALproc)xsim_positionRelative, REALnoImplementation,
     "PositionRelative(pos as Integer, relative as Integer) as Integer"},
    {(REALproc)xsim_countCharacters, REALnoImplementation,
     "CountCharacters(posStart as Integer, posEnd as Integer) as Integer"},
    {(REALproc)xsim_textWidth, REALnoImplementation, "TextWidth(style as Integer, text as String) as Integer"},
    {(REALproc)xsim_textHeight, REALnoImplementation, "TextHeight(line as Integer) as Integer"},
    {(REALproc)xsim_chooseCaretX, REALnoImplementation, "ChooseCaretX()"},
    {(REALproc)xsim_moveSelectedLinesUp, REALnoImplementation, "MoveSelectedLinesUp()"},
    {(REALproc)xsim_moveSelectedLinesDown, REALnoImplementation, "MoveSelectedLinesDown()"},

    //    /*+++++++++++++++++++++++++
    //    * sci-styledef.h
    //    +++++++++++++++++++++++++*/
    //    {(REALproc)xsim_styleResetDefault, REALnoImplementation, "StyleResetDefault()"},
    //    {(REALproc)xsim_styleClearAll, REALnoImplementation, "StyleClearAll()"},
    //    {(REALproc)xsim_styleGetFont, REALnoImplementation, "Font(style as Integer) as String"},
    //    {(REALproc)xsim_styleSetFont, REALnoImplementation, "Font(style as Integer, assigns fontName as
    //    String)"},
    //    {(REALproc)xsim_styleGetSize, REALnoImplementation, "FontSize(style as Integer) as Integer"},
    //    {(REALproc)xsim_styleSetSize, REALnoImplementation, "FontSize(style as Integer, assigns sizePoints as
    //    Integer)"},
    //    {(REALproc)xsim_styleGetWeight, REALnoImplementation, "FontWeight(style as Integer) as Integer"},
    //    {(REALproc)xsim_styleSetWeight, REALnoImplementation, "FontWeight(style as Integer, assigns weight as
    //    Integer)"},
    //    {(REALproc)xsim_styleGetFore, REALnoImplementation, "Forecolor(style as Integer) as Color"},
    //    {(REALproc)xsim_styleSetFore, REALnoImplementation, "Forecolor(style as Integer, assigns fore as
    //    Color)"},
    //    {(REALproc)xsim_styleGetBack, REALnoImplementation, "Backcolor(style as Integer) as Color"},
    //    {(REALproc)xsim_styleSetBack, REALnoImplementation, "Backcolor(style as Integer, assigns back as
    //    Color)"},
    //    {(REALproc)xsim_styleGetVisible, REALnoImplementation, "StyleVisible(style as Integer) as Boolean"},
    //    {(REALproc)xsim_styleSetVisible, REALnoImplementation,
    //     "StyleVisible(style as Integer, assigns visible as Boolean)"},
    //
    //    /*+++++++++++++++++++++++++
    //     * sci-marker.h
    //     +++++++++++++++++++++++++*/
    //    {(REALproc)xsim_markerDefine, REALnoImplementation,
    //     "MarkerDefine(markerNumber as ScMarkNum, markerSymbol as ScMarker)"},
    //    {(REALproc)xsim_markerSetFore, REALnoImplementation,
    //     "MarkerSetFore(markerNumber as ScMarkNum, assigns fore as Color)"},
    //    {(REALproc)xsim_markerSetBack, REALnoImplementation,
    //     "MarkerSetBack(markerNumber as ScMarkNum, assigns back as Color)"},
    //    {(REALproc)xsim_markerSetBackSelected, REALnoImplementation,
    //     "MarkerSetBackSelected(markerNumber as ScMarkNum, assigns back as Color)"},
    //    {(REALproc)xsim_markerDefineRgbaImage, REALnoImplementation,
    //     "MarkerDefineRgbaImage(markerNumber as ScMarkNum, assigns pixel as String)"},
    //    {(REALproc)xsim_markerSymbolDefined, REALnoImplementation,
    //     "MarkerSymbolDefined(markerNumber as ScMarkNum) as Integer"},
    //    {(REALproc)xsim_markerAdd, REALnoImplementation,
    //     "MarkerAdd(line as Integer, markerNumber as ScMarkNum) as Integer"},
    //    {(REALproc)xsim_markerAddSet, REALnoImplementation, "MarkerAddSet(line as Integer, markerNumber as
    //    ScMarkNum)"},
    //    {(REALproc)xsim_markerDelete, REALnoImplementation, "MarkerDelete(line as Integer, markerNumber as
    //    ScMarkNum)"},
    //    {(REALproc)xsim_markerDeleteAll, REALnoImplementation, "MarkerDeleteAll(markerNumber as ScMarkNum)"},
    //    {(REALproc)xsim_markerGet, REALnoImplementation, "MarkerGet(line as Integer) as Integer"},
    //    {(REALproc)xsim_markerNext, REALnoImplementation,
    //     "MarkerNext(lineStart as Integer, markerMask as Integer) as Integer"},
    //    {(REALproc)xsim_markerPrevious, REALnoImplementation,
    //     "MarkerPrevious(lineStart as Integer, markerMask as Integer) as Integer"},
    //
    //    /*+++++++++++++++++++++++++
    //     * sci-autoc.h
    //     +++++++++++++++++++++++++*/
    //    {(REALproc)xsim_autocShow, REALnoImplementation, "AutocShow(lengthEntered as Integer, itemList as
    //    String)"},
    //    {(REALproc)xsim_autocCancel, REALnoImplementation, "AutocCancel()"},
    //    {(REALproc)xsim_autocActive, REALnoImplementation, "AutocActive() as Boolean"},
    //    {(REALproc)xsim_autocComplete, REALnoImplementation, "AutocComplete()"},
    //    {(REALproc)xsim_autocPosStart, REALnoImplementation, "AutocPosStart() as Integer"},
    //    {(REALproc)xsim_autocStops, REALnoImplementation, "AutocStops(characterSet as String)"},
    //    {(REALproc)xsim_autocSelect, REALnoImplementation, "AutocSelect(selectText as String)"},
    //    {(REALproc)xsim_autocGetCurrent, REALnoImplementation, "AutocGetCurrent()"},
    //    {(REALproc)xsim_autocGetCurrentText, REALnoImplementation, "AutocGetCurrentText() as String"},
    //    {(REALproc)xsim_autocSetFillUps, REALnoImplementation, "AutocSetFillUps(characterSet as String)"},
    //
    //    /*+++++++++++++++++++++++++
    //     * sci-styling.h
    //     +++++++++++++++++++++++++*/
    //    {(REALproc)xsim_getEndStyled, REALnoImplementation, "GetEndStyled() as Integer"},
    //    {(REALproc)xsim_startStyling, REALnoImplementation, "StartStyling(start as Integer)"},
    //    {(REALproc)xsim_setStyling, REALnoImplementation, "SetStyling(length as Integer, style as Integer)"},
    //
    //    /*+++++++++++++++++++++++++
    //     * sci-words.h
    //     +++++++++++++++++++++++++*/
    //    {(REALproc)xsim_wordStartPosition, REALnoImplementation,
    //     "WordStartPosition(pos as Integer, onlyWordCharacters as Boolean) as Integer"},
};

//+++++++++++++++++++++++++++++++++
// Events
//+++++++++++++++++++++++++++++++++
REALevent xsiEvents[] = {
    // declaration, forSystemUse, attributeCount, attributes
    {"AutocCompleted(ch as Integer, listCompletionMethod as Integer)"},
    {"AutocSelection(position as Integer, ch as Integer, listCompletionMethod as Integer)"},
    {"CallTipClick(position as Integer)"},
    {"CharAdded(ch as Integer)"},
    {"DoubleClick(position as Integer, modifiers as Integer)"},
    {"DwellEnd(position as Integer, x as Integer, y as Integer)"},
    {"DwellStart(position as Integer, x as Integer, y as Integer)"},
    {"HotspotClick(position as Integer, modifiers as Integer)"},
    {"HotspotDoubleClick(position as Integer, modifiers as Integer)"},
    {"HotspotReleaseClick(position as Integer, modifiers as Integer)"},
    {"IndicatorClick(position as Integer, modifiers as Integer)"},
    {"IndicatorRelease(position as Integer, modifiers as Integer)"},
    {"ScnKey(ch as Integer)"},
    {"MacroRecord(message as Integer, wParam as Integer, lParam as Integer)"},
    {"MarginClick(position as Integer, margin as Integer)"},
    {"Modified(position as Integer, modificationType as Integer, text as String, length as Integer, linesAdded as "
     "Integer, line as Integer, foldLevelNow as Integer, foldLevelPrev as Integer, token as Integer, "
     "annotationLinesAdded as Integer)"},
    {"NeedShown(position as Integer)"},
    {"StyleNeeded(position as Integer)"},
    {"UpdateUI(updated as Integer)"},
    {"UriDropped(text as String)"},
    {"UserListSelection(position as Integer, ch as Integer, text as String, listType as Integer, listCompletionMethod "
     "as Integer)"},
    {"SavePointReached()"},
    {"SavePointLeft()"},
    {"ModifyAtTempTro()"},
    {"Zoom()"},
    {"AutocCancelled()"},
    {"AutocCharDeleted()"},
    {"FocusIn()"},
    {"FocusOut()"},
    {"MarginRightClick()"},
    {"Painted()"},
};

//+++++++++++++++++++++++++++++++++
// Behaviour
//+++++++++++++++++++++++++++++++++
REALcontrolBehaviour xsiBehavior = {
    Constructor,      // constructorFunction
    Destructor,       // destructorFunction
    NULL,             // redrawFunction
    NULL,             // clickFunction
    NULL,             // mouseDragFunction
    NULL,             // mouseUpFunction
    NULL,             // gainedFocusFunction
    NULL,             // lostFocusFunction
    NULL,             // keyDownFunction
    OnOpen,           // openFunction
    NULL,             // closeFunction
    NULL,             // backgroundIdleFunction
    OnDrawOffscreen,  // drawOffscreenFunction
    NULL,             // setSpecialBackground
    NULL,             // constantChanging
    NULL,             // droppedNewInstance
    NULL,             // mouseEnterFunction
    NULL,             // mouseExitFunction
    NULL,             // mouseMoveFunction
    NULL,             // stateChangedFunction
    NULL,             // actionEventFunction
    NULL,             // controlHandleGetter
    NULL,             // mouseWheelFunction
    NULL,             // enableMenuItemsFunction
    NULL,             // menuItemActionFunction
    NULL,             // controlAcceptFocus
    NULL,             // keyUpFunction
    NULL,             // redrawWithRectsFunction
    NULL,             // unfilteredKeyDownFunction
    NULL,             // scaleFactorChangedFunction
    NULL,             // reserved2
    NULL              // reserved3
    // end of struct
};

//+++++++++++++++++++++++++++++++++
// Constants
//+++++++++++++++++++++++++++++++++
REALconstant xsiConstant[] = {
    {"StyleMax as Integer = 255"},           // STYLE_MAX 255
    {"MarkerMax as Integer = 31"},           // MARKER_MAX 31
    {"MaskFolder as Integer = &hFE000000"},  // SC_MASK_FOLDERS 0xFE000000
};

//+++++++++++++++++++++++++++++++++
// Enumerations
//+++++++++++++++++++++++++++++++++
static const char* enumSelection[] = {
    "STREAM = 0",     // SC_SEL_STREAM=0
    "RECTANGLE = 1",  // SC_SEL_RECTANGLE=1
    "LINES = 2",      // SC_SEL_LINES=2
    "THIN = 3",       // SC_SEL_THIN=3
};

REALenum EnumDef[] = {
    // name, type, mFlags, fields, numFields, attributeCount, attributes
    {"eSelection", "Int8", REALScopePublic, enumSelection, 4},
};

//+++++++++++++++++++++++++++++++++
// xsintilla Control
//+++++++++++++++++++++++++++++++++
REALcontrol xsiControl = {
    kCurrentREALControlVersion,                         // version
    "xsintilla",                                        // name
    sizeof(xsiControlData),                             // dataSize
    REALdontEraseBackground,                            // flags
    0,                                                  // toolbarPICT
    0,                                                  // toolbarDownPICT
    100,                                                // defaultWidth
    100,                                                // defaultHeight
    xsiProperties,                                      // properties
    sizeof(xsiProperties) / sizeof(REALproperty),       // propertyCount
    xsiMethods,                                         // methods
    sizeof(xsiMethods) / sizeof(REALmethodDefinition),  // methodCount
    xsiEvents,                                          // events
    sizeof(xsiEvents) / sizeof(REALevent),              // eventCount
    &xsiBehavior,                                       // behaviour
    0,                                                  // forSystemUse, always zero
    NULL,                                               // eventInstances
    0,                                                  // eventInstanceCount
    NULL,                                               // interfaces
    NULL,                                               // attributes
    0,                                                  // attributeCount
    xsiConstant,                                        // constants
    sizeof(xsiConstant) / sizeof(REALconstant),         // constantCount
#if kCurrentREALControlVersion >= 11                    // since Xojo 2013R1
    NULL,                                               // sharedProperties
    0,                                                  // sharedPropertyCount
    NULL,                                               // sharedMethods
    0,                                                  // sharedMethodCount
    NULL,                                               // delegates
    0,                                                  // delegateCount
    EnumDef,                                            // enums
    sizeof(EnumDef) / sizeof(REALenum),                 // enumCount
#endif
    // end of structure
};

void registerPlugin(void)
{
    REALRegisterControl(&xsiControl);
}
