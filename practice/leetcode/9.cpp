class Solution {
public:
    bool isPalindrome(int x) {
        if ( !x ) return true ;
        if ( x < 0 || !( x % 10 ) ) return false ;
        int reverseHalf = 0 ;
        while ( x > reverseHalf )
        {
            reverseHalf = reverseHalf * 10 + x % 10 ;
            x /= 10 ;
        }
        return x == reverseHalf || x == reverseHalf / 10 ;
    }
};
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 ) return false ;
        if ( !x ) return true ;
        vector<int> num = {} ;
        while ( x > 0 )
        {
            num.push_back( x % 10 ) ;
            x /= 10 ;
        }
        for ( int i = 0 , j = num.size() - 1 ; i < num.size() ; i ++ , j -- )
        {
            if ( num[i] != num[j] ) return false ;
        }
        return true ;
    }
};
*/