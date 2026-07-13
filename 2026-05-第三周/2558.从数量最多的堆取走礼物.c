/**
*题目：从数量最多的堆取走礼物
*日期：2026.5.24
*/
int cmp(const void*a,const void*b){
    return *(int*)b-*(int*)a;
}

long long pickGifts(int* gifts, int giftsSize, int k) {
    while(k--){
        qsort(gifts,giftsSize,sizeof(int),cmp);
        gifts[0]=sqrt(gifts[0]);
    }
    long long ret=0;
    for(int i=0;i<giftsSize;i++){
        ret+=gifts[i];
    }
    return ret;
}
