/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[] = "-*-xbmicons-medium-r-*-*-12-*-*-*-*-*-*-*" ","
                           "-*-terminus-medium-r-*-*-12-*-*-*-*-*-*-*";
			   //"-*-cure-medium-*-*-12-*-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#1C1C24";
static const char normfgcolor[]     = "#98ABAB";
static const char selbordercolor[]  = "#56707e";
static const char selbgcolor[]      = "#3c435b";
static const char selfgcolor[]      = "#AFC2C2";

static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "\uE002", "\uE000", "\uE003", "\uE001", "\uE005",
	                      "\uE004", "\uE008", "\uE006", "\uE007 " };

static const Rule rules[] = {
  /* class                     instance    title       tags mask     isfloating   monitor */
  { "st-256color",             NULL,          NULL,            0,       False,       -1 },
  { "URxvt",                   NULL,          NULL,            0,       False,       -1 },
  { "Firefox",                 NULL,          NULL,       1 << 1,       False,       -1 },
  { "Chromium",                NULL,          NULL,       1 << 1,       False,       -1 },
  { "Emacs",                   NULL,          NULL,       1 << 2,       False,       -1 },
  { "Eclipse",                 NULL,          NULL,       1 << 2,       False,       -1 },
  { "jetbrains-idea-ce",       NULL,          NULL,       1 << 2,       False,       -1 },
  { "libreoffice-calc",        NULL,          NULL,       1 << 4,       False,       -1 },
  { "libreoffice-impress",     NULL,          NULL,       1 << 4,       False,       -1 },
  { "libreoffice-startcenter", NULL,          NULL,       1 << 4,       False,       -1 },
  { "libreoffice-writer",      NULL,          NULL,       1 << 4,       False,       -1 },
  { "Gimp",                    NULL,          NULL,       1 << 5,       False,       -1 },
  { "feh",                     NULL,          NULL,       1 << 5,       False,       -1 },
  { "Vlc",                     NULL,          NULL,       1 << 6,       False,       -1 },
  { "VirtualBox",              NULL,          NULL,       1 << 6,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\uE020 \uE009 \uE020",      tile },    /* first entry is default */
	{ "\uE020 \uE00A \uE020",      NULL },    /* no layout function means floating behavior */
	{ "\uE020 \uE00B \uE020",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", "-e", "tmux", NULL };
static const char *lockcmd[]  = { "slock", NULL };
static const char *xkbmapuscmd[]  = { "setxkbmap", "us", NULL };
static const char *xkbmapusintlcmd[]  = { "setxkbmap", "us", "-variant", "intl", NULL };

#include "shiftview.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          {.v = lockcmd } },
	{ MODKEY|ControlMask,           XK_1,      spawn,          {.v = xkbmapusintlcmd } },
	{ MODKEY|ControlMask,           XK_0,      spawn,          {.v = xkbmapuscmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_agrave, view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_agrave, tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_semicolon, focusmon,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_semicolon, tagmon,      {.i = +1 } },
	{ MODKEY,                       XK_Left,   shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_Right,  shiftview,      {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_ampersand,                     0)
	TAGKEYS(                        XK_eacute,                        1)
	TAGKEYS(                        XK_quotedbl,                      2)
	TAGKEYS(                        XK_apostrophe,                    3)
	TAGKEYS(                        XK_parenleft,                     4)
	TAGKEYS(                        XK_minus,                         5)
	TAGKEYS(                        XK_egrave,                        6)
	TAGKEYS(                        XK_underscore,                    7)
	TAGKEYS(                        XK_ccedilla,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        toggleview,     {0} },
	{ ClkTagBar,            0,              Button3,        view,           {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button4,        shiftview,      {.i = +1 } },
	{ ClkTagBar,            0,              Button5,        shiftview,      {.i = -1 } },
};

