class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowPointer = 0 ;
        for ( int fastPointer = 0 ; fastPointer < ( int )nums.size() ; fastPointer ++ )
        {
            if ( nums[fastPointer] != val )
            {
                nums[slowPointer] = nums[fastPointer] ;
                slowPointer ++ ;
            }
        }
        return slowPointer ;
    }
};