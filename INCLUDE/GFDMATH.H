#ifndef GFD_GFDMATH_H
#define GFD_GFDMATH_H

#ifdef __cplusplus
extern "C" {
#endif

float** m_projectionMatrix(float view_angle, float aspect_ratio, float near, float far);

float** m_identityMatrix();

float** m_xRotationMatrix(float angle);

float** m_yRotationMatrix(float angle);

float** m_zRotationMatrix(float angle);

float** m_multiplyMatrix4x4(float matrix1[4][4], float matrix2[4][4]);

float* mult(float vec[4], float projection_matrix[4][4]);

#ifdef __cplusplus
}
#endif

#endif//GFD_GFDMATH_H
