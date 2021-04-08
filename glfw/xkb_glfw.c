//========================================================================
// GLFW 3.4 XKB - www.glfw.org
//------------------------------------------------------------------------
// Copyright (c) 2018 Kovid Goyal <kovid@kovidgoyal.net>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================


#include <string.h>
#include <stdlib.h>
#include "internal.h"
#include "xkb_glfw.h"
#ifdef _GLFW_X11
#include <X11/XKBlib.h>
#endif

#define debug(...) if (_glfw.hints.init.debugKeyboard) printf(__VA_ARGS__);

#ifdef XKB_HAS_NO_UTF32
#include "xkb-compat-shim.h"
#else
#define utf32_to_keysym xkb_utf32_to_keysym
#endif

static int
glfw_key_for_sym(xkb_keysym_t key) {
    switch(key) {
/* start xkb to glfw (auto generated by gen-key-constants.py do not edit) */
        case XKB_KEY_Escape: return GLFW_FKEY_ESCAPE;
        case XKB_KEY_Return: return GLFW_FKEY_ENTER;
        case XKB_KEY_Tab: return GLFW_FKEY_TAB;
        case XKB_KEY_BackSpace: return GLFW_FKEY_BACKSPACE;
        case XKB_KEY_Insert: return GLFW_FKEY_INSERT;
        case XKB_KEY_Delete: return GLFW_FKEY_DELETE;
        case XKB_KEY_Left: return GLFW_FKEY_LEFT;
        case XKB_KEY_Right: return GLFW_FKEY_RIGHT;
        case XKB_KEY_Up: return GLFW_FKEY_UP;
        case XKB_KEY_Down: return GLFW_FKEY_DOWN;
        case XKB_KEY_Page_Up: return GLFW_FKEY_PAGE_UP;
        case XKB_KEY_Page_Down: return GLFW_FKEY_PAGE_DOWN;
        case XKB_KEY_Home: return GLFW_FKEY_HOME;
        case XKB_KEY_End: return GLFW_FKEY_END;
        case XKB_KEY_Caps_Lock: return GLFW_FKEY_CAPS_LOCK;
        case XKB_KEY_Scroll_Lock: return GLFW_FKEY_SCROLL_LOCK;
        case XKB_KEY_Num_Lock: return GLFW_FKEY_NUM_LOCK;
        case XKB_KEY_Print: return GLFW_FKEY_PRINT_SCREEN;
        case XKB_KEY_Pause: return GLFW_FKEY_PAUSE;
        case XKB_KEY_Menu: return GLFW_FKEY_MENU;
        case XKB_KEY_F1: return GLFW_FKEY_F1;
        case XKB_KEY_F2: return GLFW_FKEY_F2;
        case XKB_KEY_F3: return GLFW_FKEY_F3;
        case XKB_KEY_F4: return GLFW_FKEY_F4;
        case XKB_KEY_F5: return GLFW_FKEY_F5;
        case XKB_KEY_F6: return GLFW_FKEY_F6;
        case XKB_KEY_F7: return GLFW_FKEY_F7;
        case XKB_KEY_F8: return GLFW_FKEY_F8;
        case XKB_KEY_F9: return GLFW_FKEY_F9;
        case XKB_KEY_F10: return GLFW_FKEY_F10;
        case XKB_KEY_F11: return GLFW_FKEY_F11;
        case XKB_KEY_F12: return GLFW_FKEY_F12;
        case XKB_KEY_F13: return GLFW_FKEY_F13;
        case XKB_KEY_F14: return GLFW_FKEY_F14;
        case XKB_KEY_F15: return GLFW_FKEY_F15;
        case XKB_KEY_F16: return GLFW_FKEY_F16;
        case XKB_KEY_F17: return GLFW_FKEY_F17;
        case XKB_KEY_F18: return GLFW_FKEY_F18;
        case XKB_KEY_F19: return GLFW_FKEY_F19;
        case XKB_KEY_F20: return GLFW_FKEY_F20;
        case XKB_KEY_F21: return GLFW_FKEY_F21;
        case XKB_KEY_F22: return GLFW_FKEY_F22;
        case XKB_KEY_F23: return GLFW_FKEY_F23;
        case XKB_KEY_F24: return GLFW_FKEY_F24;
        case XKB_KEY_F25: return GLFW_FKEY_F25;
        case XKB_KEY_F26: return GLFW_FKEY_F26;
        case XKB_KEY_F27: return GLFW_FKEY_F27;
        case XKB_KEY_F28: return GLFW_FKEY_F28;
        case XKB_KEY_F29: return GLFW_FKEY_F29;
        case XKB_KEY_F30: return GLFW_FKEY_F30;
        case XKB_KEY_F31: return GLFW_FKEY_F31;
        case XKB_KEY_F32: return GLFW_FKEY_F32;
        case XKB_KEY_F33: return GLFW_FKEY_F33;
        case XKB_KEY_F34: return GLFW_FKEY_F34;
        case XKB_KEY_F35: return GLFW_FKEY_F35;
        case XKB_KEY_KP_0: return GLFW_FKEY_KP_0;
        case XKB_KEY_KP_1: return GLFW_FKEY_KP_1;
        case XKB_KEY_KP_2: return GLFW_FKEY_KP_2;
        case XKB_KEY_KP_3: return GLFW_FKEY_KP_3;
        case XKB_KEY_KP_4: return GLFW_FKEY_KP_4;
        case XKB_KEY_KP_5: return GLFW_FKEY_KP_5;
        case XKB_KEY_KP_6: return GLFW_FKEY_KP_6;
        case XKB_KEY_KP_7: return GLFW_FKEY_KP_7;
        case XKB_KEY_KP_8: return GLFW_FKEY_KP_8;
        case XKB_KEY_KP_9: return GLFW_FKEY_KP_9;
        case XKB_KEY_KP_Decimal: return GLFW_FKEY_KP_DECIMAL;
        case XKB_KEY_KP_Divide: return GLFW_FKEY_KP_DIVIDE;
        case XKB_KEY_KP_Multiply: return GLFW_FKEY_KP_MULTIPLY;
        case XKB_KEY_KP_Subtract: return GLFW_FKEY_KP_SUBTRACT;
        case XKB_KEY_KP_Add: return GLFW_FKEY_KP_ADD;
        case XKB_KEY_KP_Enter: return GLFW_FKEY_KP_ENTER;
        case XKB_KEY_KP_Equal: return GLFW_FKEY_KP_EQUAL;
        case XKB_KEY_KP_Separator: return GLFW_FKEY_KP_SEPARATOR;
        case XKB_KEY_KP_Left: return GLFW_FKEY_KP_LEFT;
        case XKB_KEY_KP_Right: return GLFW_FKEY_KP_RIGHT;
        case XKB_KEY_KP_Up: return GLFW_FKEY_KP_UP;
        case XKB_KEY_KP_Down: return GLFW_FKEY_KP_DOWN;
        case XKB_KEY_KP_Page_Up: return GLFW_FKEY_KP_PAGE_UP;
        case XKB_KEY_KP_Page_Down: return GLFW_FKEY_KP_PAGE_DOWN;
        case XKB_KEY_KP_Home: return GLFW_FKEY_KP_HOME;
        case XKB_KEY_KP_End: return GLFW_FKEY_KP_END;
        case XKB_KEY_KP_Insert: return GLFW_FKEY_KP_INSERT;
        case XKB_KEY_KP_Delete: return GLFW_FKEY_KP_DELETE;
        case XKB_KEY_XF86AudioPlay: return GLFW_FKEY_MEDIA_PLAY;
        case XKB_KEY_XF86AudioPause: return GLFW_FKEY_MEDIA_PAUSE;
        case XKB_KEY_XF86AudioStop: return GLFW_FKEY_MEDIA_STOP;
        case XKB_KEY_XF86AudioForward: return GLFW_FKEY_MEDIA_FAST_FORWARD;
        case XKB_KEY_XF86AudioRewind: return GLFW_FKEY_MEDIA_REWIND;
        case XKB_KEY_XF86AudioNext: return GLFW_FKEY_MEDIA_TRACK_NEXT;
        case XKB_KEY_XF86AudioPrev: return GLFW_FKEY_MEDIA_TRACK_PREVIOUS;
        case XKB_KEY_XF86AudioRecord: return GLFW_FKEY_MEDIA_RECORD;
        case XKB_KEY_XF86AudioLowerVolume: return GLFW_FKEY_LOWER_VOLUME;
        case XKB_KEY_XF86AudioRaiseVolume: return GLFW_FKEY_RAISE_VOLUME;
        case XKB_KEY_XF86AudioMute: return GLFW_FKEY_MUTE_VOLUME;
        case XKB_KEY_Shift_L: return GLFW_FKEY_LEFT_SHIFT;
        case XKB_KEY_Control_L: return GLFW_FKEY_LEFT_CONTROL;
        case XKB_KEY_Alt_L: return GLFW_FKEY_LEFT_ALT;
        case XKB_KEY_Super_L: return GLFW_FKEY_LEFT_SUPER;
        case XKB_KEY_Hyper_L: return GLFW_FKEY_LEFT_HYPER;
        case XKB_KEY_Meta_L: return GLFW_FKEY_LEFT_META;
        case XKB_KEY_Shift_R: return GLFW_FKEY_RIGHT_SHIFT;
        case XKB_KEY_Control_R: return GLFW_FKEY_RIGHT_CONTROL;
        case XKB_KEY_Alt_R: return GLFW_FKEY_RIGHT_ALT;
        case XKB_KEY_Super_R: return GLFW_FKEY_RIGHT_SUPER;
        case XKB_KEY_Hyper_R: return GLFW_FKEY_RIGHT_HYPER;
        case XKB_KEY_Meta_R: return GLFW_FKEY_RIGHT_META;
        case XKB_KEY_ISO_Level3_Shift: return GLFW_FKEY_ISO_LEVEL3_SHIFT;
        case XKB_KEY_ISO_Level5_Shift: return GLFW_FKEY_ISO_LEVEL5_SHIFT;
/* end xkb to glfw */
        default:
            return xkb_keysym_to_utf32(key);
    }
}

