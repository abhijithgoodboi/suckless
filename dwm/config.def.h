/* See LICENSE file for copyright and license details. */

/* ************************* appearance ************************* */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int default_border = 0;   /* to switch back to default border after dynamic border resizing via keybinds */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 5;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 10;   /* systray spacing */
static const unsigned int systrayonleft = 0;
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
//static const int vertpad            = 10;       /* vertical padding of bar */
//static const int sidepad            = 10;       /* horizontal padding of bar */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const Bool viewontag         = True; /* Switch view on tag switch */
static const int horizpadbar        = 5;
static const int vertpadbar         = 11;
static const int vertpadtab         = 35;
static const int horizpadtabi       = 15;
static const int horizpadtabo       = 15;
static const int scalepreview       = 4;        /* preview scaling (display w and h / scalepreview) */
static const int previewbar         = 1;        /* show the bar in the preview window */


/* ************************* Fonts ************************* */
static const char *fonts[]          = { "Hack:style:bold:size=12" ,"JetBrainsMono Nerd Font Mono:style:bold:size=19" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font Mono:style:medium:size=12";
static const int colorfultag        = 1;        /* 0 means use SchemeSel for selected non vacant tag */


/* ************************* Colors ************************* */
#include "themes/decayce.h"


static const char *colors[][3]      = {
	/*               fg         bg         border   */
    [SchemeNorm]       = { gray3,   black,  gray2 },
    [SchemeSel]        = { gray4,   green,  green },
    [SchemeTitle]      = { white,   black,  black }, // active window title
    [TabSel]           = { blue,    gray2,  black },
    [TabNorm]          = { gray3,   black,  black },
    [SchemeTag]        = { gray3,   black,  black },
    [SchemeTag1]       = { blue,    black,  black },
    [SchemeTag2]       = { green,   black,  black },
    [SchemeTag3]       = { red,     black,  black },
    [SchemeTag4]       = { orange,  black,  black },
    [SchemeTag5]       = { pink,    black,  black },
    [SchemeLayout]     = { green,   black,  black },
    [SchemeBtnPrev]    = { green,   black,  black },
    [SchemeBtnNext]    = { yellow,  black,  black },
    [SchemeBtnClose]   = { red,     black,  black },
};


/* ************************* Tagging/Workspaces ************************* */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = {"", "", "", "󰈹", ""};

/* launcher commands (They must be NULL terminated) */
static const char* dmenu_run[]      = { "dmenu_run", NULL };
//static const char* eww[] = { "eww", "open" , "eww", NULL };

static const Launcher launchers[] = {
       /* command       name to display */
    { dmenu_run,         "󰣇" },
    //{ eww,         "" },
};

static const int tagschemes[] = {
    SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, SchemeTag5
};

#define ICONSIZE 19   /* icon size */
#define ICONSPACING 8 /* space between icon and title */

static const unsigned int ulinepad = 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke = 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset = 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;	/* 1 to show underline on all tags, 0 for just the active ones */

/* ************************* Window Rules ************************* */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
    { "Nsxiv",    NULL,       NULL,       0,            1,           -1 },
    { "Spotify",  NULL,       NULL,       1 << 1,       0,           -1 },
    { "St",       NULL,       NULL,       1 << 2,       0,           -1 },
    { "Brave",    NULL,       NULL,       1 << 3,       0,           -1 },
    { "discord",  NULL,       NULL,       1 << 4,       0,           -1 },

};

/* ************************* layout(s) ************************* */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */



#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#include "movestack.c"
#include "tatami.c"
// #include "functions.h"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
    { "|+|",      tatami },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* ************************* key definitions ************************* */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      previewtag,     {.ui = TAG } },     

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/usr/local/bin/st", "-c", cmd, NULL } }

/* ************************* commands ************************* */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */



