static int topbar = 1;
static int fuzzy = 1;
static const char *fonts[] = {
	"monospace:size=10"
};
static const char *prompt      = NULL; 
static const char *colors[SchemeLast][2] = {
	[SchemeNorm] = { "#bbbbbb", "#222222" },
	[SchemeSel] = { "#eeeeee", "#005577" },
	[SchemeOut] = { "#000000", "#00ffff" },
};
static unsigned int lines = 0;

static unsigned int lineheight = 28;
static unsigned int min_lineheight = 28;

static const char worddelimiters[] = " ";