xkb_keysym_t
glfw_xkb_sym_for_key(uint32_t key) {
    switch(key) {
/* start glfw to xkb (auto generated by gen-key-constants.py do not edit) */
        case GLFW_FKEY_ESCAPE: return XKB_KEY_Escape;
        case GLFW_FKEY_ENTER: return XKB_KEY_Return;
        case GLFW_FKEY_TAB: return XKB_KEY_Tab;
        case GLFW_FKEY_BACKSPACE: return XKB_KEY_BackSpace;
        case GLFW_FKEY_INSERT: return XKB_KEY_Insert;
        case GLFW_FKEY_DELETE: return XKB_KEY_Delete;
        case GLFW_FKEY_LEFT: return XKB_KEY_Left;
        case GLFW_FKEY_RIGHT: return XKB_KEY_Right;
        case GLFW_FKEY_UP: return XKB_KEY_Up;
        case GLFW_FKEY_DOWN: return XKB_KEY_Down;
        case GLFW_FKEY_PAGE_UP: return XKB_KEY_Page_Up;
        case GLFW_FKEY_PAGE_DOWN: return XKB_KEY_Page_Down;
        case GLFW_FKEY_HOME: return XKB_KEY_Home;
        case GLFW_FKEY_END: return XKB_KEY_End;
        case GLFW_FKEY_CAPS_LOCK: return XKB_KEY_Caps_Lock;
        case GLFW_FKEY_SCROLL_LOCK: return XKB_KEY_Scroll_Lock;
        case GLFW_FKEY_NUM_LOCK: return XKB_KEY_Num_Lock;
        case GLFW_FKEY_PRINT_SCREEN: return XKB_KEY_Print;
        case GLFW_FKEY_PAUSE: return XKB_KEY_Pause;
        case GLFW_FKEY_MENU: return XKB_KEY_Menu;
        case GLFW_FKEY_F1: return XKB_KEY_F1;
        case GLFW_FKEY_F2: return XKB_KEY_F2;
        case GLFW_FKEY_F3: return XKB_KEY_F3;
        case GLFW_FKEY_F4: return XKB_KEY_F4;
        case GLFW_FKEY_F5: return XKB_KEY_F5;
        case GLFW_FKEY_F6: return XKB_KEY_F6;
        case GLFW_FKEY_F7: return XKB_KEY_F7;
        case GLFW_FKEY_F8: return XKB_KEY_F8;
        case GLFW_FKEY_F9: return XKB_KEY_F9;
        case GLFW_FKEY_F10: return XKB_KEY_F10;
        case GLFW_FKEY_F11: return XKB_KEY_F11;
        case GLFW_FKEY_F12: return XKB_KEY_F12;
        case GLFW_FKEY_F13: return XKB_KEY_F13;
        case GLFW_FKEY_F14: return XKB_KEY_F14;
        case GLFW_FKEY_F15: return XKB_KEY_F15;
        case GLFW_FKEY_F16: return XKB_KEY_F16;
        case GLFW_FKEY_F17: return XKB_KEY_F17;
        case GLFW_FKEY_F18: return XKB_KEY_F18;
        case GLFW_FKEY_F19: return XKB_KEY_F19;
        case GLFW_FKEY_F20: return XKB_KEY_F20;
        case GLFW_FKEY_F21: return XKB_KEY_F21;
        case GLFW_FKEY_F22: return XKB_KEY_F22;
        case GLFW_FKEY_F23: return XKB_KEY_F23;
        case GLFW_FKEY_F24: return XKB_KEY_F24;
        case GLFW_FKEY_F25: return XKB_KEY_F25;
        case GLFW_FKEY_F26: return XKB_KEY_F26;
        case GLFW_FKEY_F27: return XKB_KEY_F27;
        case GLFW_FKEY_F28: return XKB_KEY_F28;
        case GLFW_FKEY_F29: return XKB_KEY_F29;
        case GLFW_FKEY_F30: return XKB_KEY_F30;
        case GLFW_FKEY_F31: return XKB_KEY_F31;
        case GLFW_FKEY_F32: return XKB_KEY_F32;
        case GLFW_FKEY_F33: return XKB_KEY_F33;
        case GLFW_FKEY_F34: return XKB_KEY_F34;
        case GLFW_FKEY_F35: return XKB_KEY_F35;
        case GLFW_FKEY_KP_0: return XKB_KEY_KP_0;
        case GLFW_FKEY_KP_1: return XKB_KEY_KP_1;
        case GLFW_FKEY_KP_2: return XKB_KEY_KP_2;
        case GLFW_FKEY_KP_3: return XKB_KEY_KP_3;
        case GLFW_FKEY_KP_4: return XKB_KEY_KP_4;
        case GLFW_FKEY_KP_5: return XKB_KEY_KP_5;
        case GLFW_FKEY_KP_6: return XKB_KEY_KP_6;
        case GLFW_FKEY_KP_7: return XKB_KEY_KP_7;
        case GLFW_FKEY_KP_8: return XKB_KEY_KP_8;
        case GLFW_FKEY_KP_9: return XKB_KEY_KP_9;
        case GLFW_FKEY_KP_DECIMAL: return XKB_KEY_KP_Decimal;
        case GLFW_FKEY_KP_DIVIDE: return XKB_KEY_KP_Divide;
        case GLFW_FKEY_KP_MULTIPLY: return XKB_KEY_KP_Multiply;
        case GLFW_FKEY_KP_SUBTRACT: return XKB_KEY_KP_Subtract;
        case GLFW_FKEY_KP_ADD: return XKB_KEY_KP_Add;
        case GLFW_FKEY_KP_ENTER: return XKB_KEY_KP_Enter;
        case GLFW_FKEY_KP_EQUAL: return XKB_KEY_KP_Equal;
        case GLFW_FKEY_KP_SEPARATOR: return XKB_KEY_KP_Separator;
        case GLFW_FKEY_KP_LEFT: return XKB_KEY_KP_Left;
        case GLFW_FKEY_KP_RIGHT: return XKB_KEY_KP_Right;
        case GLFW_FKEY_KP_UP: return XKB_KEY_KP_Up;
        case GLFW_FKEY_KP_DOWN: return XKB_KEY_KP_Down;
        case GLFW_FKEY_KP_PAGE_UP: return XKB_KEY_KP_Page_Up;
        case GLFW_FKEY_KP_PAGE_DOWN: return XKB_KEY_KP_Page_Down;
        case GLFW_FKEY_KP_HOME: return XKB_KEY_KP_Home;
        case GLFW_FKEY_KP_END: return XKB_KEY_KP_End;
        case GLFW_FKEY_KP_INSERT: return XKB_KEY_KP_Insert;
        case GLFW_FKEY_KP_DELETE: return XKB_KEY_KP_Delete;
        case GLFW_FKEY_MEDIA_PLAY: return XKB_KEY_XF86AudioPlay;
        case GLFW_FKEY_MEDIA_PAUSE: return XKB_KEY_XF86AudioPause;
        case GLFW_FKEY_MEDIA_STOP: return XKB_KEY_XF86AudioStop;
        case GLFW_FKEY_MEDIA_FAST_FORWARD: return XKB_KEY_XF86AudioForward;
        case GLFW_FKEY_MEDIA_REWIND: return XKB_KEY_XF86AudioRewind;
        case GLFW_FKEY_MEDIA_TRACK_NEXT: return XKB_KEY_XF86AudioNext;
        case GLFW_FKEY_MEDIA_TRACK_PREVIOUS: return XKB_KEY_XF86AudioPrev;
        case GLFW_FKEY_MEDIA_RECORD: return XKB_KEY_XF86AudioRecord;
        case GLFW_FKEY_LOWER_VOLUME: return XKB_KEY_XF86AudioLowerVolume;
        case GLFW_FKEY_RAISE_VOLUME: return XKB_KEY_XF86AudioRaiseVolume;
        case GLFW_FKEY_MUTE_VOLUME: return XKB_KEY_XF86AudioMute;
        case GLFW_FKEY_LEFT_SHIFT: return XKB_KEY_Shift_L;
        case GLFW_FKEY_LEFT_CONTROL: return XKB_KEY_Control_L;
        case GLFW_FKEY_LEFT_ALT: return XKB_KEY_Alt_L;
        case GLFW_FKEY_LEFT_SUPER: return XKB_KEY_Super_L;
        case GLFW_FKEY_LEFT_HYPER: return XKB_KEY_Hyper_L;
        case GLFW_FKEY_LEFT_META: return XKB_KEY_Meta_L;
        case GLFW_FKEY_RIGHT_SHIFT: return XKB_KEY_Shift_R;
        case GLFW_FKEY_RIGHT_CONTROL: return XKB_KEY_Control_R;
        case GLFW_FKEY_RIGHT_ALT: return XKB_KEY_Alt_R;
        case GLFW_FKEY_RIGHT_SUPER: return XKB_KEY_Super_R;
        case GLFW_FKEY_RIGHT_HYPER: return XKB_KEY_Hyper_R;
        case GLFW_FKEY_RIGHT_META: return XKB_KEY_Meta_R;
        case GLFW_FKEY_ISO_LEVEL3_SHIFT: return XKB_KEY_ISO_Level3_Shift;
        case GLFW_FKEY_ISO_LEVEL5_SHIFT: return XKB_KEY_ISO_Level5_Shift;
/* end glfw to xkb */
        default:
            return utf32_to_keysym(key);
    }
}

