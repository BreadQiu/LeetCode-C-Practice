/**
*题目：最后一块石头的重量
*日期：2026.5.20
*/
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int lastStoneWeight(int* stones, int stonesSize) {
    if(stonesSize==1) return stones[0];
    qsort(stones,stonesSize,sizeof(int),cmp);
    for(;stones[stonesSize-2];){
        stones[stonesSize-1]-=stones[stonesSize-2];
        stones[stonesSize-2]=0;
        qsort(stones,stonesSize,sizeof(int),cmp);
    }
    return stones[stonesSize-1];
}
