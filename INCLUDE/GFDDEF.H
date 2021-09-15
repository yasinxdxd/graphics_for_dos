#ifndef GFD_GFDDEF_H
#define GFD_GFDDEF_H

#ifdef __cplusplus
extern "C" {
#endif

#define SCREEN_WIDTH 320    //px
#define SCREEN_HEIGHT 200   //px

#define PRIVATE

/* signs of our all functions. */

/**
 * @author Muhammed Yasinhan Yaşar
**/


int def_gfdInit(void);

void def_gfdDestroy(void);

void def_gfdDrawPixel(unsigned int x, unsigned int y);

void def_gfdSetPixelColor(unsigned char color);

typedef struct
{
    int steps;
    float index_x, index_y;
    float pixel_x0, pixel_y0;

} DDALineInfo;

DDALineInfo def_gfdInfoLine(float x0, float y0, float x1, float y1);

DDALineInfo def_gfdInfoLineStepY(float x0, float y0, float x1, float y1);

DDALineInfo def_gfdInfoLineWithoutCoordAbstraction(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);

void def_gfdDrawLine(float x0, float y0, float x1, float y1);

void def_gfdDrawLineWithoutCoordAbstraction(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);

void def_gfdDrawTriangle(float x0, float y0, float x1, float y1, float x2, float y2);

void def_gfdDrawTriangleFilled(float x0, float y0, float x1, float y1, float x2, float y2);

void def_gfdClear(void);

#ifdef __cplusplus
}
#endif

#endif//GFD_GFDDEF_H
