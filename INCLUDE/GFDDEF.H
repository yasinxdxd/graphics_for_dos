#ifndef GFD_GFDDEF_H
#define GFD_GFDDEF_H

#ifdef __cplusplus
extern "C" {
#endif

#define SCREEN_WIDTH 320    //px
#define SCREEN_HEIGHT 200   //px

/* signs of our all functions. */

/**
 * @author Muhammed Yasinhan Yaşar
**/

/**
 * @param NO_PARAMETER
**/
int dec_gfdInit();

/**
 * @param NO_PARAMETER
**/
void dec_gfdDestroy();

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
 * @param NO_PARAMETER
**/
void dec_gfdDrawLine(float x0, float y0, float x1, float y1);

/**
 * @param NO_PARAMETER
**/
void dec_gfdDrawTriangle(float x0, float y0, float x1, float y1, float x2, float y2);

#ifdef __cplusplus
}
#endif

#endif//GFD_GFDDEF_H
