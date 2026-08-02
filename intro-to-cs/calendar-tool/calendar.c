#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int days_in_month[2][12] = { { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } ,
                             { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } } ;

int leap_year( int year )
{
    return ( year % 400 == 0 ) || ( year % 4 == 0 && year % 100 != 0 ) ;
}

void split_date( char *date , int *year , int *month , int *day )
{
    *year = ( date[0] - '0' ) * 1000 + ( date[1] - '0' ) * 100 +
            ( date[2] - '0' ) * 10 + ( date[3] - '0' ) ;
    *month = ( date[5] - '0' ) * 10 + ( date[6] - '0' ) ;
    *day = ( date[8] - '0' ) * 10 + ( date[9] - '0' ) ;
}

char *to_string( int year , int month , int day )
{
    char *date = (char *)malloc( 11 * sizeof(char) ) ;
    date[0] = ( year / 1000 ) + '0' ;
    date[1] = ( ( year / 100 ) % 10 ) + '0' ;
    date[2] = ( ( year / 10 ) % 10 ) + '0' ;
    date[3] = ( year % 10 ) + '0' ;
    date[4] = '-' ;
    date[5] = ( month / 10 ) + '0' ;
    date[6] = ( month % 10 ) + '0' ;
    date[7] = '-' ;
    date[8] = ( day / 10 ) + '0' ;
    date[9] = ( day % 10 ) + '0' ;
    date[10] = '\0' ;
    return date ;
}

int days_sum( int year , int month , int day )
{
    int sum = 0 ;
    for ( int y = 1 ; y < year ; y ++ )
        sum += 365 + leap_year(y) ;
    for ( int m = 1 ; m < month ; m ++ )
        sum += days_in_month[leap_year(year)][m - 1] ;
    sum += day ;
    return sum ;
}

int validate( char *date )
{
    if ( strlen( date ) != 10 ) return 1 ;
    if ( date[4] != '-' || date[7] != '-' ) return 1 ;
    for ( int i = 0 ; i < 10 ; i ++ )
    {
        if ( i == 4 || i == 7 ) continue ;
        if ( date[i] < '0' || date[i] > '9' ) return 1 ;
    }
    int year , month , day ;
    split_date( date , &year , &month , &day ) ;
    if ( month < 1 || month > 12 ) return 2 ;
    if ( day < 1 || day > days_in_month[leap_year(year)][month - 1] ) return 2 ;
    return 0 ;
}

char *shift( char *date , int n )
{
    int year , month , day ;
    split_date( date , &year , &month , &day ) ;
    day += n ;
    while ( day > days_in_month[leap_year(year)][month - 1] )
    {
        day -= days_in_month[leap_year(year)][month - 1] ;
        month ++ ;
        if ( month > 12 )
        {
            month = 1 ;
            year ++ ;
        }
    }
    while (day <= 0){
        month--;
        if (month < 1){
            month = 12;
            year--;
        }
        day += get_days_in_month(year, month);
    }
    return to_string( year , month , day ) ;
}

int diff( char *date1 , char *date2 )
{
    int year1 , month1 , day1 ;
    int year2 , month2 , day2 ;
    split_date( date1 , &year1 , &month1 , &day1 ) ;
    split_date( date2 , &year2 , &month2 , &day2 ) ;
    int days1 = days_sum( year1 , month1 , day1 ) ;
    int days2 = days_sum( year2 , month2 , day2 ) ;
    return days2 - days1 ;
}

int weekday( char *date )
{
    int year , month , day ;
    split_date( date , &year , &month , &day ) ;
    int days = days_sum( year , month , day ) ;
    return ( days + 6 ) % 7 ;
}

int workdays( char *date1 , char *date2 )
{
    int year1 , month1 , day1 ;
    int year2 , month2 , day2 ;
    split_date( date1 , &year1 , &month1 , &day1 ) ;
    split_date( date2 , &year2 , &month2 , &day2 ) ;
    int days1 = days_sum( year1 , month1 , day1 ) ;
    int days2 = days_sum( year2 , month2 , day2 ) ;
    int workdays = 0 ;
    for ( int d = days1 ; d <= days2 ; d ++ )
    {
        int w = ( d + 5 ) % 7 ;
        if ( w >= 0 && w <= 4 ) workdays ++ ;
    }
    return workdays ;
}

void monthcal( int year , int month )
{
    int total_days = days_in_month[leap_year(year)][month - 1];
    char *first_day_str = to_string(year, month, 1);
    int first_weekday = weekday(first_day_str);
    free(first_day_str);

    printf("Mon Tue Wed Thu Fri Sat Sun\n");

    for (int i = 0; i < first_weekday; i++) {
        printf("    ");
    }

    int current_col = first_weekday;
    for (int day = 1; day <= total_days; day++) {
        printf("%3d ", day);
        current_col++;

        if (current_col == 7) {
            printf("\n");
            current_col = 0;
        }
    }

    if (current_col != 0) {
        printf("\n");
    }
}