/* Lauch Apps */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *rangercmd[] = { "st", "-e", "ranger", NULL};
static const char *rmpcmd[] = { "st", "-e", "rmpc", NULL};
static const char *neovimcmd[] = { "st", "-e", "nvim", NULL};
static const char *iwctld[] = { "st", "-e", "iwctl", NULL};
static const char *htopcmd[] = { "st", "-e", "htop", NULL};
static const char *bravel[] = {"brave", NULL};
static const char *firefoxl[] = {"firefox", NULL};
static const char *discordl[] = {"discord", NULL};
static const char *thunarl[] = {"thunar", NULL};
static const char *spotifyl[] = {"spotify", NULL};
static const char *vlcp[] = {"vlc", NULL};
static const char *bluecmd[]= {"blueberry", NULL};

/* Power scripts */
// static const char *poweroffcmd[] = {"poweroff", NULL};
// static const char *rebootcmd[] = {"reboot", NULL};
static const char *rofipower[] = {"/home/anastasia/.local/bin/scripts/rofi-powermenu.sh", NULL};
static const char *powermenucmd[] = {"/home/anastasia/.local/bin/scripts/powermenu.sh", NULL};
static const char *betterlock[] = {"/home/anastasia/suckless/dwm/better.sh", NULL};
static const char *layoutcmd[] = {"/home/anastasia/.local/bin/scripts/dmenu-layouts.sh", NULL};

/* Dunst */
static const char *dunclose[] = {"dunstctl", "close", NULL};
static const char *duncloseall[] = {"dunstctl", "close-all", NULL};
static const char *dunhistory[] = {"dunstctl", "history-pop", NULL};

/* Wallpaper scripts */
static const char *setwal[] = {"/home/anastasia/.local/bin/scripts/wal.sh", NULL};
static const char *selwal[] = {"/home/anastasia/.local/bin/scripts/set-wall.sh", NULL};

static const char *mpvdm[] = {"/home/anastasia/.local/bin/scripts/mpv.sh", NULL};

/* Theme switcher */
static const char *dtheme[] = {"/home/anastasia/.local/bin/scripts/dunst-theme.sh", NULL};
static const char *rtheme[] = {"/home/anastasia/.local/bin/scripts/rofi-theme.sh", NULL};
static const char *stheme[] = {"/home/anastasia/.local/bin/scripts/st-themes.sh", NULL};


/* Hardware kays for volume and brightness */
#include <X11/XF86keysym.h>

static const char *mutevol[] = { "/home/anastasia/.local/bin/scripts/volume.sh", "--toggle",  NULL };
static const char *mutemic[] = { "/home/anastasia/.local/bin/scripts/volume.sh", "--toggle-mic",  NULL };
static const char *upvol[] = { "/home/anastasia/.local/bin/scripts/volume.sh", "--inc",  NULL };
static const char *downvol[] = { "/home/anastasia/.local/bin/scripts/volume.sh", "--dec",  NULL };
static const char *incvol[] = { "/home/anastasia/.local/bin/scripts/volume.sh", "--inc-fine",  NULL };
static const char *decvol[] = { "/home/anastasia/.local/bin/scripts/volume.sh", "--dec-fine",  NULL };
static const char *playpausel[] = { "/home/anastasia/.local/bin/scripts/media.sh", "play-pause", NULL };
static const char *playnextl[] = { "/home/anastasia/.local/bin/scripts/media.sh", "next", NULL };
static const char *playprvl[] = { "/home/anastasia/.local/bin/scripts/media.sh", "previous", NULL };
static const char *upbl[] = { "/home/anastasia/.local/bin/scripts/brightness.sh", "--inc",    NULL };
static const char *downbl[] = { "/home/anastasia/.local/bin/scripts/brightness.sh", "--dec",    NULL };

/* Screenshot */
static const char *shotnow[] = { "/home/anastasia/.local/bin/scripts/screenshot.sh", "--now", NULL };
static const char *shotin5[] = { "/home/anastasia/.local/bin/scripts/screenshot.sh", "--in5", NULL };
static const char *shotin10[] = { "/home/anastasia/.local/bin/scripts/screenshot.sh", "--in10", NULL };
static const char *shotwin[] = { "/home/anastasia/.local/bin/scripts/screenshot.sh", "--win", NULL };
static const char *shotarea[] = { "/home/anastasia/.local/bin/scripts/screenshot.sh", "--area", NULL };

