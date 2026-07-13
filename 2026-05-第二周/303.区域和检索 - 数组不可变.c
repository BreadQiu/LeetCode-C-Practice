/**
*题目：区域和检索 - 数组不可变
*日期：2026.5.9
*/
typedef struct {
    int*nums;
    int numsSize;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray*obj=(NumArray*)malloc(sizeof(NumArray));
    obj->nums=(int*)malloc((numsSize)*sizeof(int));
    for(int i=0;i<numsSize;i++){
        obj->nums[i]=nums[i];
    }
    obj->numsSize=numsSize;
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int ret=0;
    for(int i=left;i<=right;i++){
        ret+=obj->nums[i];
    }
    return ret;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
