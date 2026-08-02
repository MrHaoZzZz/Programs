class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() ;
        int n = nums2.size() ;

        if ( m > n ) return findMedianSortedArrays( nums2 , nums1 ) ;

        int totalLeftCount = ( m + n + 1 ) / 2 ;
    }
};