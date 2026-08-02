#include <iostream>
#include <string>

using namespace std ;

class Student
{
    private :
        string name ;
        int chi , math , eng ;
    public :
        void setData( string na , int c , int m , int e )
        {
            name = na ;
            chi = c ;
            math = m ;
            eng = e ;
        }
        int getTot()
        {
            return chi + math + eng ;
        }
        string output()
        {
            return name + " " + to_string( chi ) + " " + to_string( math ) + " " + to_string( eng ) ;
        }
} ;

int main()
{
    int n ;
    Student stu[1005] ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        string na ;
        int c , m , e ;
        cin >> na >> c >> m >> e ;
        stu[i].setData( na , c , m , e ) ;
    }
    Student maxstu = stu[0] ;
    for ( int i = 1 ; i < n ; i ++ )
    {
        if ( stu[i].getTot() > maxstu.getTot() )
        {
            maxstu = stu[i] ;
        }
    }
    cout << maxstu.output() << endl ;
    return 0 ;
}