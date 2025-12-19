static const char *colorname[] = {
    /* 8 normal colors */
    [0] = "#1e222a", /* black   */
    [1] = "#e06c75", /* red     */
    [2] = "#7EC7A2", /* green   */
    [3] = "#EBCB8B", /* yellow  */
    [4] = "#61afef", /* blue    */
    [5] = "#c678dd", /* magenta */
    [6] = "#6d8dad", /* cyan    */
    [7] = "#abb2bf", /* white   */

    /* 8 bright colors */
    [8]  = "#2e323a", /* bright black   (gray2) */
    [9]  = "#e06c75", /* bright red     */
    [10] = "#7EC7A2", /* bright green   */
    [11] = "#EBCB8B", /* bright yellow  */
    [12] = "#61afef", /* bright blue    */
    [13] = "#c678dd", /* bright magenta */
    [14] = "#6d8dad", /* bright cyan    */
    [15] = "#abb2bf", /* bright white   */

    /* special colors */
    [256] = "#1e222a", /* background */
    [257] = "#abb2bf", /* foreground */
    [258] = "#abb2bf", /* cursor */
};

/* Default colors (index in colorname[]) */
unsigned int defaultfg = 257;
unsigned int defaultbg = 256;
unsigned int defaultcs = 258;
unsigned int defaultrcs = 258;

