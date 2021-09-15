#include "GFDDEF.H"
#include "GFDUTILS.H"
//#include <stdio.h>
/* definitions of our all functions */

int def_gfdInit(void)
{
    asm volatile(
    "mov al, 0x13\n"       // 40x25 320x200 256 colors VGA 1
    "mov ah, 0x0\n"
    "int 0x10\n"           // apply configuration.
    );

    return 0;
}

void def_gfdDestroy(void)
{
    asm volatile(
    "mov ax, 0x03\n"	//80x16  text mode
    "int 0x10\n"
    );

    //system("cls");
}

void def_gfdDrawPixel(unsigned int x, unsigned int y)
{
    //if (x < 320 && x >= 0 && y < 200 && y >= 0)
    {
        asm volatile(
        "mov al, [0x3080]\n"
        "mov ah, 0x0C\n"        // to set the color.    
        "mov ecx, %0\n"          //x pos
        "mov edx, %1\n"          //y pos
        "int 0x10\n"            //draw pixel
        :"=g"(x),"=g"(y)        //parameters as output
        );
        
    }

}

void def_gfdSetPixelColor(unsigned char color)
{
    //printf("%d", color);
    asm(
    "mov bl, %0\n"         // pixel color(we set bx here to give the value to an spesific addres that i decided.)
    "mov [0x3080], bl\n"    // the addres is 0x3080. idk why
    "mov al, [0x3080]\n"    //REMOVABLEEEEEE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    "mov ah, 0x0C\n"        // to set the color.
    :"=g"(color)
    );

//"mov ah, 0x0C\n"       //change the color --> for color function.
}

DDALineInfo def_gfdInfoLine(float x0, float y0, float x1, float y1)
{
    DDALineInfo info;
    
    x0 += 1.f;
    y0 -= 1.f;
    x1 += 1.f;
    y1 -= 1.f;
    
    info.pixel_x0 = SCREEN_WIDTH * x0 / 2.f;
    info.pixel_y0 = -SCREEN_HEIGHT * y0 / 2.f;
    float pixel_x1 = SCREEN_WIDTH * x1 / 2.f;
    float pixel_y1 = -SCREEN_HEIGHT * y1 / 2.f;

    int delta_x = pixel_x1 - info.pixel_x0;
    int delta_y = pixel_y1 - info.pixel_y0;
    info.steps = m_imax(m_iabs(delta_x), m_iabs(delta_y));  //we need to get max delta value to avoid gaps between pixels.

    info.index_y = delta_y / (float)info.steps;
    info.index_x = delta_x / (float)info.steps;

    return info;

}

DDALineInfo def_gfdInfoLineStepY(float x0, float y0, float x1, float y1)
{
    DDALineInfo info;
    
    x0 += 1.f;
    y0 -= 1.f;
    x1 += 1.f;
    y1 -= 1.f;
    
    info.pixel_x0 = SCREEN_WIDTH * x0 / 2.f;
    info.pixel_y0 = -SCREEN_HEIGHT * y0 / 2.f;
    float pixel_x1 = SCREEN_WIDTH * x1 / 2.f;
    float pixel_y1 = -SCREEN_HEIGHT * y1 / 2.f;

    int delta_x = pixel_x1 - info.pixel_x0;
    int delta_y = pixel_y1 - info.pixel_y0;
    info.steps = m_iabs(delta_y); // we always get y as steps value, because we will rasterize horizontaly.

    info.index_y = delta_y / (float)info.steps;
    info.index_x = delta_x / (float)info.steps;

    return info;

}

DDALineInfo def_gfdInfoLineWithoutCoordAbstraction(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1)
{
    DDALineInfo info;
    
    info.pixel_x0 = x0;
    info.pixel_y0 = y0;
    float pixel_x1 = x1;
    float pixel_y1 = y1;

    int delta_x = pixel_x1 - info.pixel_x0;
    int delta_y = pixel_y1 - info.pixel_y0;
    info.steps = m_imax(m_iabs(delta_x), m_iabs(delta_y));  //we need to get max delta value to avoid gaps between pixels.

    info.index_y = delta_y / (float)info.steps;
    info.index_x = delta_x / (float)info.steps;

    return info;
}

void def_gfdDrawLine(float x0, float y0, float x1, float y1)
{
    DDALineInfo info = def_gfdInfoLine(x0, y0, x1, y1);

    unsigned int i;
    for(i = 0; i < info.steps; i++)
    {

#ifndef __dj_include_stdio_h_            
        def_gfdDrawPixel(m_fround(info.pixel_x0), m_fround(info.pixel_y0));
#endif
        info.pixel_x0 += info.index_x;
        info.pixel_y0 += info.index_y;
    }

}

