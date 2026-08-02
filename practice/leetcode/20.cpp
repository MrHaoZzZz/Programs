class Solution {
public:
    bool isValid(string s) {
        if ( s.length() % 2 ) return false ;
        stack<char> pending ;
        for ( char c : s )
        {
            switch ( c )
            {
                case '(' : pending.push( ')' ) ; break ;
                case '[' : pending.push( ']' ) ; break ;
                case '{' : pending.push( '}' ) ; break ;
                default : if ( pending.empty() || pending.top() != c ) return false ; else pending.pop() ;
            }
        }
        return pending.empty() ;
    }
};

/*
class Solution {
public:
    bool isValid(string s) {
        if ( s == "" ) return true ;
        if ( ( int )s.size() % 2 ) return false ;
        stack<char> pending ;
        for ( int i = 0 ; i < ( int )s.size() ; i ++ )
        {
            if ( s[i] == '(' || s[i] == '[' || s[i] == '{' ) pending.push( s[i] ) ;
            else if ( !pending.empty() )
            {
                switch ( s[i] )
                {
                    case ')' : if ( pending.top() == '(' ) pending.pop() ; else return false ; break ;
                    case ']' : if ( pending.top() == '[' ) pending.pop() ; else return false ; break ;
                    case '}' : if ( pending.top() == '{' ) pending.pop() ; else return false ; break ;
                    default : return false ;
                }
            }
            else return false ;
        }
        if ( pending.empty() ) return true ;
        else return false ;
    }
};
*/