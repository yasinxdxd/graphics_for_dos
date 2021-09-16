#ifndef GFD_GFDDEF_H
#define GFD_GFDDEF_H

#ifdef __cplusplus
extern "C" {
#endif

#define SCREEN_WIDTH 320    //px
#define SCREEN_HEIGHT 200   //px

#ifdef PRIVATE
#undef PRIVATE
#define PRIVATE
#else
#define PRIVATE
#endif//PRIVATE

#ifdef PUBLIC
#undef PUBLIC
#define PUBLIC
#else
#define PUBLIC
#endif//PUBLIC

/* signs of our all functions. */

/**
 * @author Muhammed Yasinhan Yaşar
**/


PUBLIC int def_gfdInit(void);

PUBLIC void def_gfdDestroy(void);

PUBLIC void def_gfdDrawPixel(unsigned int x, unsigned int y);

PUBLIC void def_gfdSetPixelColor(unsigned char color);

PRIVATE typedef struct
{
    int steps;
    float index_x, index_y;
    float pixel_x0, pixel_y0;

} DDALineInfo;

PRIVATE DDALineInfo def_gfdInfoLine(float x0, float y0, float x1, float y1);

PRIVATE DDALineInfo def_gfdInfoLineStepY(float x0, float y0, float x1, float y1);

PRIVATE DDALineInfo def_gfdInfoLineWithoutCoordAbstraction(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);

PUBLIC void def_gfdDrawLine(float x0, float y0, float x1, float y1);

PUBLIC void def_gfdDrawLineWithoutCoordAbstraction(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);

PUBLIC void def_gfdDrawTriangle(float x0, float y0, float x1, float y1, float x2, float y2);

PUBLIC void def_gfdDrawTriangleFilled(float x0, float y0, float x1, float y1, float x2, float y2);

PUBLIC void def_gfdClear(void);

#ifdef __cplusplus
}
#endif

#endif//GFD_GFDDEF_H
