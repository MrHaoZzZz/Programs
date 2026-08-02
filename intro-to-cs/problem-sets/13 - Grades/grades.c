#include <grades.h>

char number_to_letter( int grade )
{
    if ( grade >= 90 && grade <= 100 ) return 'A' ;
    if ( grade >= 80 && grade < 90 ) return 'B' ;
    if ( grade >= 70 && grade < 80 ) return 'C' ;
    if ( grade >= 60 && grade < 70 ) return 'D' ;
    return 'F' ;
}

int letter_to_number( char grade )
{
    if ( grade == 'A' ) return 100 ;
    if ( grade == 'B' ) return 89 ;
    if ( grade == 'C' ) return 79 ;
    if ( grade == 'D' ) return 69 ;
    return 59 ;
}

int rounding( int grade )
{
    if ( grade % 10 >= 5 ) return (grade/10+1)*10 ;
    return grade/10 + 1 ;
}