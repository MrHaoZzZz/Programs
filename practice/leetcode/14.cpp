class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ( strs.empty() ) return "" ;
        string prefix = "" ;
        bool flag = false ;
        sort( strs.begin() , strs.end() , cmp ) ;
        for ( int i = 0 ; i < ( int )strs[0].size() ; i ++ )
        {
            flag = true ;
            char curr = strs[0][i] ;
            for ( int j = 1 ; j < ( int )strs.size() ; j ++ )
            {
                if ( curr != strs[j][i] )
                {
                    flag = false ;
                    break ;
                }
            }
            if ( flag ) prefix += strs[0][i] ;
            else break ;
        }
        return prefix ;
    }
    static bool cmp( const string& cmp1 , const string& cmp2 )
    {
        return cmp1.length() < cmp2.length() ;
    }
};