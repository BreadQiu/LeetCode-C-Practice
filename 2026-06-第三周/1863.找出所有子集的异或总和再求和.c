/**
*题目：找出所有子集的异或总和再求和
*日期：2026.6.15
*/
int subsetXORSum(int* nums, int numsSize) {
    int n=1<<numsSize;
    int ret=0;
    for(int i=0;i<n;i++){
        int xor=0;
        for(int j=0;j<numsSize;j++){
            if(i&1<<j) xor=xor^nums[j];
        }
        ret+=xor;
    }
    return ret;
}
