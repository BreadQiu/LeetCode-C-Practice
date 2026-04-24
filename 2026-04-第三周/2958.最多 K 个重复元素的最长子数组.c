/**
*题目：最多 K 个重复元素的最长子数组
*日期：2026.4.16
*/
int maxSubarrayLength(int* nums, int numsSize, int k) {
    int i,left,right,maxLength=0,max=INT_MIN,min=INT_MAX;
    int* hush=(int*)malloc(1000000001*sizeof(int));
    memset(hush,0,1000000001*sizeof(int));
    for(left=0,right=0;right<numsSize;++right){
        ++hush[nums[right]];
        if(hush[nums[right]]>k){
            maxLength=fmax(right-left,maxLength);
            --hush[nums[left]];
            ++left;
            for(;hush[nums[left-1]]<k;++left){
                --hush[nums[left]];
            }
        }
    }
    free(hush);
    return fmax(right-left,maxLength);
}
