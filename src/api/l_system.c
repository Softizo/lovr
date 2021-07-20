#include "api.h"
#include "system/system.h"
#include "core/os.h"
#include <lua.h>
#include <lauxlib.h>

StringEntry lovrKeyboardKey[] = {
  [OS_KEY_A] = ENTRY("a"),
  [OS_KEY_B] = ENTRY("b"),
  [OS_KEY_C] = ENTRY("c"),
  [OS_KEY_D] = ENTRY("d"),
  [OS_KEY_E] = ENTRY("e"),
  [OS_KEY_F] = ENTRY("f"),
  [OS_KEY_G] = ENTRY("g"),
  [OS_KEY_H] = ENTRY("h"),
  [OS_KEY_I] = ENTRY("i"),
  [OS_KEY_J] = ENTRY("j"),
  [OS_KEY_K] = ENTRY("k"),
  [OS_KEY_L] = ENTRY("l"),
  [OS_KEY_M] = ENTRY("m"),
  [OS_KEY_N] = ENTRY("n"),
  [OS_KEY_O] = ENTRY("o"),
  [OS_KEY_P] = ENTRY("p"),
  [OS_KEY_Q] = ENTRY("q"),
  [OS_KEY_R] = ENTRY("r"),
  [OS_KEY_S] = ENTRY("s"),
  [OS_KEY_T] = ENTRY("t"),
  [OS_KEY_U] = ENTRY("u"),
  [OS_KEY_V] = ENTRY("v"),
  [OS_KEY_W] = ENTRY("w"),
  [OS_KEY_X] = ENTRY("x"),
  [OS_KEY_Y] = ENTRY("y"),
  [OS_KEY_Z] = ENTRY("z"),
  [OS_KEY_0] = ENTRY("0"),
  [OS_KEY_1] = ENTRY("1"),
  [OS_KEY_2] = ENTRY("2"),
  [OS_KEY_3] = ENTRY("3"),
  [OS_KEY_4] = ENTRY("4"),
  [OS_KEY_5] = ENTRY("5"),
  [OS_KEY_6] = ENTRY("6"),
  [OS_KEY_7] = ENTRY("7"),
  [OS_KEY_8] = ENTRY("8"),
  [OS_KEY_9] = ENTRY("9"),
  [OS_KEY_SPACE] = ENTRY("space"),
  [OS_KEY_ENTER] = ENTRY("return"),
  [OS_KEY_TAB] = ENTRY("tab"),
  [OS_KEY_ESCAPE] = ENTRY("escape"),
  [OS_KEY_BACKSPACE] = ENTRY("backspace"),
  [OS_KEY_UP] = ENTRY("up"),
  [OS_KEY_DOWN] = ENTRY("down"),
  [OS_KEY_LEFT] = ENTRY("left"),
  [OS_KEY_RIGHT] = ENTRY("right"),
  [OS_KEY_HOME] = ENTRY("home"),
  [OS_KEY_END] = ENTRY("end"),
  [OS_KEY_PAGE_UP] = ENTRY("pageup"),
  [OS_KEY_PAGE_DOWN] = ENTRY("pagedown"),
  [OS_KEY_INSERT] = ENTRY("insert"),
  [OS_KEY_DELETE] = ENTRY("delete"),
  [OS_KEY_F1] = ENTRY("f1"),
  [OS_KEY_F2] = ENTRY("f2"),
  [OS_KEY_F3] = ENTRY("f3"),
  [OS_KEY_F4] = ENTRY("f4"),
  [OS_KEY_F5] = ENTRY("f5"),
  [OS_KEY_F6] = ENTRY("f6"),
  [OS_KEY_F7] = ENTRY("f7"),
  [OS_KEY_F8] = ENTRY("f8"),
  [OS_KEY_F9] = ENTRY("f9"),
  [OS_KEY_F10] = ENTRY("f10"),
  [OS_KEY_F11] = ENTRY("f11"),
  [OS_KEY_F12] = ENTRY("f12"),
  [OS_KEY_BACKTICK] = ENTRY("`"),
  [OS_KEY_MINUS] = ENTRY("-"),
  [OS_KEY_EQUALS] = ENTRY("="),
  [OS_KEY_LEFT_BRACKET] = ENTRY("["),
  [OS_KEY_RIGHT_BRACKET] = ENTRY("]"),
  [OS_KEY_BACKSLASH] = ENTRY("\\"),
  [OS_KEY_SEMICOLON] = ENTRY(";"),
  [OS_KEY_APOSTROPHE] = ENTRY("'"),
  [OS_KEY_COMMA] = ENTRY(","),
  [OS_KEY_PERIOD] = ENTRY("."),
  [OS_KEY_SLASH] = ENTRY("/"),
  [OS_KEY_LEFT_CONTROL] = ENTRY("lctrl"),
  [OS_KEY_LEFT_SHIFT] = ENTRY("lshift"),
  [OS_KEY_LEFT_ALT] = ENTRY("lalt"),
  [OS_KEY_LEFT_OS] = ENTRY("lgui"),
  [OS_KEY_RIGHT_CONTROL] = ENTRY("rctrl"),
  [OS_KEY_RIGHT_SHIFT] = ENTRY("rshift"),
  [OS_KEY_RIGHT_ALT] = ENTRY("ralt"),
  [OS_KEY_RIGHT_OS] = ENTRY("rgui"),
  [OS_KEY_CAPS_LOCK] = ENTRY("capslock"),
  [OS_KEY_SCROLL_LOCK] = ENTRY("scrolllock"),
  [OS_KEY_NUM_LOCK] = ENTRY("numlock"),
  { 0 }
};

StringEntry lovrPermission[] = {
  [PERMISSION_AUDIO_CAPTURE] = ENTRY("audiocapture"),
  { 0 }
};

static int l_lovrSystemGetOS(lua_State* L) {
  lua_pushstring(L, lovrSystemGetOS());
  return 1;
}

static int l_lovrSystemGetCoreCount(lua_State* L) {
  lua_pushinteger(L, lovrSystemGetCoreCount());
  return 1;
}

static int l_lovrSystemRequestPermission(lua_State* L) {
  Permission permission = luax_checkenum(L, 1, Permission, NULL);
  lovrSystemRequestPermission(permission);
  return 0;
}

static const luaL_Reg lovrSystem[] = {
  { "getOS", l_lovrSystemGetOS },
  { "getCoreCount", l_lovrSystemGetCoreCount },
  { "requestPermission", l_lovrSystemRequestPermission },
  { NULL, NULL }
};

int luaopen_lovr_system(lua_State* L) {
  lua_newtable(L);
  luax_register(L, lovrSystem);
  if (lovrSystemInit()) {
    luax_atexit(L, lovrSystemDestroy);
  }
  return 1;
}