void def_gfdDrawLineWithoutCoordAbstraction(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1)
{
    DDALineInfo info = def_gfdInfoLineWithoutCoordAbstraction(x0, y0, x1, y1);

    unsigned int i;
    for(i = 0; i < info.steps; i++)
    {

#ifndef __dj_include_stdio_h_          
        def_gfdDrawPixel(info.pixel_x0, info.pixel_y0);
#endif
        info.pixel_x0 += info.index_x;
        info.pixel_y0 += info.index_y;
    }
}

void def_gfdDrawTriangle(float x0, float y0, float x1, float y1, float x2, float y2)
{
    def_gfdDrawLine(x0, y0, x1, y1);
    def_gfdDrawLine(x1, y1, x2, y2);
    def_gfdDrawLine(x2, y2, x0, y0);
}

void def_gfdDrawTriangleFilled(float x0, float y0, float x1, float y1, float x2, float y2)
{
    // the y component of the point which is between other two points according to Y axes.
    // we need to have the line it doesn't contain that point.
    // what you're gonna find below is sorting lines up to down...
    float p1_x, p1_y, p2_x, p2_y, op_x, op_y;

    if(y0 < y1 && y0 > y2)
    {
        //point_y = y0;
        op_x = x0;
        op_y = y0;
        p1_x = x1;
        p1_y = y1;
        p2_x = x2;
        p2_y = y2;
    }
    else if(y0 < y2 && y0 > y1)
    {
        //point_y = y0;
        op_x = x0;
        op_y = y0;
        p1_x = x2;
        p1_y = y2;
        p2_x = x1;
        p2_y = y1;
    }
    else if(y1 < y0 && y1 > y2)
    {
        op_x = x1;
        op_y = y1;
        p1_x = x0;
        p1_y = y0;
        p2_x = x2;
        p2_y = y2;
    }
    else if(y1 < y2 && y1 > y0)
    {
        op_x = x1;
        op_y = y1;
        p1_x = x2;
        p1_y = y2;
        p2_x = x0;
        p2_y = y0;
    }
    else if(y2 < y1 && y2 > y0)
    {
        op_x = x2;
        op_y = y2;
        p1_x = x1;
        p1_y = y1;
        p2_x = x0;
        p2_y = y0;
    }
    else
    {
        op_x = x2;
        op_y = y2;
        p1_x = x0;
        p1_y = y0;
        p2_x = x1;
        p2_y = y1;
    }
    // FIXME: line1 has to be higher up. [OK fixed]
    DDALineInfo info_line1 = def_gfdInfoLineStepY(p1_x, p1_y, op_x, op_y); // up
    DDALineInfo info_line3 = def_gfdInfoLineStepY(op_x, op_y, p2_x, p2_y); // down
    DDALineInfo info_line2 = def_gfdInfoLineStepY(p1_x, p1_y, p2_x, p2_y); // middle

    int step = info_line1.steps + info_line3.steps;
    //printf("%d\n", step);
    //printf("%d\n", info_line2.steps);
    float arrx[step];
    float arry[step];

    //save x and y values of line1
    unsigned int i1;
    for(i1 = 0; i1 < info_line1.steps; i1++)
    {
        info_line1.pixel_x0 += info_line1.index_x;
        info_line1.pixel_y0 += info_line1.index_y;
        arrx[i1] = info_line1.pixel_x0;
        arry[i1] = info_line1.pixel_y0;
    }

    //save x and y values of line3
    unsigned int i3;
    for(i3 = 0; i3 < info_line3.steps; i3++)
    {
        info_line3.pixel_x0 += info_line3.index_x;
        info_line3.pixel_y0 += info_line3.index_y;
        unsigned int i = info_line1.steps + i3;
        arrx[i] = info_line3.pixel_x0;
        arry[i] = info_line3.pixel_y0;
    }

    unsigned int i;
    for(i = 0; i < step; i++)
    {
        info_line2.pixel_x0 += info_line2.index_x;
        info_line2.pixel_y0 += info_line2.index_y;
        
        def_gfdDrawLineWithoutCoordAbstraction(m_fround(info_line2.pixel_x0), m_fround(info_line2.pixel_y0), m_fround(arrx[i]), m_fround(info_line2.pixel_y0));
    }

}

void def_gfdClear(void)
{
    asm volatile(
    "mov al, 0x00\n"       // set for clear screen
    "mov ah, 0x06\n"       // set for clear screen
    "mov bh, 0x00\n"
    "mov cx, 0x00\n"
    "mov dx, 0x184F\n"
    //"rep stosw\n"          // clear video memory
    "int 0x10\n"           // apply configuration.
    );

}
