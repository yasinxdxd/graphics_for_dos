/*

MIT License

Copyright (c) 2021 Muhammed Yasinhan Yaşar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef GFD_GFDOS_H
#define GFD_GFDOS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Core Definitions */
#ifndef GFDAPIENTRY
#define GFDAPIENTRY
#else
#undef GFDAPIENTRY
#define GFDAPIENTRY
#endif

#ifndef GFDAPIENTRYP
#define GFDAPIENTRYP GFDAPIENTRY * 
#else
#undef GFDAPIENTRYP
#define GFDAPIENTRYP GFDAPIENTRY * 
#endif

#define GFD_CORE
#define GFD_FORMAT
#define GFD_ATTRIBUTE __attribute__
#define GFD_ATTR_FAST_NOINLINE __attribute__((fastcall, noinline))
#define GFD_ATTR_ALIGNED(X) __attribute__((packed, aligned(X)))

/* Error Definitions */
#define GFD_ERR_

/* Core Type Definitions */
#define NULL 0
#define bool _Bool
#define true 1
#define false 0

typedef signed char        i8;
typedef signed short       i16;
typedef signed int         i32;
typedef signed long long   i64;
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

/* Check for GCC */
#if (__GNUC__ > 4)
#define _gfd_binary_prefix_ 0b
#else
#define _gfd_binary_prefix_
#endif

#define _gfdbin(x) _gfd_binary_prefix_##x
#define gfdbin(bin) (int) _gfdbin(bin)

/* Core Struct Definitions */

/* Core Function Definitions */

typedef int (GFDAPIENTRYP GFDINITPROC)(void);
GFD_CORE GFDINITPROC graphics_for_dos_gfdInit;
#define gfdInit graphics_for_dos_gfdInit

typedef void (GFDAPIENTRYP GFDDESTROYPROC)(void);
GFD_CORE GFDDESTROYPROC graphics_for_dos_gfdDestroy;
#define gfdDestroy graphics_for_dos_gfdDestroy

typedef void (GFDAPIENTRYP GFDDRAWPIXELPROC)(unsigned int x, unsigned int y);
GFD_CORE GFDDRAWPIXELPROC graphics_for_dos_gfdDrawPixel;
#define gfdDrawPixel graphics_for_dos_gfdDrawPixel

typedef void (GFDAPIENTRYP GFDSETPIXELCOLORPROC)(unsigned char color);
GFD_CORE GFDSETPIXELCOLORPROC graphics_for_dos_gfdSetPixelColor;
#define gfdSetPixelColor graphics_for_dos_gfdSetPixelColor

typedef void (GFDAPIENTRYP GFDDRAWLINEPROC)(float x0, float y0, float x1, float y1);
GFD_CORE GFDDRAWLINEPROC graphics_for_dos_gfdDrawLine;
#define gfdDrawLine graphics_for_dos_gfdDrawLine

typedef void (GFDAPIENTRYP GFDDRAWTRIANGLEPROC)(float x0, float y0, float x1, float y1, float x2, float y2);
GFD_CORE GFDDRAWTRIANGLEPROC graphics_for_dos_gfdDrawTriangle;
#define gfdDrawTriangle graphics_for_dos_gfdDrawTriangle

typedef void (GFDAPIENTRYP GFDCLEARPROC)(void);
GFD_CORE GFDCLEARPROC graphics_for_dos_gfdClear;
#define gfdClear graphics_for_dos_gfdClear

/* Mouse/Keyboard Definitions */

#define GFD_KEY_SPACE 0x20
#define GFD_KEY_A 0x41
#define GFD_KEY_B 0x42
#define GFD_KEY_C 0x43
#define GFD_KEY_D 0x44
#define GFD_KEY_E 0x45
#define GFD_KEY_F 0x46
#define GFD_KEY_G 0x47
#define GFD_KEY_H 0x48
#define GFD_KEY_I 0x49
#define GFD_KEY_J 0x4A
#define GFD_KEY_K 0x4B
#define GFD_KEY_L 0x4C
#define GFD_KEY_M 0x4D
#define GFD_KEY_N 0x4E
#define GFD_KEY_O 0x4F
#define GFD_KEY_P 0x50
#define GFD_KEY_Q 0x51
#define GFD_KEY_R 0x52
#define GFD_KEY_S 0x53
#define GFD_KEY_T 0x54
#define GFD_KEY_U 0x55
#define GFD_KEY_V 0x56
#define GFD_KEY_W 0x57
#define GFD_KEY_X 0x58
#define GFD_KEY_Y 0x59
#define GFD_KEY_Z 0x5A








/* Color Definitions */



//BASIC COLORS	I	R	G	B	COLOR

//DULL INTENSITY
#define GFD_CLR_BLACK           /*gfdbin*/(0000)
#define GFD_CLR_BLUE            /*gfdbin*/(0001)
#define GFD_CLR_GREEN           /*gfdbin*/(0010)
#define GFD_CLR_CYAN            /*gfdbin*/(0011)
#define GFD_CLR_RED             /*gfdbin*/(0100)
#define GFD_CLR_MAGENTA         /*gfdbin*/(0101)
#define GFD_CLR_BROWN           /*gfdbin*/(0110)
#define GFD_CLR_WHITE           /*gfdbin*/(0111)
///*BRIGHT*/
#define GFD_CLR_GRAY            /*gfdbin*/(01000)
#define GFD_CLR_LIGHT_BLUE      /*gfdbin*/(01001)
#define GFD_CLR_LIGHT_GREEN     /*gfdbin*/(01010)
#define GFD_CLR_LIGHT_CYAN      /*gfdbin*/(01011)
#define GFD_CLR_LIGHT_RED       /*gfdbin*/(01100)
#define GFD_CLR_LIGHT_MAGENTA   /*gfdbin*/(01101)
#define GFD_CLR_YELLOW          /*gfdbin*/(01110)
#define GFD_CLR_INTENSE_WHITE   /*gfdbin*/(01111)


#ifdef __cplusplus
}
#endif

#endif//GFD_GFDOS_H
