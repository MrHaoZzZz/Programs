#include <hasroots.h>

int hasroots(float a, float b, float c)
{
    return b*b - 4*a*c >= 0 ;
}