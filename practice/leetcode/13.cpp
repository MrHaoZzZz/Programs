class Solution {
public:
    int romanToInt(string s) {
        int ans = 0 ;
        static const int value[256] = {
            ['I'] = 1 ,
            ['V'] = 5 ,
            ['X'] = 10 ,
            ['L'] = 50 ,
            ['C'] = 100 ,
            ['D'] = 500 ,
            ['M'] = 1000
        } ;
        int last = 0 ;
        for ( int i = ( int )s.size() - 1 ; i >= 0 ; i -- )
        {
            int curr = value[s[i]] ;
            if ( curr < last ) ans -= curr ;
            else ans += curr ;
            last = curr ;
        }
        return ans ;
    }
};