#ifdef _GLFW_X11

bool
glfw_xkb_set_x11_events_mask(void) {
    if (!XkbSelectEvents(_glfw.x11.display, XkbUseCoreKbd, XkbNewKeyboardNotifyMask | XkbMapNotifyMask | XkbStateNotifyMask, XkbNewKeyboardNotifyMask | XkbMapNotifyMask | XkbStateNotifyMask)) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "Failed to set XKB events mask");
        return false;
    }
    return true;
}

bool
glfw_xkb_update_x11_keyboard_id(_GLFWXKBData *xkb) {
    xkb->keyboard_device_id = -1;
    xcb_connection_t* conn = XGetXCBConnection(_glfw.x11.display);
    if (!conn) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "X11: Failed to retrieve XCB connection");
        return false;
    }

    xkb->keyboard_device_id = xkb_x11_get_core_keyboard_device_id(conn);
    if (xkb->keyboard_device_id == -1) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "X11: Failed to retrieve core keyboard device id");
        return false;
    }
    return true;
}

#define xkb_glfw_load_keymap(keymap, ...) {\
    xcb_connection_t* conn = XGetXCBConnection(_glfw.x11.display); \
    if (conn) keymap = xkb_x11_keymap_new_from_device(xkb->context, conn, xkb->keyboard_device_id, XKB_KEYMAP_COMPILE_NO_FLAGS); \
}

