/**
*题目：数对和
*日期：2026.4.24
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int** pairSums(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    if(numsSize<2) return NULL;
    int left,right,mid;
    *returnSize=0;
    int**ret=(int**)malloc(numsSize/2*sizeof(int*));
    qsort(nums,numsSize,sizeof(int),cmp);

    for(left=0,right=numsSize-1;left<right;){
        for(;left<right&&nums[left]+nums[right]<target;left++);
        if(left>=right) break;
        if(nums[left]+nums[right]==target){
            ret[*returnSize]=(int*)malloc(2*sizeof(int));
            ret[*returnSize][0]=nums[left];
            ret[*returnSize][1]=nums[right];
            (*returnSize)++;
            left++;
            right--;
        }
        if(left>=right) break;

        for(;left<right&&nums[left]+nums[right]>target;right--);
        if(left>=right) break;
        if(nums[left]+nums[right]==target){
            ret[*returnSize]=(int*)malloc(2*sizeof(int));
            ret[*returnSize][0]=nums[left];
            ret[*returnSize][1]=nums[right];
            (*returnSize)++;
            left++;
            right--;
        }
        if(left>=right) break;
    }

    *returnColumnSizes=(int*)malloc((*returnSize+1)*sizeof(int));
    for(right=0;right<*returnSize;right++){
        (*returnColumnSizes)[right]=2;
    }

    return ret;
}
