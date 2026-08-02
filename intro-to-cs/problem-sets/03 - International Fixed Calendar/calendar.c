#include <calendar.h>

int days2date( int days )
{
    return (days/28+1)*100 + days%28 ;
}

int date2days( int date )
{
    return (date/100-1)*28 + date%100 ;
}