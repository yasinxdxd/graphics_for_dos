#include "GFDOS.H"
#include "GFDDEF.H"

/* fill our funcpointers with functions. */

//GFD_ATTR_FAST_NOINLINE

GFD_CORE GFDINITPROC graphics_for_dos_gfdInit = def_gfdInit;
GFD_CORE GFDDESTROYPROC graphics_for_dos_gfdDestroy = def_gfdDestroy;
GFD_CORE GFDDRAWPIXELPROC graphics_for_dos_gfdDrawPixel = def_gfdDrawPixel;
GFD_CORE GFDSETPIXELCOLORPROC graphics_for_dos_gfdSetPixelColor = def_gfdSetPixelColor;
GFD_CORE GFDDRAWLINEPROC graphics_for_dos_gfdDrawLine = def_gfdDrawLine;
GFD_CORE GFDDRAWLINEWITHOUTCOORDABSTRACTIONPROC graphics_for_dos_gfdDrawLineWithoutCoordAbstraction = def_gfdDrawLineWithoutCoordAbstraction;
GFD_CORE GFDDRAWTRIANGLEPROC graphics_for_dos_gfdDrawTriangle = def_gfdDrawTriangle;
GFD_CORE GFDDRAWTRIANGLEFILLEDPROC graphics_for_dos_gfdDrawTriangleFilled = def_gfdDrawTriangleFilled;
GFD_CORE GFDCLEARPROC graphics_for_dos_gfdClear = def_gfdClear;
