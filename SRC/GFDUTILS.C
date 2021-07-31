#include "GFDUTILS.H"

unsigned int m_umax(unsigned int a, unsigned int b)
{
    unsigned int result;
    return result = a > b ? a : b;
}

int m_imax(int a, int b)
{
    int result;
    return result = a > b ? a : b;
}

float m_fmax(float a, float b)
{
    float result;
    return result = a > b ? a : b;
}

unsigned int m_umin(unsigned int a, unsigned int b)
{
    unsigned int result;
    return result = a < b ? a : b;
}

int m_imin(int a, int b)
{
    int result;
    return result = a < b ? a : b;
}

float m_fmin(float a, float b)
{
    float result;
    return result = a < b ? a : b;
}

int m_iabs(int a)
{
    return a = a < 0 ? -a : a;
}

float m_fabs(float a)
{
    return a = a < 0 ? -a : a;
}

float m_fround(float a)
{
    int round_down = (int)a;
    return a = (a - round_down) > 0.5f ? round_down + 1 : round_down;
}
