#include <iostream>
#include <cmath>

using namespace std ;

struct a
{
	char name[10] ;
	int chinese , math , english ;
	int total ;
} student[1005] ;

int n ;

int main()
{
	cin >> n ;
	for ( int i = 0 ; i < n ; i ++ )
	{
		cin >> student[i].name >> student[i].chinese >> student[i].math >> student[i].english ;
		student[i].total = student[i].chinese + student[i].english + student[i].math ;
	}
	
	for ( int i = 0 ; i < n ; i ++ )
	{
		for ( int j = i+1 ; j < n ; j ++ )
		{
			if ( abs( student[i].chinese - student[j].chinese ) <= 5 && abs( student[i].english - student[j].english ) <= 5
			&& abs( student[i].math - student[j].math ) <= 5 && abs( student[i].total - student[j].total ) <= 10 )
			{
				cout << student[i].name << ' ' << student[j].name << endl ;
			}
		}
	}
	return 0 ;
}