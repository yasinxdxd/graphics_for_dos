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

/**
 * @param NO_PARAMETER
**/
int dec_gfdInit(void);

/**
 * @param NO_PARAMETER
**/
void dec_gfdDestroy(void);

/**
 * @param NO_PARAMETER
**/
void dec_gfdDrawPixel(unsigned int x, unsigned int y);

/**
 * @param NO_PARAMETER
 * @brief 
**/
void dec_gfdSetPixelColor(unsigned char color);

/**
 * @brief Line information for drawing a line with DDA Line Algorithm.
**/
typedef struct
{
    int steps;
    float index_x, index_y;
    float pixel_x0, pixel_y0;

} DDALineInfo;

/**
 * @param NO_PARAMETER
**/
DDALineInfo dec_gfdInfoLine(float x0, float y0, float x1, float y1);

/**
 * @param NO_PARAMETER
**/
DDALineInfo dec_gfdInfoLineWithoutCoordAbstraction(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);

/**
 * @param NO_PARAMETER
**/
void dec_gfdDrawLine(float x0, float y0, float x1, float y1);

/**
 * @param NO_PARAMETER
**/
void dec_gfdDrawLineWithoutCoordAbstraction(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);

/**
 * @param NO_PARAMETER
**/
void dec_gfdDrawTriangle(float x0, float y0, float x1, float y1, float x2, float y2);

/**
 * @param NO_PARAMETER
**/
void dec_gfdDrawTriangleFilled(float x0, float y0, float x1, float y1, float x2, float y2);

/**
 * @param NO_PARAMETER
**/
void dec_gfdClear(void);

#ifdef __cplusplus
}
#endif

#endif//GFD_GFDDEF_H
