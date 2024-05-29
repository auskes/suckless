static const unsigned int borderpx = 4;
static const unsigned int gappx = 20;
static const unsigned int snap = 0;
static const int showbar = 1;
static const int topbar = 1;
static const int user_bh = 30;
static const char *fonts[] = { "Roboto Mono:size=11:style=Bold" };
static const char dmenufont[] = "Roboto Mono:size=11:style=Bold";
static const char norm_fg[] = "#827C77";
static const char norm_bg[] = "#282828";
static const char norm_border[] = "#827C77";
static const char sel_border[] = "#A39A92";
static const char sel_fg[] = "#EAE0C7";
static const char sel_bg[] = "#282828";
static const char urg_fg[] = "#824E48";
static const char urg_bg[] = "#282828";
static const char float_border[] = "#824E48";

static const char *colors[][4] = {

    /*               fg        bg        border       float    */
    [SchemeNorm] = { norm_fg,  norm_bg,  norm_border, float_border }, // unfocused
    [SchemeSel]  = { sel_fg,   sel_bg,   sel_border,  float_border },  // focused
    [SchemeUrg]  = { urg_fg,   urg_bg, }, // urgent colors
};

static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	
        /* class             instance    title      tags mask    switchtotag     isfloating     monitor */
	{ "firefox",         NULL,       NULL,       1 << 1,     1,	         0,             -1, },
        { "firefox",         NULL, 
          "Picture-in-Picture",                      1 << 1,     1,              1,             -1, },
	{ "st",              NULL,       NULL,       1 << 0,	 1,	         0,             -1, },
};

static const float mfact     = 0.50; 
static const int nmaster     = 1;    
static const int resizehints = 0;    
static const int lockfullscreen = 1; 

static const Layout layouts[] = {
	  
	{ "T",      tile },   
	{ "F",      NULL },   
};

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0"; 
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", norm_bg, "-sf", sel_fg, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "80x30", NULL };
static const char *flamcmd[]  = { "flameshot", "gui", NULL };

static const Key keys[] = {
	
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_s,      togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_m,	   spawn,	   {.v = flamcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
        { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_r,      resetlayout,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_v,      togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

static const Button buttons[] = {
	
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};
