#include <iostream>

using namespace std ;

struct student
{
    string name ;
    int age , score ;
} stu[10] ;

int main()
{
    int n ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> stu[i].name >> stu[i].age >> stu[i].score ;
    }
    for ( int i = 0 ; i < n ; i ++ )
    {
        cout << stu[i].name << " " << stu[i].age + 1 << " " << ( ( stu[i].score * 1.2 > 600 ) ? 600 : ( int ) ( stu[i].score * 1.2 ) ) << endl ;
    }
}