/*
    CIrrlicht - C Bindings for Irrlicht Engine

    Copyright (C) 2014- Danyal Zia (catofdanyal@yahoo.com)

    This software is provided 'as-is', without any express or
    implied warranty. In no event will the authors be held
    liable for any damages arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute
    it freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented;
       you must not claim that you wrote the original software.
       If you use this software in a product, an acknowledgment
       in the product documentation would be appreciated but
       is not required.

    2. Altered source versions must be plainly marked as such,
       and must not be misrepresented as being the original software.

    3. This notice may not be removed or altered from any
       source distribution.
*/

#ifndef _CIRRLICHT_IGUISTATICTEXT_
#define _CIRRLICHT_IGUISTATICTEXT_

#include "SColor.h"
#include "EGUIAlignment.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
    struct irr_IGUIStaticText;
    typedef struct irr_IGUIStaticText irr_IGUIStaticText;

    struct irr_IGUIFont;

    void irr_IGUIStaticText_setOverrideFont(irr_IGUIStaticText* txt, irr_IGUIFont* font=0);
	irr_IGUIFont* irr_IGUIStaticText_getOverrideFont(irr_IGUIStaticText* txt);
	irr_IGUIFont* irr_IGUIStaticText_getActiveFont(irr_IGUIStaticText* txt);
	void irr_IGUIStaticText_setOverrideColor(irr_IGUIStaticText* txt, irr_SColor col);
	irr_SColor irr_IGUIStaticText_getOverrideColor(irr_IGUIStaticText* txt);
	void irr_IGUIStaticText_enableOverrideColor(irr_IGUIStaticText* txt, bool enable);
	bool irr_IGUIStaticText_isOverrideColorEnabled(irr_IGUIStaticText* txt);
	void irr_IGUIStaticText_setBackgroundColor(irr_IGUIStaticText* txt, irr_SColor color);
	void irr_IGUIStaticText_setDrawBackground(irr_IGUIStaticText* txt, bool draw);
	bool irr_IGUIStaticText_isDrawBackgroundEnabled(irr_IGUIStaticText* txt);
	irr_SColor irr_IGUIStaticText_getBackgroundColor(irr_IGUIStaticText* txt);
	void irr_IGUIStaticText_setDrawBorder(irr_IGUIStaticText* txt, bool draw);
	bool irr_IGUIStaticText_isDrawBorderEnabled(irr_IGUIStaticText* txt);
	void irr_IGUIStaticText_setTextAlignment(irr_IGUIStaticText* txt, EGUI_ALIGNMENT horizontal, EGUI_ALIGNMENT vertical);
	void irr_IGUIStaticText_setWordWrap(irr_IGUIStaticText* txt, bool enable);
	bool irr_IGUIStaticText_isWordWrapEnabled(irr_IGUIStaticText* txt);
	int irr_IGUIStaticText_getTextHeight(irr_IGUIStaticText* txt);
	int irr_IGUIStaticText_getTextWidth(irr_IGUIStaticText* txt);
	bool irr_IGUIStaticText_isTextRestrainedInside(irr_IGUIStaticText* txt);
	void irr_IGUIStaticText_setRightToLeft(irr_IGUIStaticText* txt, bool rtl);
	bool irr_IGUIStaticText_isRightToLeft(irr_IGUIStaticText* txt);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _CIRRLICHT_GUI_
