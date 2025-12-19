static const char *colorname[] = {
    
     // Decayce
     /* 8 standard colors */
    "#0d0f18", /* black   - Closest to your #3b4252 (Background) */
    "#dd6777", /* red     - Closest to your #bf616a (Red) */
    "#90ceaa", /* green   - Closest to your #a3be8c (Green) */
    "#ecd3a0", /* yellow  - Closest to your #ebcb8b (Yellow) */
    "#86aaec", /* blue    - Closest to your #81a1c1 (Blue) */
    "#c296eb", /* magenta - Closest to your #b48ead (Magenta) */
    "#93cee9", /* cyan    - Closest to your #88c0d0 (Cyan) */
    "#d0d3d8", /* white   - Closest to your #e5e9f0 (White) */

    /* 8 bright colors */
    "#050710", /* bright black - Closest to your #4c566a (Background 2) */
    "#e26c7c", /* bright red   - Closest to your #bf616a (Bright Red) */
    "#95d3af", /* bright green - Closest to your #a3be8c (Bright Green) */
    "#f1d8a5", /* bright yellow- Closest to your #ebcb8b (Bright Yellow) */
    "#8baff1", /* bright blue  - Closest to your #81a1c1 (Bright Blue) */
    "#c79bf0", /* bright magenta - Closest to your #b48ead (Bright Magenta) */
    "#98d3ee", /* bright cyan  - Closest to your #8fbcbb (Bright Cyan) */
    "#c8cbd0", /* bright white - Closest to your #eceff4 (Bright White 2) */
[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#d0d3d8", /* default foreground colour */
	"#0d0f18", /* default background colour */
};


/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 256;
unsigned int defaultbg = 257;
unsigned int defaultcs = 256;
static unsigned int defaultrcs = 257;