#define xkb_glfw_load_state(keymap, state) {\
    xcb_connection_t* conn = XGetXCBConnection(_glfw.x11.display); \
    if (conn) state = xkb_x11_state_new_from_device(keymap, conn, xkb->keyboard_device_id); \
}

static void
glfw_xkb_update_masks(_GLFWXKBData *xkb) {
    // See https://github.com/kovidgoyal/kitty/pull/3430 for discussion
    bool succeeded = false;
    unsigned used_bits = 0; /* To avoid using the same bit twice */
    XkbDescPtr xkb_ptr = XkbGetMap( _glfw.x11.display, XkbVirtualModsMask | XkbVirtualModMapMask, XkbUseCoreKbd );

#define S( a ) xkb->a##Idx = XKB_MOD_INVALID; xkb->a##Mask = 0
    S(control); S(alt); S(shift); S(super); S(hyper); S(meta); S(capsLock); S(numLock);
#undef S
    if (xkb_ptr) {
        Status status = XkbGetNames(_glfw.x11.display, XkbVirtualModNamesMask, xkb_ptr);
        if (status == Success) {
            for (int indx = 0; indx < XkbNumVirtualMods; ++indx) {
                Atom atom = xkb_ptr->names->vmods[indx];
                if (atom) {
                    unsigned mask_rtn = 0;
                    if (XkbVirtualModsToReal( xkb_ptr, 1<<indx, &mask_rtn) ) {
                        const char *name = XGetAtomName(_glfw.x11.display, atom);
#define S( a, s ) if (!(used_bits & mask_rtn) && strcmp(name, #s) == 0) xkb->a##Mask = mask_rtn, used_bits |= mask_rtn
                        /* Note that the order matters here; earlier is higher priority. */
                        S(alt, Alt);
                        S(super, Super);
                        S(numLock, NumLock);
                        S(meta, Meta);
                        S(hyper, Hyper);
#undef S
                    }
                }
            }
            succeeded = true;
        }
        XkbFreeNames(xkb_ptr, XkbVirtualModNamesMask, True);
        XkbFreeKeyboard(xkb_ptr, 0, True);
    }
    if (succeeded) {
        unsigned indx, shifted;
        for (indx = 0, shifted = 1; used_bits; ++indx, shifted <<= 1, used_bits >>= 1) {
#define S( a ) if ( ( xkb->a##Mask & shifted ) == shifted ) xkb->a##Idx = indx
            S(alt); S(super); S(hyper); S(meta); S(numLock);
#undef S
        }
    }
#define S(a, n) xkb->a##Idx = xkb_keymap_mod_get_index(xkb->keymap, n); xkb->a##Mask = 1 << xkb->a##Idx;
    S(control, XKB_MOD_NAME_CTRL);
    S(shift, XKB_MOD_NAME_SHIFT);
    S(capsLock, XKB_MOD_NAME_CAPS);
    if (!succeeded) {
        S(numLock, XKB_MOD_NAME_NUM);
        S(alt, XKB_MOD_NAME_ALT);
        S(super, XKB_MOD_NAME_LOGO);
    }
#undef S
    debug("Modifier indices alt:%u super:%u hyper:%u meta:%u numlock:%u\n",
            xkb->altIdx, xkb->superIdx, xkb->hyperIdx, xkb->metaIdx, xkb->numLockIdx);
}


