/**
*题目：子集
*日期：2026.6.9
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int**ret=(int**)malloc((1<<numsSize)*sizeof(int*));
    *returnColumnSizes=(int*)malloc((1<<numsSize)*sizeof(int));
    for(*returnSize=0;(*returnSize)<1<<numsSize;(*returnSize)++){
        returnColumnSizes[0][*returnSize]=0;
        ret[*returnSize]=(int*)malloc(10*sizeof(int));
        for(int i=0;i<numsSize;i++){
            if((*returnSize)&(int)pow(2,i)){
                ret[*returnSize][returnColumnSizes[0][*returnSize]++]=nums[i];
            }
        }
    }
    return ret;
}
