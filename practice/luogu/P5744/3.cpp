#include <iostream>

using namespace std ;

class student
{
    private :
        string name ;
        int age , score ;
    public :
        void set_data( string na , int ag , int sc )
        {
            name = na ;
            age = ag ;
            score = sc ;
        }
        string output()
        {
            return name + " " + to_string( age + 1 ) + " " + ( score * 1.2 > 600 ? "600" : to_string( ( int ) ( score * 1.2 ) ) ) ;
        }
} ;

int main()
{
    int n ;
    cin >> n ;
    student s[10] ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        string na ;
        int ag , sc ;
        cin >> na >> ag >> sc ;
        s[i].set_data( na , ag , sc ) ;
    }
    for ( int i = 0 ; i < n ; i ++ )
    {
        cout << s[i].output() << endl ;
    }
    return 0 ;
}