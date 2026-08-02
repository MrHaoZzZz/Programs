#include <iostream>

using namespace std ;

struct a
{
	int number , study , other ;
	double point ;
} student[1005] ;
int n ;

int main()
{
	cin >> n ;
	for ( int i = 0 ; i < n ; i ++ )
	{
		cin >> student[i].number >> student[i].study >> student[i].other ;
		student[i].point = 0.7*student[i].study + 0.3* student[i].other ;
	}
	
	for ( int i = 0 ; i < n ; i ++ )
	{
		if ( student[i].study + student[i].other > 140 && student[i].point >= 80 )
		{
			cout << "Excellent" << endl ;
		}
		else
		{
			cout << "Not excellent" << endl ;
		}
	}
	return 0 ;
}