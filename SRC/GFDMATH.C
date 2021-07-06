#include "GFDMATH.H"
#include <math.h>

float** m_projectionMatrix(float view_angle, float aspect_ratio, float near, float far)
{
    float projection_matrix[4][4] = 
    {
        {1 / (aspect_ratio * tanf(view_angle / 2)), 0, 0, 0},
        {0, 1 / (tanf(view_angle / 2)), 0, 0},
        {0, 0, ((-far - near) / (far - near)), ((-2 * far * near) / (far - near))},
        {0, 0, -1, 0}
    };
    return projection_matrix;
}

float** m_identityMatrix()
{
    float identity_matrix[4][4] = 
    {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    return identity_matrix;
}

float** m_xRotationMatrix(float angle)
{
    float x_rotation_matrix[4][4] = 
    {
        {1, 0, 0, 0},
        {0, cosf(angle), -sinf(angle), 0},
        {0, sinf(angle), cosf(angle), 0},
        {0, 0, 0, 1}
    };
    return x_rotation_matrix;
}

float** m_yRotationMatrix(float angle)
{
    float y_rotation_matrix[4][4] = 
    {
        {cosf(angle), 0, sinf(angle), 0},
        {0, 1, 0, 0},
        {-sinf(angle), 0, cosf(angle), 0},
        {0, 0, 0, 1}
    };
    return y_rotation_matrix;
}

float** m_zRotationMatrix(float angle)
{
    float z_rotation_matrix[4][4] = 
    {
        {cosf(angle), -sinf(angle), 0, 0},
        {sinf(angle), cosf(angle), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    return z_rotation_matrix;
}

float** m_multiplyMatrix4x4(float matrix1[4][4], float matrix2[4][4])
{
    float result[4][4];

    unsigned int i;
    for(i = 0; i < 4; i++)
    {
        unsigned int j;
        for(j = 0; j < 4; j++)
        {
            result[i][j] = 0;
            unsigned int k;
            for(k = 0; k < 4; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

float* mult(float vec[4], float projection_matrix[4][4])
{
    float result[4] = 
    {
        projection_matrix[0][0] * vec[0],
        projection_matrix[1][1] * vec[1],
        (projection_matrix[2][2] * vec[2]) + (projection_matrix[2][3] * vec[3]),
        projection_matrix[3][2] * vec[2]
    };

    return result;
}

