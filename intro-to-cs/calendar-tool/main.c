#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int validate(char *date);
char *shift(char *date, int n);
int diff(char *date1, char *date2);
int weekday(char *date);
int workdays(char *date1, char *date2);
void monthcal(int year, int month);

int main( int argc , char* argv[])
{
    const char *command = argv[1] ;

    if (strcmp(command, "validate") == 0){
        // validate
        int res = validate( argv[2] ) ;
        if ( res == 0 ) {
            printf("valid date\n");
        } else if ( res == 1 ) {
            printf("invalid format\n");
        }
        else if ( res == 2 ) {
            printf("invalid date\n");
        }
    } else if (strcmp(command, "shift") == 0) {
        // shift
        printf("%s\n", shift( argv[2] , atoi(argv[3]) ) );
    } else if (strcmp(command, "diff") == 0) {
        // diff
        printf("%d\n", diff( argv[2] , argv[3] ) );
    } else if (strcmp(command, "weekday") == 0) {
        // weekday
        switch ( weekday( argv[2] ) ) {
            case 0:
                printf("Mon\n");
                break;
            case 1:
                printf("Tue\n");
                break;
            case 2:
                printf("Wed\n");
                break;
            case 3:
                printf("Thu\n");
                break;
            case 4:
                printf("Fri\n");
                break;
            case 5:
                printf("Sat\n");
                break;
            case 6:
                printf("Sun\n");
                break;
        }
    } else if (strcmp(command, "workdays") == 0) {
        // workdays
        printf("%d\n", workdays( argv[2] , argv[3] ) );
    } else if (strcmp(command, "monthcal") == 0) {
        // monthcal
        monthcal( atoi(argv[2]) , atoi(argv[3]) ) ;
    } else {
        printf("Invalid command.\n");
    }
    return 0 ;
}