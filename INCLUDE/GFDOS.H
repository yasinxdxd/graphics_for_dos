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
typedef float f32;
typedef double f64;

/* Check for GCC */
#if (__GNUC__ > 4)
#define _gfd_binary_prefix_ 0b
#else
#define _gfd_binary_prefix_
#endif

#define _gfdbin(x) _gfd_binary_prefix_##x
#define gfdbin(bin) (int) _gfdbin(bin)

/* Core Function Definitions */

/**
 * @author Muhammed Yasinhan Yaşar. (yasinxdxd)
 * @test All tests were made on DOSBOX 0.74
 * @code Code style of this project is about creating function pointers and loading these pointers with actual definitions of real functions.
 * @bug there are some bugs on Clear function
**/

/**
 * @brief Initialize function. It's for setting video mode for drawing graphics.
 * @param void : it's for there is no parameter, and will be no parameter.
**/
typedef int (GFDAPIENTRYP GFDINITPROC)(void);
GFD_CORE GFDINITPROC graphics_for_dos_gfdInit;
#define gfdInit graphics_for_dos_gfdInit

/**
 * @brief Destroy function. It's for cleaning up everything.
 * @param void : it's for there is no parameter, and will be no parameter.
**/
typedef void (GFDAPIENTRYP GFDDESTROYPROC)(void);
GFD_CORE GFDDESTROYPROC graphics_for_dos_gfdDestroy;
#define gfdDestroy graphics_for_dos_gfdDestroy

/**
 * @brief Draw Pixel function. It's for drawing a single pixel on to the screen.
 * @param x (u32) x coordinate of the pixel which will be drawn. There is no any abstraction for pixel coordinates.
 * @param y (u32) x coordinate of the pixel which will be drawn. There is no any abstraction for pixel coordinates.
**/
typedef void (GFDAPIENTRYP GFDDRAWPIXELPROC)(u32 x, u32 y);
GFD_CORE GFDDRAWPIXELPROC graphics_for_dos_gfdDrawPixel;
#define gfdDrawPixel graphics_for_dos_gfdDrawPixel

/**
 * @brief Set Pixel Color function. Changing the color of pixels which will be drawn after the call of this function.
 * @param color (u8) the color code to change the color at a spesific memory addres.
**/
typedef void (GFDAPIENTRYP GFDSETPIXELCOLORPROC)(u8 color);
GFD_CORE GFDSETPIXELCOLORPROC graphics_for_dos_gfdSetPixelColor;
#define gfdSetPixelColor graphics_for_dos_gfdSetPixelColor

/**
 * @brief Draw Line function. It's a function for drawing a line between two points.
 * @param x0 (f32) x coordinate of the first point on coordinate system which is affected by coordinate system abstraction.
 * @param y0 (f32) y coordinate of the first point on coordinate system which is affected by coordinate system abstraction.
 * @param x1 (f32) x coordinate of the second point on coordinate system which is affected by coordinate system abstraction.
 * @param y1 (f32) y coordinate of the second point on coordinate system which is affected by coordinate system abstraction.
**/
typedef void (GFDAPIENTRYP GFDDRAWLINEPROC)(f32 x0, f32 y0, f32 x1, f32 y1);
GFD_CORE GFDDRAWLINEPROC graphics_for_dos_gfdDrawLine;
#define gfdDrawLine graphics_for_dos_gfdDrawLine

/**
 * @brief Draw Line Without Coordinate Abstraction function. It's a function for drawing a line between two points.
 * @param x0 (u32) x coordinate of the first point on coordinate system which doesn't have any coordinate abstraction.
 * @param y0 (u32) y coordinate of the first point on coordinate system which doesn't have any coordinate abstraction.
 * @param x1 (u32) x coordinate of the second point on coordinate system which doesn't have any coordinate abstraction.
 * @param y1 (u32) y coordinate of the second point on coordinate system which doesn't have any coordinate abstraction.
**/
typedef void (GFDAPIENTRYP GFDDRAWLINEWITHOUTCOORDABSTRACTIONPROC)(u32 x0, u32 y0, u32 x1, u32 y1);
GFD_CORE GFDDRAWLINEWITHOUTCOORDABSTRACTIONPROC graphics_for_dos_gfdDrawLineWithoutCoordAbstraction;
#define gfdDrawLineWithoutCoordAbstraction graphics_for_dos_gfdDrawLineWithoutCoordAbstraction

