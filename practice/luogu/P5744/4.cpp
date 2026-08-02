#include <iostream>

using namespace std ;

class student
{
    public :
        string name ;
        int age , score ;
} ;

int main()
{
    int n ;
    cin >> n ;
    student stu[10] ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> stu[i].name >> stu[i].age >> stu[i].score ;
    }
    for ( int i = 0 ; i < n ; i ++ )
    {
        cout << stu[i].name << " " << stu[i].age + 1 << " " << ( ( stu[i].score * 1.2 > 600 ) ? 600 : ( int ) ( stu[i].score * 1.2 ) ) << endl ;
    }
    return 0 ;
}