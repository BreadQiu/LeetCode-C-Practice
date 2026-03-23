/**
*题目：找出最小平衡下标
*日期：2026.3.22
*/
int smallestBalancedIndex(int* nums, int numsSize) {
    int i,j;
    long double plus,mult;
    if(numsSize==1) return -1;
    if(numsSize==2)
    {
        if(nums[0]==1) return 1;
        return -1;
    }
    for(i=1,j=numsSize-2,plus=nums[i-1],mult=nums[j+1];i<=j;)
    {
        if(plus>mult) mult*=nums[j--];
        else if(plus<mult) plus+=nums[i++];
        else
        {
            if(i<j) mult*=nums[j--];
            else return i;
        }
    }
    return -1;
}