#else

#define xkb_glfw_load_keymap(keymap, map_str) keymap = xkb_keymap_new_from_string(xkb->context, map_str, XKB_KEYMAP_FORMAT_TEXT_V1, 0);
#define xkb_glfw_load_state(keymap, state) state = xkb_state_new(keymap);

static void
glfw_xkb_update_masks(_GLFWXKBData *xkb) {
    // Should find better solution under Wayland
    // See https://github.com/kovidgoyal/kitty/pull/3430 for discussion

#define S( a ) xkb->a##Idx = XKB_MOD_INVALID; xkb->a##Mask = 0
    S(hyper); S(meta);
#undef S
#define S(a, n) xkb->a##Idx = xkb_keymap_mod_get_index(xkb->keymap, n); xkb->a##Mask = 1 << xkb->a##Idx;
    S(control, XKB_MOD_NAME_CTRL);
    S(shift, XKB_MOD_NAME_SHIFT);
    S(capsLock, XKB_MOD_NAME_CAPS);
    S(numLock, XKB_MOD_NAME_NUM);
    S(alt, XKB_MOD_NAME_ALT);
    S(super, XKB_MOD_NAME_LOGO);
#undef S
}

#endif

static void
release_keyboard_data(_GLFWXKBData *xkb) {
#define US(group, state, unref) if (xkb->group.state) {  unref(xkb->group.state); xkb->group.state = NULL; }
#define UK(keymap) if(xkb->keymap) { xkb_keymap_unref(xkb->keymap); xkb->keymap = NULL; }
    US(states, composeState, xkb_compose_state_unref);
    UK(keymap);
    UK(default_keymap);
    US(states, state, xkb_state_unref);
    US(states, clean_state, xkb_state_unref);
    US(states, default_state, xkb_state_unref);
#undef US
#undef UK

}

void
glfw_xkb_release(_GLFWXKBData *xkb) {
    release_keyboard_data(xkb);
    if (xkb->context) {
        xkb_context_unref(xkb->context);
        xkb->context = NULL;
    }
    glfw_ibus_terminate(&xkb->ibus);
}

bool
glfw_xkb_create_context(_GLFWXKBData *xkb) {
    xkb->context = xkb_context_new(0);
    if (!xkb->context)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Failed to initialize XKB context");
        return false;
    }
#ifndef _GLFW_WAYLAND
    glfw_connect_to_ibus(&xkb->ibus);
#endif
    return true;
}

static const char*
load_keymaps(_GLFWXKBData *xkb, const char *map_str) {
    (void)(map_str);  // not needed on X11
    xkb_glfw_load_keymap(xkb->keymap, map_str);
    if (!xkb->keymap) return "Failed to compile XKB keymap";
    // The system default keymap, can be overridden by the XKB_DEFAULT_RULES
    // env var, see
    // https://xkbcommon.org/doc/current/structxkb__rule__names.html
    static struct xkb_rule_names default_rule_names = {0};
    xkb->default_keymap = xkb_keymap_new_from_names(xkb->context, &default_rule_names, XKB_KEYMAP_COMPILE_NO_FLAGS);
    if (!xkb->default_keymap) return "Failed to create default XKB keymap";
    return NULL;
}

static const char*
load_states(_GLFWXKBData *xkb) {
    xkb_glfw_load_state(xkb->keymap, xkb->states.state);
    xkb->states.clean_state = xkb_state_new(xkb->keymap);
    xkb->states.default_state = xkb_state_new(xkb->default_keymap);
    if (!xkb->states.state || !xkb->states.clean_state || !xkb->states.default_state) return "Failed to create XKB state";
    return NULL;
}

static void
load_compose_tables(_GLFWXKBData *xkb) {
    /* Look up the preferred locale, falling back to "C" as default. */
    struct xkb_compose_table* compose_table = NULL;
    const char *locale = getenv("LC_ALL");
    if (!locale) locale = getenv("LC_CTYPE");
    if (!locale) locale = getenv("LANG");
    if (!locale) locale = "C";

    // See https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=903373
    if (strcmp(locale, "en_IN") == 0) locale = "en_IN.UTF-8";

    compose_table = xkb_compose_table_new_from_locale(xkb->context, locale, XKB_COMPOSE_COMPILE_NO_FLAGS);
    if (!compose_table) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "Failed to create XKB compose table for locale %s", locale);
        return;
    }
    xkb->states.composeState = xkb_compose_state_new(compose_table, XKB_COMPOSE_STATE_NO_FLAGS);
    if (!xkb->states.composeState) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "Failed to create XKB compose state");
    }
    xkb_compose_table_unref(compose_table);
}

