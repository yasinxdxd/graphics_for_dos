#include "GFDMATH.H"
#include <math.h>
#include <stdlib.h>


m_Matrix* m_createMatrix(unsigned short rows, unsigned short cols)
{
    m_Matrix* matrix = (m_Matrix*)malloc(sizeof(m_Matrix));
    matrix->rows = rows;
    matrix->cols = cols;

    return matrix;
}

void m_destroyMatrix(m_Matrix* matrix)
{
    free(matrix);
    matrix = NULL;
}

m_Vec* m_createVector(unsigned short dimension)
{
    m_Vec* vector = (m_Vec*)malloc(sizeof(m_Vec));
    vector->dim = dimension; 

    return vector;
}

void m_destroyVector(m_Vec* vector)
{
    free(vector);
    vector = NULL;
}

void m_projectionMatrix(m_Matrix* matrix, float view_angle, float aspect_ratio, float near, float far)
{
    matrix->data[0][0] = 1 / (aspect_ratio * tanf(view_angle / 2));
    matrix->data[0][1] = 0;
    matrix->data[0][2] = 0;
    matrix->data[0][3] = 0;
    matrix->data[1][0] = 0;
    matrix->data[1][1] = 1 / (tanf(view_angle / 2));
    matrix->data[1][2] = 0;
    matrix->data[1][3] = 0;
    matrix->data[2][0] = 0;
    matrix->data[2][1] = 0;
    matrix->data[2][2] = ((-far - near) / (far - near));
    matrix->data[2][3] = ((-2 * far * near) / (far - near));
    matrix->data[3][0] = 0;
    matrix->data[3][1] = 0;
    matrix->data[3][2] = -1;
    matrix->data[3][3] = 0;
    /*
    {
        {1 / (aspect_ratio * tanf(view_angle / 2)), 0, 0, 0},
        {0, 1 / (tanf(view_angle / 2)), 0, 0},
        {0, 0, ((-far - near) / (far - near)), ((-2 * far * near) / (far - near))},
        {0, 0, -1, 0}
    };
    */
}

void m_identityMatrix(m_Matrix* matrix)
{
    matrix->data[0][0] = 1;
    matrix->data[0][1] = 0;
    matrix->data[0][2] = 0;
    matrix->data[0][3] = 0;
    matrix->data[1][0] = 0;
    matrix->data[1][1] = 1;
    matrix->data[1][2] = 0;
    matrix->data[1][3] = 0;
    matrix->data[2][0] = 0;
    matrix->data[2][1] = 0;
    matrix->data[2][2] = 1;
    matrix->data[2][3] = 0;
    matrix->data[3][0] = 0;
    matrix->data[3][1] = 0;
    matrix->data[3][2] = 0;
    matrix->data[3][3] = 1;

}

void m_xRotationMatrix(m_Matrix* matrix, float angle)
{
    /*
    float x_rotation_matrix[4][4] = 
    {
        {1, 0, 0, 0},
        {0, cosf(angle), -sinf(angle), 0},
        {0, sinf(angle), cosf(angle), 0},
        {0, 0, 0, 1}
    };
    */
}

void m_yRotationMatrix(m_Matrix* matrix, float angle)
{
    
    matrix->data[0][0] = cosf(angle);
    matrix->data[0][1] = 0;
    matrix->data[0][2] = sinf(angle);
    matrix->data[0][3] = 0;
    matrix->data[1][0] = 0;
    matrix->data[1][1] = 1;
    matrix->data[1][2] = 0;
    matrix->data[1][3] = 0;
    matrix->data[2][0] = -sinf(angle);
    matrix->data[2][1] = 0;
    matrix->data[2][2] = cosf(angle);
    matrix->data[2][3] = 0;
    matrix->data[3][0] = 0;
    matrix->data[3][1] = 0;
    matrix->data[3][2] = 0;
    matrix->data[3][3] = 1;
    
}

void m_zRotationMatrix(m_Matrix* matrix, float angle)
{

    matrix->data[0][0] = cosf(angle);
    matrix->data[0][1] = -sinf(angle);
    matrix->data[0][2] = 0;
    matrix->data[0][3] = 0;
    matrix->data[1][0] = sinf(angle);
    matrix->data[1][1] = cosf(angle);
    matrix->data[1][2] = 0;
    matrix->data[1][3] = 0;
    matrix->data[2][0] = 0;
    matrix->data[2][1] = 0;
    matrix->data[2][2] = 1;
    matrix->data[2][3] = 0;
    matrix->data[3][0] = 0;
    matrix->data[3][1] = 0;
    matrix->data[3][2] = 0;
    matrix->data[3][3] = 1;
}

void m_multiplyMatrix4x4(m_Matrix* result, m_Matrix* matrix1, m_Matrix* matrix2)
{

    unsigned int i;
    for(i = 0; i < 4; i++)
    {
        unsigned int j;
        for(j = 0; j < 4; j++)
        {
            result->data[i][j] = 0;
            unsigned int k;
            for(k = 0; k < 4; k++)
            {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }

}

///x y z 1

///a b c d
///e f g h
///i j k l
///m n o p

void m_mult(m_Matrix* matrix, m_Vec* vec)
{
    vec->data[0] = matrix->data[0][0] * vec->data[0] + matrix->data[0][1] * vec->data[1] + matrix->data[0][2] * vec->data[2] + matrix->data[0][3];
    vec->data[1] = matrix->data[1][0] * vec->data[0] + matrix->data[1][1] * vec->data[1] + matrix->data[1][2] * vec->data[2] + matrix->data[1][3];
    vec->data[2] = matrix->data[2][0] * vec->data[0] + matrix->data[2][1] * vec->data[1] + matrix->data[2][2] * vec->data[2] + matrix->data[2][3];
    //matrix->data[3][2] * vec[2];
}

