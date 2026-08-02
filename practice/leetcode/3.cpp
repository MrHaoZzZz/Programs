class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastPos( 256 , -1 ) ;
        int left = 0 ;
        int maxLen = 0 ;
        for ( int right = 0 ; right < s.size() ; right ++ )
        {
            if ( lastPos[s[right]] >= left ) left = lastPos[s[right]] + 1 ;
            lastPos[s[right]] = right ;
            maxLen = max( maxLen , right - left + 1 ) ;
        }
        return maxLen ;
    }
};

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool flag[300] = {false} ;
        int ans = 0 ;
        for ( int i = 0 ; i < s.size() ; i ++ )
        {
            memset( flag , 0 , sizeof( flag ) ) ;
            int res = 0 ;
            for ( int j = i ; j < s.size() ; j ++ )
            {
                if ( !flag[s[j]] )
                {
                    flag[s[j]] = true ;
                    res ++ ;
                }
                else break ;
            }
            ans = res > ans ? res : ans ;
        }
        return ans ;
    }
};
*/