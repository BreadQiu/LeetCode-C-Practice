/**
*题目：构造奇偶一致的数组II
*日期：2026.3.22
*/
bool uniformArray(int* nums1, int nums1Size) {
    int i,oddnums=0;
    long long nums1min=999999999,nums2min=1000000000;
    if(nums1Size==1) return 1;
    for(i=0;i<nums1Size;i++)
    {
        if(nums1[i]%2==1)
        {
            oddnums++;
            if(nums1[i]<nums1min) nums1min=nums1[i];
        }
        else if(nums1[i]<nums2min) nums2min=nums1[i];
    }
    if(nums1min<nums2min||oddnums==0) return 1;
    return 0;
}
