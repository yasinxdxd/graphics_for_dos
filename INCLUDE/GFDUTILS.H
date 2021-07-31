#ifndef GFD_GFDUTILS_H
#define GFD_GFDUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 
 * @brief 
**/
typedef struct _Pair_int_int
{
    int first;
    int second;
} Pair_ii;

/**
 * @param NO_PARAMETER
 * @brief 
**/
unsigned int m_umax(unsigned int a, unsigned int b);

/**
 * @param NO_PARAMETER
 * @brief 
**/
int m_imax(int a, int b);

/**
 * @param NO_PARAMETER
 * @brief 
**/
float m_fmax(float a, float b);

/**
 * @param NO_PARAMETER
 * @brief 
**/
unsigned int m_umin(unsigned int a, unsigned int b);

/**
 * @param NO_PARAMETER
 * @brief 
**/
int m_imin(int a, int b);

/**
 * @param NO_PARAMETER
 * @brief 
**/
float m_fmin(float a, float b);

/**
 * @param NO_PARAMETER
 * @brief 
**/
int m_iabs(int a);

/**
 * @param NO_PARAMETER
 * @brief 
**/
float m_fabs(float a);

/**
 * @param NO_PARAMETER
 * @brief 
**/
float m_fround(float a);

#ifdef __cplusplus
}
#endif

#endif//GFD_GFDUTILS_H
