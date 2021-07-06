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
    "mov al, 0x03\n"
    "int 0x21\n"
    );

    //system("cls");
}

void dec_gfdDrawPixel(unsigned int x, unsigned int y)
{
    //if (x <= SCREEN_WIDTH && x >= 0 && y <= SCREEN_HEIGHT && y >= 0)
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

//"mov ah, 0x0C\n"       //change the color --> for color function.

void dec_gfdDrawLine(float x0, float y0, float x1, float y1)
{
    //DDA line algorithm
    int delta_x = x1 - x0;
    int delta_y = y1 - y0;
    int steps = m_imax(m_iabs(delta_x), m_iabs(delta_y));  //we need to get max delta value to avoid gaps between pixels.

    float index_x, index_y;

    float pixel_x = x0, pixel_y = y0;
    
    index_y = delta_y / (float)steps;
    index_x = delta_x / (float)steps;

#ifdef __dj_include_stdio_h_
        printf("steps:%d\n", steps);
        printf("ix:%f\n", index_x);
        printf("iy:%f\n", index_y);
        printf("fix:%d\n", (int)m_fround(index_x));
        printf("fiy:%d\n", (int)m_fround(index_y));
		printf("7.9:%d\n", (int)m_fround(7.9));
#endif

        unsigned int i;
        for(i = 1; i <= steps; i++)
        {
#ifndef __dj_include_stdio_h_            
            dec_gfdDrawPixel(m_fround(pixel_x), m_fround(pixel_y));
#endif
            pixel_x += index_x;
            pixel_y += index_y;
        }

}


void dec_gfdDrawTriangle(float x0, float y0, float x1, float y1, float x2, float y2)
{
    dec_gfdDrawLine(x0, y0, x1, y1);
    dec_gfdDrawLine(x1, y1, x2, y2);
    dec_gfdDrawLine(x2, y2, x0, y0);
}