static inline xkb_mod_mask_t
active_unknown_modifiers(_GLFWXKBData *xkb, struct xkb_state *state) {
    size_t i = 0;
    xkb_mod_mask_t ans = 0;
    while (xkb->unknownModifiers[i] != XKB_MOD_INVALID) {
        if (xkb_state_mod_index_is_active(state, xkb->unknownModifiers[i], XKB_STATE_MODS_EFFECTIVE)) ans |= (1 << xkb->unknownModifiers[i]);
        i++;
    }
    return ans;
}

static unsigned int
update_one_modifier(XKBStateGroup *group, xkb_mod_mask_t mask,
                    xkb_mod_index_t idx, unsigned int mod) {
    if ( idx == XKB_MOD_INVALID )
        return 0;
    /* Optimization in the case of a single real modifier */
    if ( mask && ( ( mask & ( mask-1 ) ) == 0 ) )
        return (xkb_state_mod_index_is_active(group->state, idx, XKB_STATE_MODS_EFFECTIVE) == 1) ? mod : 0;
    /* Multiple real mods map to the same virtual mod */
    for ( unsigned indx = 0; indx < 32 && mask; ++indx, mask >>= 1 )
        if ( ( mask & 1 ) && xkb_state_mod_index_is_active(group->state, indx, XKB_STATE_MODS_EFFECTIVE) == 1)
            return mod;
    return 0;
}

static void
update_modifiers(_GLFWXKBData *xkb) {
    XKBStateGroup *group = &xkb->states;
#define S(attr, name) group->modifiers |= update_one_modifier( group, xkb->attr##Mask, xkb->attr##Idx, GLFW_MOD_##name )
    S(control, CONTROL); S(alt, ALT); S(shift, SHIFT); S(super, SUPER); S(hyper, HYPER); S(meta, META); S(capsLock, CAPS_LOCK); S(numLock, NUM_LOCK);
#undef S
    xkb->states.activeUnknownModifiers = active_unknown_modifiers(xkb, xkb->states.state);

}

bool
glfw_xkb_compile_keymap(_GLFWXKBData *xkb, const char *map_str) {
    const char *err;
    debug("Loading new XKB keymaps\n");
    release_keyboard_data(xkb);
    err = load_keymaps(xkb, map_str);
    if (err) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "%s", err);
        release_keyboard_data(xkb);
        return false;
    }
    err = load_states(xkb);
    if (err) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "%s", err);
        release_keyboard_data(xkb);
        return false;
    }
    load_compose_tables(xkb);

    glfw_xkb_update_masks(xkb);
    size_t capacity = arraysz(xkb->unknownModifiers), j = 0;
    for (xkb_mod_index_t i = 0; i < capacity; i++) xkb->unknownModifiers[i] = XKB_MOD_INVALID;
    for (xkb_mod_index_t i = 0; i < xkb_keymap_num_mods(xkb->keymap) && j < capacity - 1; i++) {
        if (i != xkb->controlIdx && i != xkb->altIdx && i != xkb->shiftIdx && i != xkb->superIdx && i != xkb->hyperIdx && i != xkb->metaIdx && i != xkb->capsLockIdx && i != xkb->numLockIdx) xkb->unknownModifiers[j++] = i;
    }
    xkb->states.modifiers = 0;
    xkb->states.activeUnknownModifiers = 0;
    update_modifiers(xkb);
    return true;
}

void
glfw_xkb_update_modifiers(_GLFWXKBData *xkb, xkb_mod_mask_t depressed, xkb_mod_mask_t latched, xkb_mod_mask_t locked, xkb_layout_index_t base_group, xkb_layout_index_t latched_group, xkb_layout_index_t locked_group) {
    if (!xkb->keymap) return;
    xkb->states.modifiers = 0;
    xkb_state_update_mask(xkb->states.state, depressed, latched, locked, base_group, latched_group, locked_group);
    // We have to update the groups in clean_state, as they change for
    // different keyboard layouts, see https://github.com/kovidgoyal/kitty/issues/488
    xkb_state_update_mask(xkb->states.clean_state, 0, 0, 0, base_group, latched_group, locked_group);
    update_modifiers(xkb);
}

bool
glfw_xkb_should_repeat(_GLFWXKBData *xkb, xkb_keycode_t keycode) {
#ifdef _GLFW_WAYLAND
    keycode += 8;
#endif
    return xkb_keymap_key_repeats(xkb->keymap, keycode);
}


static inline xkb_keysym_t
compose_symbol(struct xkb_compose_state *composeState, xkb_keysym_t sym, int *compose_completed, char *key_text, int n) {
    *compose_completed = 0;
    if (sym == XKB_KEY_NoSymbol || !composeState) return sym;
    if (xkb_compose_state_feed(composeState, sym) != XKB_COMPOSE_FEED_ACCEPTED) return sym;
    switch (xkb_compose_state_get_status(composeState)) {
        case XKB_COMPOSE_COMPOSED:
            xkb_compose_state_get_utf8(composeState, key_text, n);
            *compose_completed = 1;
            return xkb_compose_state_get_one_sym(composeState);
        case XKB_COMPOSE_COMPOSING:
        case XKB_COMPOSE_CANCELLED:
            return XKB_KEY_NoSymbol;
        case XKB_COMPOSE_NOTHING:
        default:
            return sym;
    }
}


const char*
glfw_xkb_keysym_name(xkb_keysym_t sym) {
    static char name[256];
    name[0] = 0;
    xkb_keysym_get_name(sym, name, sizeof(name));
    return name;
}

int
glfw_xkb_keysym_from_name(const char *name, bool case_sensitive) {
    return (int)xkb_keysym_from_name(name, case_sensitive ? XKB_KEYSYM_NO_FLAGS : XKB_KEYSYM_CASE_INSENSITIVE);
}