/**
 * @brief Draw Triangle function. It's for drawing an empty triangle which is becoming from three points.
 * @param x0 (f32) x coordinate of the first point for drawing a triangle on coordinate system which is affected by coordinate system abstraction.
 * @param y0 (f32) y coordinate of the first point for drawing a triangle on coordinate system which is affected by coordinate system abstraction.
 * @param x1 (f32) x coordinate of the second point for drawing a triangle on coordinate system which is affected by coordinate system abstraction.
 * @param y1 (f32) y coordinate of the second point for drawing a triangle on coordinate system which is affected by coordinate system abstraction.
 * @param x2 (f32) x coordinate of the third point for drawing a triangle on coordinate system which is affected by coordinate system abstraction.
 * @param y2 (f32) y coordinate of the third point for drawing a triangle on coordinate system which is affected by coordinate system abstraction.
**/
typedef void (GFDAPIENTRYP GFDDRAWTRIANGLEPROC)(f32 x0, f32 y0, f32 x1, f32 y1, f32 x2, f32 y2);
GFD_CORE GFDDRAWTRIANGLEPROC graphics_for_dos_gfdDrawTriangle;
#define gfdDrawTriangle graphics_for_dos_gfdDrawTriangle

/**
 * @brief Draw Triangle Filled function. It's for drawing a filled triangle which is becoming from three points.
 * @param x0 (f32) x coordinate of the first point for drawing a filled triangle on coordinate system which is affected by coordinate system abstraction.
 * @param y0 (f32) y coordinate of the first point for drawing a filled triangle on coordinate system which is affected by coordinate system abstraction.
 * @param x1 (f32) x coordinate of the second point for drawing a filled triangle on coordinate system which is affected by coordinate system abstraction.
 * @param y1 (f32) y coordinate of the second point for drawing a filled triangle on coordinate system which is affected by coordinate system abstraction.
 * @param x2 (f32) x coordinate of the third point for drawing a filled triangle on coordinate system which is affected by coordinate system abstraction.
 * @param y2 (f32) y coordinate of the third point for drawing a filled triangle on coordinate system which is affected by coordinate system abstraction.
**/
typedef void (GFDAPIENTRYP GFDDRAWTRIANGLEFILLEDPROC)(f32 x0, f32 y0, f32 x1, f32 y1, f32 x2, f32 y2);
GFD_CORE GFDDRAWTRIANGLEFILLEDPROC graphics_for_dos_gfdDrawTriangleFilled;
#define gfdDrawTriangleFilled graphics_for_dos_gfdDrawTriangleFilled

/**
 * @brief Clear function. It's for clearing the screen black.
 * @param void : it's for there is no parameter, and will be no parameter.
**/
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
#define GFD_CLR_BLACK           0x00/*gfdbin(0000)*/
#define GFD_CLR_BLUE            0x01/*gfdbin(0001)*/
#define GFD_CLR_GREEN           0x02/*gfdbin(0010)*/
#define GFD_CLR_CYAN            0x03/*gfdbin(0011)*/
#define GFD_CLR_RED             0x04/*gfdbin(0100)*/
#define GFD_CLR_MAGENTA         0x05/*gfdbin(0101)*/
#define GFD_CLR_BROWN           0x06/*gfdbin(0110)*/
#define GFD_CLR_WHITE           0x07/*gfdbin(0111)*/
///*BRIGHT
#define GFD_CLR_GRAY            0x08/*gfdbin(1000)*/
#define GFD_CLR_LIGHT_BLUE      0x09/*gfdbin(1001)*/
#define GFD_CLR_LIGHT_GREEN     0x0A/*gfdbin(1010)*/
#define GFD_CLR_LIGHT_CYAN      0x0B/*gfdbin(1011)*/
#define GFD_CLR_LIGHT_RED       0x0C/*gfdbin(1100)*/
#define GFD_CLR_LIGHT_MAGENTA   0x0D/*gfdbin(1101)*/
#define GFD_CLR_YELLOW          0x0E/*gfdbin(1110)*/
#define GFD_CLR_INTENSE_WHITE   0x0F/*gfdbin(1111)*/


#ifdef __cplusplus
}
#endif

#endif//GFD_GFDOS_H
