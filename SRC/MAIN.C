#include "GFDOS.H"
#include "GFDUTILS.H"
#include "GFDLDR.H"
#include <math.h>
//#include <stdio.h>
int main(int argc, char* argv[])
{
		
	gfdInit();
    //printf("%c\n", argv[1]);
    //gfdDrawPixel(111, 150);

    /*
    float vertices[] = 
    {
        -0.5, 0.0, 0.0,
        0,5, 0.0, 0.0,
        0.0, 0.5, 0.0
    };*/

    gfdSetPixelColor(GFD_CLR_LIGHT_BLUE);

    //gfdDrawLine(0, 0, 320, 200);
    

    gfdSTLHeader header;
    gfdSTLTriangle* triangles;

    triangles = gfdLoadSTL("../RES/cubcub.stl", &header);

    //printf("%d", sizeof(*triangles));

    //printf("%f", triangles[0].vertex1[0]);

    
    unsigned int i;
    for(i = 0; i < header.triangles_number; i++)
    {
        
        gfdDrawTriangle(triangles[i].vertex1[0], triangles[i].vertex1[1],
                        triangles[i].vertex2[0], triangles[i].vertex2[1],
                        triangles[i].vertex3[0], triangles[i].vertex3[1]);
    }
    

    free(triangles);

    //gfdDrawTriangle(10, 25, 14, 80, 47, 61);
    /*
    float x = 100, y = 100;
    float x1 = 100, y1 = 100;
    float r = 1;

    unsigned int i;
    for(i = 0; i <= 360; i++)
    {
        x1 += sinf(i * 3.14 / 180) * (r);
        y1 += cosf(i * 3.14 / 180) * (r);
        //gfdDrawPixel(i, i);
        if(argv[1] == 0)
			gfdDrawLine((unsigned int)m_fround(x), (unsigned int)m_fround(y), (unsigned int)m_fround(x1), (unsigned int)m_fround(y1));	
		else
			gfdDrawPixel((unsigned int)x1, (unsigned int)y1);
    }
	*/
    

    gfdDestroy();

    return 0;
}
