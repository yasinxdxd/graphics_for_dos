#include "GFDOS.H"
#include "GFDUTILS.H"
#include "GFDLDR.H"
#include "GFDMATH.H"
#include <math.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	gfdInit();

    

    gfdSTLHeader header;
    gfdSTLTriangle* triangles;

    triangles = gfdLoadSTL("../RES/cubcub2.stl", &header);

    float alpha = DEGREE2RADIAN(45.f);
    float n = (1) / (2 * tanf(alpha / 2));
    float aspect_ratio = 320.f / 200.f;
    
    int a = 0;
    while(a < 1000)
    {
        a++;

        //CLEAR THE SCREEN
        //gfdSetPixelColor(GFD_CLR_BLACK);
        //gfdClear();
        

        gfdSetPixelColor(GFD_CLR_INTENSE_WHITE);
        unsigned int i;
        for(i = 0; i < header.triangles_number; i++)
        {   
            //PROJECTION
            triangles[i].vertex1[0] *= (-n / (triangles[i].vertex1[2] * aspect_ratio));
            triangles[i].vertex1[1] *= (-n / (triangles[i].vertex1[2]));

            triangles[i].vertex2[0] *= (-n / (triangles[i].vertex2[2] * aspect_ratio));
            triangles[i].vertex2[1] *= (-n / (triangles[i].vertex2[2]));

            triangles[i].vertex3[0] *= (-n / (triangles[i].vertex3[2] * aspect_ratio));
            triangles[i].vertex3[1] *= (-n / (triangles[i].vertex3[2]));

            //ROTATION
            

            //DRAWING
            gfdDrawTriangle(triangles[i].vertex1[0], triangles[i].vertex1[1],
                            triangles[i].vertex2[0], triangles[i].vertex2[1],
                            triangles[i].vertex3[0], triangles[i].vertex3[1]);

        }
    }

    


    gfdFreeSTL(triangles);
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


//MATRICES ...
/*
    m_Matrix* projection_matrix = m_createMatrix(4, 4);
    m_Matrix* z_rotation_matrix = m_createMatrix(4, 4);
    m_Matrix* MVP = m_createMatrix(4, 4);


    m_identityMatrix(projection_matrix);
    m_identityMatrix(z_rotation_matrix);
    m_identityMatrix(MVP);

    m_projectionMatrix(projection_matrix, DEGREE2RADIAN(45.f), 320/200, 0.1f, 100.f);
    m_zRotationMatrix(z_rotation_matrix, DEGREE2RADIAN(120));
    m_multiplyMatrix4x4(MVP, projection_matrix, z_rotation_matrix);
    
    m_mult(MVP, vertex_pos1);
    m_mult(MVP, vertex_pos2);
    m_mult(MVP, vertex_pos3);

    gfdSetPixelColor(GFD_CLR_LIGHT_BLUE);
    gfdDrawTriangle(vertex_pos1->data[0], vertex_pos1->data[1],
                    vertex_pos2->data[0], vertex_pos2->data[1],
                    vertex_pos3->data[0], vertex_pos3->data[1]);

    //gfdSetPixelColor(GFD_CLR_BLACK);
    //gfdClear();




    m_destroyMatrix(projection_matrix);
    m_destroyMatrix(z_rotation_matrix);
    m_destroyMatrix(MVP);
    */


/*

    m_Vec* vertex_pos1 = m_createVector(4);
    m_Vec* vertex_pos2 = m_createVector(4);
    m_Vec* vertex_pos3 = m_createVector(4);

    vertex_pos1->data[0] = -0.1f;
    vertex_pos1->data[1] = -0.1f;
    vertex_pos1->data[2] = -1.f;
    //vertex_pos1->data[3] = 1.0f;

    vertex_pos2->data[0] = 0.1f;
    vertex_pos2->data[1] = -0.1f;
    vertex_pos2->data[2] = -1.f;
    //vertex_pos2->data[3] = 1.0f;

    vertex_pos3->data[0] = 0.0f;
    vertex_pos3->data[1] = 0.1f;
    vertex_pos3->data[2] = -1.f;
    //vertex_pos3->data[3] = 1.0f;

    
    float alpha = DEGREE2RADIAN(60.f);
    float n = (1) / (2 * tanf(alpha / 2));
    

    //X:
    vertex_pos1->data[0] *= (-n / (vertex_pos1->data[2] * 320 / 200));
    vertex_pos2->data[0] *= (-n / (vertex_pos2->data[2] * 320 / 200));
    vertex_pos3->data[0] *= (-n / (vertex_pos3->data[2] * 320 / 200));

    //Y:
    vertex_pos1->data[1] *= (-n / vertex_pos1->data[2]);
    vertex_pos2->data[1] *= (-n / vertex_pos2->data[2]);
    vertex_pos3->data[1] *= (-n / vertex_pos3->data[2]);


    m_destroyVector(vertex_pos1);
    m_destroyVector(vertex_pos2);
    m_destroyVector(vertex_pos3);


*/
