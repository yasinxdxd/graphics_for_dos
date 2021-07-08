#include "GFDOS.H"
#include "GFDDEF.H"

/* fill our funcpointers with functions. */

//GFD_ATTR_FAST_NOINLINE

GFD_CORE GFDINITPROC graphics_for_dos_gfdInit = dec_gfdInit;
GFD_CORE GFDDESTROYPROC graphics_for_dos_gfdDestroy = dec_gfdDestroy;
GFD_CORE GFDDRAWPIXELPROC graphics_for_dos_gfdDrawPixel = dec_gfdDrawPixel;
GFD_CORE GFDSETPIXELCOLORPROC graphics_for_dos_gfdSetPixelColor = dec_gfdSetPixelColor;
GFD_CORE GFDDRAWLINEPROC graphics_for_dos_gfdDrawLine = dec_gfdDrawLine;
GFD_CORE GFDDRAWTRIANGLEPROC graphics_for_dos_gfdDrawTriangle = dec_gfdDrawTriangle;
GFD_CORE GFDCLEARPROC graphics_for_dos_gfdClear = dec_gfdClear;
