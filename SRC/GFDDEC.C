#include "GFDDEF.H"
#include "GFDUTILS.H"
//#include <stdio.h>
/* declarations of our all functions */

int dec_gfdInit()
{
    asm volatile(
    "mov al, 0x13\n"       // 40x25 320x200 256 colors VGA 1
    "mov ah, 0x0\n"
    "int 0x10\n"           // apply configuration.
    );

    return 0;
}

void dec_gfdDestroy()
{
    asm volatile(
    "mov ax, 0x03\n"	//80x16  text mode
    "int 0x10\n"
    );

    //system("cls");
}

void dec_gfdDrawPixel(unsigned int x, unsigned int y)
{
    //if (x < 320 && x >= 0 && y < 200 && y >= 0)
    {
        asm volatile(
        "mov al, [0x3080]\n"
        "mov ah, 0x0C\n"        // to set the color.    
        "mov cx, %0\n"          //x pos
        "mov dx, %1\n"          //y pos
        "int 0x10\n"            //draw pixel
        :"=g"(x),"=g"(y)        //parameters as output
        );
        
    }

}

void dec_gfdSetPixelColor(unsigned char color)
{
    //printf("%d", color);
    asm(
    "mov bl, %0\n"         // pixel color(we set bx here to give the value to an spesific addres that i decided.)
    "mov [0x3080], bl\n"    // the addres is 0x3080. idk why
    "mov al, [0x3080]\n"    //REMOVABLEEEEEE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    "mov ah, 0x0C\n"        // to set the color.
    :"=g"(color)
    );

}

struct PRIVATE _dec_Rasterizer
{
    Pair_ii* xy;
    unsigned int size;

} _Rasterizer;



//"mov ah, 0x0C\n"       //change the color --> for color function.

void dec_gfdDrawLine(float x0, float y0, float x1, float y1)
{
    //DDA line algorithm

    float index_x, index_y;
    
    x0 += 1.f;
    y0 -= 1.f;
    x1 += 1.f;
    y1 -= 1.f;
    
    float pixel_x0 = SCREEN_WIDTH * x0 / 2.f;
    float pixel_y0 = -SCREEN_HEIGHT * y0 / 2.f;
    float pixel_x1 = SCREEN_WIDTH * x1 / 2.f;
    float pixel_y1 = -SCREEN_HEIGHT * y1 / 2.f;

    int delta_x = pixel_x1 - pixel_x0;
    int delta_y = pixel_y1 - pixel_y0;
    int steps = m_imax(m_iabs(delta_x), m_iabs(delta_y));  //we need to get max delta value to avoid gaps between pixels.

    index_y = delta_y / (float)steps;
    index_x = delta_x / (float)steps;


#ifdef __dj_include_stdio_h_
        /*printf("steps:%d\n", steps);
        printf("ix:%f\n", index_x);
        printf("iy:%f\n", index_y);
        printf("fix:%d\n", (int)m_fround(index_x));
        printf("fiy:%d\n", (int)m_fround(index_y));
		printf("7.9:%d\n", (int)m_fround(7.9));*/
#endif

    Pair_ii x_and_y_values[steps];

    unsigned int i;
    for(i = 1; i <= steps; i++)
    {
        Pair_ii x_and_y;
        x_and_y.first = m_fround(pixel_x0);
        x_and_y.second = m_fround(pixel_y0);
        x_and_y_values[i-1] = x_and_y;

#ifndef __dj_include_stdio_h_            
        dec_gfdDrawPixel(m_fround(pixel_x0), m_fround(pixel_y0));
#endif
        pixel_x0 += index_x;
        pixel_y0 += index_y;
    }

    _Rasterizer.size = steps;
    _Rasterizer.xy = &x_and_y_values[0];

}


void dec_gfdDrawTriangle(float x0, float y0, float x1, float y1, float x2, float y2)
{
    dec_gfdDrawLine(x0, y0, x1, y1);
    dec_gfdDrawLine(x1, y1, x2, y2);
    dec_gfdDrawLine(x2, y2, x0, y0);
}

void dec_gfdDrawTriangleFilled(float x0, float y0, float x1, float y1, float x2, float y2)
{

}

void dec_gfdClear()
{
    /*
    asm volatile(
    "mov al, 0x13\n"       // 40x25 320x200 256 colors VGA 1
    "mov ah, 0x0\n"
    "int 0x10\n"           // apply configuration.
    );
    */
    unsigned int i = 0;
    for(i = 0; i < SCREEN_WIDTH; i++)
    {
        unsigned int j = 0;
        for(j = 0; j < SCREEN_HEIGHT; j++)
        {
            dec_gfdDrawPixel(i, j);
        }
    }
}
