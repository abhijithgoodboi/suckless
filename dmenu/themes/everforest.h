  // /* 8 normal colors */
  // "#232A2E", // black
  // "#E67E80", // red
  // "#A7C080", // green
  // "#DBBC7F", // yellow
  // "#7FBBB3", // blue
  // "#D699B6", // magenta/purple
  // "#83C092", // cyan
  // "#D3C6AA", // white
  //
  // /* 8 bright colors (same as normal if uniform look is desired) */
  // "#7A8478", // bright black / grey0
  // "#E67E80", // bright red
  // "#A7C080", // bright green
  // "#DBBC7F", // bright yellow
  // "#7FBBB3", // bright blue
  // "#D699B6", // bright magenta
  // "#83C092", // bright cyan
  // "#D3C6AA", // bright white

  static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#D3C6AA", "#232A2E" },
	[SchemeSel] = { "#7A8478", "#A7C080" },
	[SchemeOut] = { "#000000", "#A7C080" },
};
