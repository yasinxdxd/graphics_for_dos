#ifndef GFD_GFDMATH_H
#define GFD_GFDMATH_H

#ifdef __cplusplus
extern "C" {
#endif

#define M_PI 3.14159265359
#define RADIAN2DEGREE(R) R * 180.f / M_PI 
#define DEGREE2RADIAN(D) D * M_PI / 180.f

typedef struct
{
    union
    {
        struct
        {
            float _00, _01, _02, _03;
            float _10, _11, _12, _13;
            float _20, _21, _22, _23;
            float _30, _31, _32, _33;
        };
        float data[4][4];
    };
} Mat4x4;

typedef struct
{
    union
    {
        struct
        {
            float x, y;
        };
        float data[2];
    };
} Vec2;

typedef struct
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float data[3];
    };
} Vec3;

typedef struct
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        float data[4];
    };
} Vec4;

m_Matrix* m_createMatrix(unsigned short rows, unsigned short cols);

void m_destroyMatrix(m_Matrix* matrix);

m_Vec* m_createVector(unsigned short dimension);

void m_destroyVector(m_Vec* matrix);

void m_projectionMatrix(m_Matrix* matrix, float view_angle, float aspect_ratio, float near, float far);

void m_identityMatrix(m_Matrix* matrix);

void m_xRotationMatrix(m_Matrix* matrix, float angle);

void m_yRotationMatrix(m_Matrix* matrix, float angle);

void m_zRotationMatrix(m_Matrix* matrix, float angle);

void m_multiplyMatrix4x4(m_Matrix* result, m_Matrix* matrix1, m_Matrix* matrix2);

void m_mult(m_Matrix* matrix, m_Vec* vec);

#ifdef __cplusplus
}
#endif

#endif//GFD_GFDMATH_H
