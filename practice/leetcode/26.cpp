class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ( nums.empty() ) return 0 ;
        int slowPointer = 0 ;
        for ( int fastPointer = 1 ; fastPointer < ( int )nums.size() ; fastPointer ++ )
        {
            if ( nums[fastPointer] != nums[fastPointer-1] )
            {
                slowPointer ++ ;
                nums[slowPointer] = nums[fastPointer] ;
            }
        }
        return slowPointer + 1 ;
    }
};
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = ( int )nums.size() ;
        for ( int i = 1 ; i < ( int )nums.size() ; i ++ )
        {
            if ( nums[i] == nums[i-1] )
            {
                nums.erase( nums.begin() + i ) ;
                length -- ;
                i -- ;
            }
        }
        return length ;
    }
};
*/