/* ************************* Keybinds ************************* */

static const Key keys[] = {
	/* modifier                             key                         function        argument */

    //Dmenu and Terminal ----------
	{ MODKEY,                               XK_d,                       spawn,          {.v = dmenucmd } },
	{ MODKEY,                               XK_Return,                  spawn,          {.v = termcmd } },

    //Themes Switch ----------
    { MODKEY,                               XK_F5,                      spawn,          {.v = dtheme } },
    { MODKEY,                               XK_F6,                      spawn,          {.v = rtheme } },
    { MODKEY,                               XK_F7,                      spawn,          {.v = stheme } },

    
    // Lauch App ----------
    { ALTKEY,			                    XK_x,	                    spawn,	        {.v = bravel } },
    { ALTKEY,                               XK_f,                       spawn,          {.v = firefoxl } },
    { ALTKEY,                               XK_d,                       spawn,          {.v = discordl } },
	{ ALTKEY,			                    XK_z,	                    spawn,	        {.v = thunarl } },
	{ ALTKEY,			                    XK_s,                       spawn,	        {.v = spotifyl } },
	{ ALTKEY,			                    XK_v,	                    spawn,	        {.v = vlcp } },
    { ALTKEY,                               XK_a,                       spawn,          {.v = bluecmd } },
    { ALTKEY|ShiftMask,                     XK_m,                       spawn,          {.v = mpvdm } },
	{ ALTKEY,                               XK_r,                       spawn,          {.v = rangercmd } },
    { ALTKEY,                               XK_m,                       spawn,          {.v = rmpcmd } },
    { ALTKEY,                               XK_n,                       spawn,          {.v = neovimcmd } },
    { ALTKEY,                               XK_h,                       spawn,          {.v = htopcmd } },
    { ALTKEY,                               XK_i,                       spawn,          {.v = iwctld } },
	{ ALTKEY,			                    XK_space,                   spawn,          {.v = dunclose } },
	{ ALTKEY|ShiftMask,		                XK_space,                   spawn,          {.v = duncloseall } },
	{ ALTKEY,			                    XK_Return,                  spawn,          {.v = dunhistory } },

  /* poweroff and reboot */
  { MODKEY,                                 XK_BackSpace,               spawn,          {.v = powermenucmd } },
  { ALTKEY,                                 XK_l,                       spawn,          {.v = betterlock} },
  { MODKEY|ShiftMask,		                XK_x,                       spawn,	        {.v = rofipower} },

  /* audio for inc and dec 1 */ 
  { MODKEY,                                 XK_equal,                   spawn,          {.v = incvol } },
  { MODKEY,                                 XK_minus,                   spawn,          {.v = decvol } },

  /* audio and brightness */
  { 0,                                      XF86XK_AudioMute,           spawn,          {.v = mutevol } },
  { 0,                                      XF86XK_AudioMicMute,        spawn,          {.v = mutemic } },
  { 0,                                      XF86XK_AudioRaiseVolume,    spawn,          {.v = upvol } },
  { 0,                                      XF86XK_AudioLowerVolume,    spawn,          {.v = downvol } },
  { 0,                                      XF86XK_AudioPlay,           spawn,          {.v = playpausel } },
  { 0,                                      XF86XK_AudioNext,           spawn,          {.v = playnextl } },
  { 0,                                      XF86XK_AudioPrev,           spawn,          {.v = playprvl } },
  { 0,                                      XF86XK_MonBrightnessUp,	    spawn,	  	    {.v = upbl } },
  { 0,                                      XF86XK_MonBrightnessDown,   spawn,	  	    {.v = downbl } },

  /* screenshot */
  { 0,                                      XK_Print, 	                spawn, 	        {.v = shotnow } },
  { ALTKEY, 	                            XK_Print, 	                spawn,          {.v = shotin5 } },
  { ShiftMask, 	                            XK_Print, 	                spawn,          {.v = shotin10 } },
  { ControlMask,                            XK_Print, 	                spawn,          {.v = shotwin } },
  { MODKEY, 	                            XK_Print, 	                spawn,          {.v = shotarea } },

  //Set Wallpapers ----------
  { ALTKEY,                                 XK_w,                       spawn,          {.v = setwal } },
  { ALTKEY|ShiftMask,                       XK_w,                       spawn,          {.v = selwal } },

    /* DWM Stuffs*/
  /* Murder */
  { MODKEY,                                 XK_q,                       killclient,     {0} }, // Kill window
  { MODKEY|ShiftMask,                       XK_q,                       quit,           {0} }, // Quit DWM
  { MODKEY|ShiftMask,                       XK_r,                       quit,           {1} }, // Restart DWM


  /* Switch */
  { MODKEY,                                 XK_j,                       focusstack,     {.i = +1 } }, // Cycle window
  { MODKEY,                                 XK_k,                       focusstack,     {.i = -1 } },
  { MODKEY|ShiftMask,                       XK_j,                       movestack,      {.i = +1 } }, // Switch master
  { MODKEY|ShiftMask,                       XK_k,                       movestack,      {.i = -1 } },

  { MODKEY,                                 XK_i,                       incnmaster,     {.i = +1 } }, // Vertical
  { MODKEY,                                 XK_u,                       incnmaster,     {.i = -1 } }, // Horizontal

  
   
    /* Gaps and Border */

  /* Border */
  {MODKEY|ShiftMask,                        XK_minus,                   setborderpx,    {.i = -1 } }, // Decrease border width
  {MODKEY|ShiftMask,                        XK_p,                       setborderpx,    {.i = +1 } }, // Increase border width
  {MODKEY|ShiftMask,                        XK_w,                       setborderpx,    {.i = default_border } },

  /* Change m, cfact sizes */
  { MODKEY,                                 XK_h,                       setmfact,       {.f = -0.05} }, // Shrink left
  { MODKEY,                                 XK_l,                       setmfact,       {.f = +0.05} }, // Shrink right
  { MODKEY|ShiftMask,                       XK_h,                       setcfact,       {.f = +0.25} }, // Shrink up
  { MODKEY|ShiftMask,                       XK_l,                       setcfact,       {.f = -0.25} }, // Shrink down
  { MODKEY|ShiftMask,                       XK_o,                       setcfact,       {.f =  0.00} }, // default shrink


    /* Misc */
  { MODKEY,                                 XK_b,                       togglebar,      {0} }, // Toggle bar
  { MODKEY|ShiftMask,                       XK_Return,                  zoom,           {0} }, // Switch master
  { MODKEY,                                 XK_Tab,                     view,           {0} }, // Switch to last tag
  { MODKEY, 					            XK_e, 						hidewin,        {0} }, // Hide window
  { MODKEY|ShiftMask, 		                XK_e, 						restorewin,     {0} }, // Restore window
  { MODKEY,                                 XK_0,                       view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,                       XK_0,                       tag,            {.ui = ~0 } },
  
        /* Gaps */
  /* Overall gaps */
  { MODKEY|ALTKEY,                          XK_u,                       incrgaps,       {.i = +1 } },
  { MODKEY|ALTKEY|ShiftMask,                XK_u,                       incrgaps,       {.i = -1 } },
  { MODKEY|ALTKEY|ShiftMask,                XK_0,                       defaultgaps,    {0} }, // Default gaps
  { MODKEY|ALTKEY,                          XK_0,                       togglegaps,     {0} }, // Toggle gaps
  
  /* Inner gaps */
  { MODKEY|ALTKEY,                          XK_i,                       incrigaps,      {.i = +1 } },
  { MODKEY|ALTKEY|ShiftMask,                XK_i,                       incrigaps,      {.i = -1 } },

  /* Outer gaps */
  { MODKEY|ALTKEY,                          XK_o,                       incrogaps,      {.i = +1 } },
  { MODKEY|ALTKEY|ShiftMask,                XK_o,                       incrogaps,      {.i = -1 } },

  /* Inner + Outer horiz, vert gaps */
  { MODKEY|ALTKEY,                          XK_6,                       incrihgaps,     {.i = +1 } },
  { MODKEY|ALTKEY|ShiftMask,                XK_6,                       incrihgaps,     {.i = -1 } },
  { MODKEY|ALTKEY,                          XK_7,                       incrivgaps,     {.i = +1 } },
  { MODKEY|ALTKEY|ShiftMask,                XK_7,                       incrivgaps,     {.i = -1 } },
  { MODKEY|ALTKEY,                          XK_8,                       incrohgaps,     {.i = +1 } },
  { MODKEY|ALTKEY|ShiftMask,                XK_8,                       incrohgaps,     {.i = -1 } },
  { MODKEY|ALTKEY,                          XK_9,                       incrovgaps,     {.i = +1 } },
  { MODKEY|ALTKEY|ShiftMask,                XK_9,                       incrovgaps,     {.i = -1 } },
  

  /* Layouts */
  
  { MODKEY|ShiftMask,                       XK_space,                   togglefloating, {0} },
  { MODKEY, 					            XK_f, 						togglefullscr,  {0} },
  { MODKEY|ControlMask,		                XK_comma,                   cyclelayout,    {.i = -1 } },
  { MODKEY|ControlMask,                     XK_period,                  cyclelayout,    {.i = +1 } },

  { ALTKEY|ControlMask, 		            XK_space, 					spawn,          {.v = layoutcmd } },
  { ALTKEY|ControlMask,                     XK_t,                       setlayout,      {.v = &layouts[0]} }, //tile
  { ALTKEY|ControlMask,                     XK_m,                       setlayout,      {.v = &layouts[1]} }, //monocle
  { ALTKEY|ControlMask,                     XK_s,                       setlayout,      {.v = &layouts[2]} }, //spiral
  { ALTKEY|ControlMask,                     XK_d,                       setlayout,      {.v = &layouts[3]} }, //dwindle
  { ALTKEY|ShiftMask,                       XK_d,                       setlayout,      {.v = &layouts[4]} }, //deck
  { ALTKEY|ControlMask,                     XK_b,                       setlayout,      {.v = &layouts[5]} }, //bstack
  { ALTKEY|ShiftMask,                       XK_b,                       setlayout,      {.v = &layouts[6]} }, //bstackhoriz
  { ALTKEY|ControlMask,                     XK_g,                       setlayout,      {.v = &layouts[7]} }, //grid
  { ALTKEY|ControlMask,                     XK_n,                       setlayout,      {.v = &layouts[8]} }, //nrowgrid
  { ALTKEY|ControlMask,                     XK_h,                       setlayout,      {.v = &layouts[9]} }, //horizgrid
  { ALTKEY|ShiftMask,                       XK_g,                       setlayout,      {.v = &layouts[10]} }, //gaplessgrid
  { ALTKEY|ControlMask,                     XK_c,                       setlayout,      {.v = &layouts[11]} }, //centeredmaster
  { ALTKEY|ShiftMask,                       XK_c,                       setlayout,      {.v = &layouts[12]} }, //centeredfloatingmaster
  { ALTKEY|ControlMask,                     XK_y,                       setlayout,      {.v = &layouts[13]} }, //tatami
  { ALTKEY|ControlMask,                     XK_f,                       setlayout,      {.v = &layouts[14]} }, //floating
  { MODKEY,                                 XK_space,                   setlayout,      {0} },

  
  { MODKEY,                                 XK_comma,                   focusmon,       {.i = -1 } },
  { MODKEY,                                 XK_period,                  focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,                       XK_comma,                   tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,                       XK_period,                  tagmon,         {.i = +1 } },


    /* Tags */
  TAGKEYS(                                  XK_1,                      0)
  TAGKEYS(                                  XK_2,                      1)
  TAGKEYS(                                  XK_3,                      2)
  TAGKEYS(                                  XK_4,                      3)
  TAGKEYS(                                  XK_5,                      4)
  TAGKEYS(                                  XK_6,                      5)
  TAGKEYS(                                  XK_7,                      6)
  TAGKEYS(                                  XK_8,                      7)
  TAGKEYS(                                  XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


/* ******************** DWMC ******************** */
void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
};
