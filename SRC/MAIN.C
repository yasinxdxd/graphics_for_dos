#include "GFDOS.H"
#include "GFDUTILS.H"
#include "GFDLDR.H"
#include "GFDMATH.H"
#include <stdio.h>
int main(int argc, char* argv[])
{
	gfdInit();

    

    gfdSTLHeader header;
    gfdSTLTriangle* triangles;

    triangles = gfdLoadSTL("../RES/cubcub.stl", &header);

    m_Vec* vertex_pos1 = m_createVector(3);
    m_Vec* vertex_pos2 = m_createVector(3);
    m_Vec* vertex_pos3 = m_createVector(3);

    vertex_pos1->data[0] = -0.1f;
    vertex_pos1->data[1] = -0.1f;
    vertex_pos1->data[2] = 0.0f;

    vertex_pos2->data[0] = 0.1f;
    vertex_pos2->data[1] = -0.1f;
    vertex_pos2->data[2] = 0.0f;

    vertex_pos3->data[0] = 0.0f;
    vertex_pos3->data[1] = 0.1f;
    vertex_pos3->data[2] = 0.0f;
    
    m_Matrix* projection_matrix = m_createMatrix(4, 4);
    m_Matrix* z_rotation_matrix = m_createMatrix(4, 4);
    m_Matrix* MVP = m_createMatrix(4, 4);





    float a = 0.5f;
    float b = 0.1f;
    while(b < 1)
    {

        m_identityMatrix(projection_matrix);
        m_identityMatrix(z_rotation_matrix);
        m_identityMatrix(MVP);

        m_projectionMatrix(projection_matrix, DEGREE2RADIAN(45.f), 320/200, 0.1f, 100.f);
        m_zRotationMatrix(z_rotation_matrix, DEGREE2RADIAN(b));
        m_multiplyMatrix4x4(MVP, projection_matrix, z_rotation_matrix);
        
        m_mult(MVP, vertex_pos1);
        m_mult(MVP, vertex_pos2);
        m_mult(MVP, vertex_pos3);

        gfdSetPixelColor(GFD_CLR_LIGHT_BLUE);
        gfdDrawTriangle(vertex_pos1->data[0], vertex_pos1->data[1],
                        vertex_pos2->data[0], vertex_pos2->data[1],
                        vertex_pos3->data[0], vertex_pos3->data[1]);

        gfdSetPixelColor(GFD_CLR_BLACK);
        gfdClear();

        

        b += 0.1;

    }


    



    m_destroyMatrix(projection_matrix);
    m_destroyMatrix(z_rotation_matrix);
    m_destroyMatrix(MVP);

    m_destroyVector(vertex_pos1);
    m_destroyVector(vertex_pos2);
    m_destroyVector(vertex_pos3);



    /*printf("%f\n%f\n%f\n%f\n%f\n%f\n", vertex1[0], vertex1[1],
                                        vertex2[0], vertex2[1],
                                        vertex3[0], vertex3[2]);*/
    free(triangles);


    //gfdDestroy();

    return 0;
}




/*
    //DRAW A CIRCLE:
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
