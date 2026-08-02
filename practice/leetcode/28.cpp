class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next = buildNext( needle ) ;
        int pointer = 0 ;
        for ( int i = 0 ; i < haystack.length() ; i ++ )
        {
            while ( pointer < needle.length() )
        }
        return -1 ;
    }

private :
    vector<int> buildPrefix( const string& pattern )
    {
        const int n = pattern.lenth() ;
        vector<int> prefix( n , 0 ) ;
        int j = 0 ;
        for ( int i = 0 ; i < n ; i ++ )
        {
            
        }
    }
};