static const char *colorname[] = {

    /* 8 standard colors */
    "#232a2d", /* black   */
    "#e57474", /* red     */
    "#8ccf7e", /* green   */
    "#e5c76b", /* yellow  */
    "#67b0e8", /* blue    */
    "#c47fd5", /* magenta */
    "#6cbfbf", /* cyan    */
    "#b3b9b8", /* white   */

    /* 8 bright colors */
    "#2d3437", /* black   */
    "#ef7e7e", /* red     */
    "#96d988", /* green   */
    "#f4d67a", /* yellow  */
    "#71baf2", /* blue    */
    "#ce89df", /* magenta */
    "#67cbe7", /* cyan    */
    "#bdc3c2", /* white   */

    [255] = 0,

    /* Default colors */
    "#dadada", /* default foreground color */
    "#141b1e", /* default background color */
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 256;
unsigned int defaultbg = 257;
unsigned int defaultcs = 256;
static unsigned int defaultrcs = 257;

