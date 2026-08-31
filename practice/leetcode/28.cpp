// KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        const int n = haystack.length();
        const int m = needle.length();
        vector<int> next = buildNext( needle ) ;
        int i = 0 ;
        int j = 0 ;
        while ( i < n )
        {
            if ( haystack[i] == needle[j] ) 
            {
                i ++ ;
                j ++ ;
            }
            else if ( j > 0 ) j = next[j - 1] ;
            else i ++ ;
            if ( j == m ) return i - j ; 
        }
        return -1 ;
    }
private:
    vector<int> buildNext( string pattern )
    {
        vector<int> next ;
        int prefixLen = 0 ;
        next.pushback( 0 ) ;
        for ( int i = 1 ; i < pattern.length() ; i ++ )
        {
            if ( pattern[next.size()] == pattern[i] )
            {
                prefixLen ++ ;
                next.pushback( prefixLen ) ;
            }
            else
            {
                if ( !prefixLen )
                {
                    next.pushback( 0 ) ;
                }
                else
                {
                    prefixLen = next[]
                }
            }
        }
    }
};

/* force search
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length() ;
        int m = needle.length() ;
        for ( int i = 0 ; i < n ; i ++ )
        {
            bool flag = true ;
            for ( int j = 0 ; j < m ; j ++ )
            {
                if ( haystack[i + j] != needle[j] )
                {
                    flag = false ;
                    break ;
                }
            }
            if ( flag )
            {
                return i ;
            }
        }
        return -1 ;
    }
};
*/