// static const char black[]        = "#0d0f18";
// static const char white[]        = "#cbced3";
// static const char gray2[]        = "#11131c"; // unfocused window border
// static const char gray3[]        = "#262831";
// static const char gray4[]        = "#11131c";
// static const char blue[]         = "#86aaec";  // focused window border
// static const char green[]        = "#90ceaa";
// static const char red[]          = "#dd6777";
// static const char orange[]       = "#f8bd96";
// static const char yellow[]       = "#ecd3a0";
// static const char pink[]         = "#c296eb";
// static const char col_borderbar[]= "#0d0f18"; // inner border
//

static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#cbced3", "#0d0f18" },
	[SchemeSel] = { "#262831", "#90ceaa" },
	[SchemeOut] = { "#000000", "#00ffff" },
};