static inline const char*
format_mods(unsigned int mods) {
    static char buf[128];
    char *p = buf, *s;
#define pr(x) p += snprintf(p, sizeof(buf) - (p - buf) - 1, "%s", x)
    pr("mods: ");
    s = p;
    if (mods & GLFW_MOD_CONTROL) pr("ctrl+");
    if (mods & GLFW_MOD_ALT) pr("alt+");
    if (mods & GLFW_MOD_SHIFT) pr("shift+");
    if (mods & GLFW_MOD_SUPER) pr("super+");
    if (mods & GLFW_MOD_META) pr("meta+");
    if (mods & GLFW_MOD_HYPER) pr("hyper+");
    if (mods & GLFW_MOD_CAPS_LOCK) pr("capslock+");
    if (mods & GLFW_MOD_NUM_LOCK) pr("numlock+");
    if (p == s) pr("none");
    else p--;
    pr(" ");
#undef pr
    return buf;
}

static inline const char*
format_xkb_mods(_GLFWXKBData *xkb, const char* name, xkb_mod_mask_t mods) {
    static char buf[512];
    char *p = buf, *s;
#define pr(x) { \
    int num_needed = -1; \
    ssize_t space_left = sizeof(buf) - (p - buf) - 1; \
    if (space_left > 0) num_needed = snprintf(p, space_left, "%s", x);  \
    if (num_needed > 0) p += num_needed; \
}
    pr(name); pr(": ");
    s = p;
    for (xkb_mod_index_t i = 0; i < xkb_keymap_num_mods(xkb->keymap); i++) {
        xkb_mod_mask_t m = 1 << i;
        if (m & mods) { pr(xkb_keymap_mod_get_name(xkb->keymap, i)); pr("+"); }
    }
    if (p == s) { pr("none"); }
    else p--;
    pr(" ");
#undef pr
    return buf;
}

void
glfw_xkb_update_ime_state(_GLFWwindow *w, _GLFWXKBData *xkb, const GLFWIMEUpdateEvent *ev) {
    int x = 0, y = 0;
    switch(ev->type) {
        case GLFW_IME_UPDATE_FOCUS:
            glfw_ibus_set_focused(&xkb->ibus, ev->focused);
            break;
        case GLFW_IME_UPDATE_CURSOR_POSITION:
            _glfwPlatformGetWindowPos(w, &x, &y);
            x += ev->cursor.left; y += ev->cursor.top;
            glfw_ibus_set_cursor_geometry(&xkb->ibus, x, y, ev->cursor.width, ev->cursor.height);
            break;
    }
}

void
glfw_xkb_key_from_ime(_GLFWIBUSKeyEvent *ev, bool handled_by_ime, bool failed) {
    _GLFWwindow *window = _glfwWindowForId(ev->window_id);
    if (failed && window && window->callbacks.keyboard) {
        // notify application to remove any existing pre-edit text
        GLFWkeyevent fake_ev = {.action = GLFW_PRESS};
        fake_ev.ime_state = GLFW_IME_PREEDIT_CHANGED;
        window->callbacks.keyboard((GLFWwindow*) window, &fake_ev);
    }
    static xkb_keycode_t last_handled_press_keycode = 0;
    // We filter out release events that correspond to the last press event
    // handled by the IME system. This won't fix the case of multiple key
    // presses before a release, but is better than nothing. For that case
    // you'd need to implement a ring buffer to store pending key presses.
    xkb_keycode_t prev_handled_press = last_handled_press_keycode;
    last_handled_press_keycode = 0;
    bool is_release = ev->glfw_ev.action == GLFW_RELEASE;
    debug("From IBUS: native_key: 0x%x name: %s is_release: %d\n", ev->glfw_ev.native_key, glfw_xkb_keysym_name(ev->glfw_ev.key), is_release);
    if (window && !handled_by_ime && !(is_release && ev->glfw_ev.native_key == (int) prev_handled_press)) {
        debug("↳ to application: glfw_keycode: 0x%x (%s) keysym: 0x%x (%s) action: %s %s text: %s\n",
            ev->glfw_ev.native_key, _glfwGetKeyName(ev->glfw_ev.native_key), ev->glfw_ev.key, glfw_xkb_keysym_name(ev->glfw_ev.key),
            (ev->glfw_ev.action == GLFW_RELEASE ? "RELEASE" : (ev->glfw_ev.action == GLFW_PRESS ? "PRESS" : "REPEAT")),
            format_mods(ev->glfw_ev.mods), ev->glfw_ev.text
        );

        ev->glfw_ev.ime_state = GLFW_IME_NONE;
        _glfwInputKeyboard(window, &ev->glfw_ev);
    } else debug("↳ discarded\n");
    if (!is_release && handled_by_ime)
      last_handled_press_keycode = ev->glfw_ev.native_key;
}

