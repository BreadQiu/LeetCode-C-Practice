/**
*题目：删掉一个元素以后全为 1 的最长子数组
*日期：2026.4.1
*/
int longestSubarray(int* nums, int numsSize) {
    int i,sum1=0,sum2=0,max=0;
    int temp=0,haszero=0;
    for(i=0;i<numsSize;++i){
        if(nums[i]==0){
            haszero=1;
            sum1=sum2=0;
            continue;
        }
        for(;i<numsSize;++i){
            if(nums[i]==1){
                ++sum1;
                ++sum2;
            }
            else{
                haszero=1;
                if(temp==0){
                    temp=1;
                    max=fmax(sum2,max);
                    sum2=0;
                    }
                else{
                    temp=0;
                    max=fmax(sum1,max);
                    sum1=0;
                }
                break;
            }
        }
    }
    max=fmax(fmax(sum1,sum2),max);
    if(haszero==0) return max-1;
    return max;
}