void
glfw_xkb_handle_key_event(_GLFWwindow *window, _GLFWXKBData *xkb, xkb_keycode_t xkb_keycode, int action) {
    static char key_text[64] = {0};
    const xkb_keysym_t *syms, *clean_syms, *default_syms;
    xkb_keysym_t xkb_sym, shifted_xkb_sym = XKB_KEY_NoSymbol, alternate_xkb_sym = XKB_KEY_NoSymbol;
    xkb_keycode_t code_for_sym = xkb_keycode, ibus_keycode = xkb_keycode;
    GLFWkeyevent glfw_ev = {.action = GLFW_PRESS};
#ifdef _GLFW_WAYLAND
    code_for_sym += 8;
#else
    ibus_keycode -= 8;
#endif
    debug("%s xkb_keycode: 0x%x ", action == GLFW_RELEASE ? "Release" : "Press", xkb_keycode);
    XKBStateGroup *sg = &xkb->states;
    int num_syms = xkb_state_key_get_syms(sg->state, code_for_sym, &syms);
    int num_clean_syms = xkb_state_key_get_syms(sg->clean_state, code_for_sym, &clean_syms);
    key_text[0] = 0;
    // According to the documentation of xkb_compose_state_feed it does not
    // support multi-sym events, so we ignore them
    if (num_syms != 1 || num_clean_syms != 1) {
        debug("num_syms: %d num_clean_syms: %d ignoring event\n", num_syms, num_clean_syms);
        return;
    }
    xkb_sym = clean_syms[0];
    shifted_xkb_sym = syms[0];
    debug("clean_sym: %s ", glfw_xkb_keysym_name(clean_syms[0]));
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        const char *text_type = "composed_text";
        int compose_completed;
        xkb_sym = compose_symbol(sg->composeState, syms[0], &compose_completed, key_text, sizeof(key_text));
        if (xkb_sym == XKB_KEY_NoSymbol && !compose_completed) {
            debug("compose not complete, ignoring.\n");
            return;
        }
        debug("composed_sym: %s ", glfw_xkb_keysym_name(xkb_sym));
        if (xkb_sym == syms[0]) { // composed sym is the same as non-composed sym
            // Only use the clean_sym if no mods other than the mods we report
            // are active (for example if ISO_Shift_Level_* mods are active
            // they are not reported by GLFW so the key should be the shifted
            // key). See https://github.com/kovidgoyal/kitty/issues/171#issuecomment-377557053
            xkb_mod_mask_t consumed_unknown_mods = xkb_state_key_get_consumed_mods(sg->state, code_for_sym) & sg->activeUnknownModifiers;
            if (sg->activeUnknownModifiers) debug("%s", format_xkb_mods(xkb, "active_unknown_mods", sg->activeUnknownModifiers));
            if (consumed_unknown_mods) { debug("%s", format_xkb_mods(xkb, "consumed_unknown_mods", consumed_unknown_mods)); }
            else xkb_sym = clean_syms[0];
            // xkb returns text even if alt and/or super are pressed
            if ( ((GLFW_MOD_CONTROL | GLFW_MOD_ALT | GLFW_MOD_SUPER | GLFW_MOD_HYPER | GLFW_MOD_META) & sg->modifiers) == 0) {
              xkb_state_key_get_utf8(sg->state, code_for_sym, key_text, sizeof(key_text));
            }
            text_type = "text";
        }
        if ((1 <= key_text[0] && key_text[0] <= 31) || key_text[0] == 127) {
          key_text[0] = 0;  // don't send text for ascii control codes
        }
        if (key_text[0]) { debug("%s: %s ", text_type, key_text); }
    }
    if (xkb_sym == XKB_KEY_ISO_First_Group || xkb_sym == XKB_KEY_ISO_Last_Group || xkb_sym == XKB_KEY_ISO_Next_Group || xkb_sym == XKB_KEY_ISO_Prev_Group || xkb_sym == XKB_KEY_Mode_switch) {
      return;
    }
    int num_default_syms = xkb_state_key_get_syms(sg->default_state, code_for_sym, &default_syms);
    if (num_default_syms > 0) alternate_xkb_sym = default_syms[0];
    int glfw_sym = glfw_key_for_sym(xkb_sym);

    debug(
        "%s%s: %d (%s) xkb_key: %d (%s)",
        format_mods(sg->modifiers),
        "glfw_key", glfw_sym, _glfwGetKeyName(glfw_sym),
        xkb_sym, glfw_xkb_keysym_name(xkb_sym)
    );
    bool has_shifted_key = shifted_xkb_sym != xkb_sym && shifted_xkb_sym != XKB_KEY_NoSymbol;
    bool has_alternate_key = alternate_xkb_sym != xkb_sym && alternate_xkb_sym != XKB_KEY_NoSymbol;
    if (has_shifted_key) {
        glfw_ev.shifted_key = glfw_key_for_sym(shifted_xkb_sym);
        if (glfw_ev.shifted_key) debug(" shifted_key: %d (%s)", glfw_ev.shifted_key, _glfwGetKeyName(glfw_ev.shifted_key))
    }
    if (has_alternate_key) {
        glfw_ev.alternate_key = glfw_key_for_sym(alternate_xkb_sym);
        if (glfw_ev.alternate_key) debug(" alternate_key: %d (%s)", glfw_ev.alternate_key, _glfwGetKeyName(glfw_ev.alternate_key))
    }
    debug("%s", "\n");

    // NOTE: On linux, the reported native key identifier is the XKB keysym value.
    // Do not confuse `native_key` with `xkb_keycode` (the native keycode reported for the
    // glfw event VS the X internal code for a key).
    //
    // We use the XKB keysym instead of the X keycode to be able to go back-and-forth between
    // the GLFW keysym and the XKB keysym when needed, which is not possible using the X keycode,
    // because of the lost information when resolving the keycode to the keysym, like consumed
    // mods.
    glfw_ev.native_key = xkb_sym;

    glfw_ev.action = action;
    glfw_ev.key = glfw_sym;
    glfw_ev.mods = sg->modifiers;
    glfw_ev.text = key_text;
    _GLFWIBUSKeyEvent ibus_ev;
    ibus_ev.glfw_ev = glfw_ev;
    ibus_ev.ibus_keycode = ibus_keycode;
    ibus_ev.window_id = window->id;
    ibus_ev.ibus_keysym = syms[0];
    if (ibus_process_key(&ibus_ev, &xkb->ibus)) {
        debug("↳ to IBUS: keycode: 0x%x keysym: 0x%x (%s) %s\n", ibus_ev.ibus_keycode, ibus_ev.ibus_keysym, glfw_xkb_keysym_name(ibus_ev.ibus_keysym), format_mods(ibus_ev.glfw_ev.mods));
    } else {
        _glfwInputKeyboard(window, &glfw_ev);
    }
}
